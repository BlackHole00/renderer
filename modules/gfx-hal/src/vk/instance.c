#include <gfx/hal/vk/instance.h>

#include <gfx/hal/vk/debug_messenger.h>
#include "instance_prober.h"

static bool gfx_vkinstance_check_extension_support(
    const gfx_VkInstanceProber* prober, 
    Slice(gfx_VkInitializationExtension) extensions,
    Slice(rawstring)* valid_extensions,
    Context* context
) {
	Vector(rawstring) tmp_valid_extensions = vector_make(rawstring)(context->global_allocator);
	bool has_invalid_extensions = false;

	log_trace(context, "Checking for Vulkan instance extensions compatibility...");

	for (usize i = 0; i < extensions.length; i++) {
		gfx_VkInitializationExtension extension = extensions.data[i];
		if (extension.name == nullptr) {
			continue;
		}

		bool valid = gfx_vkinstanceprober_is_extension_supported(prober, extension.name);

		if (!valid && !extension.critical) {
			log_warn(context,
			    "Non critical required instance extension %s is not present",
			    extension.name
			);
		} else if (!valid && extension.critical) {
			log_error(context,
			    "Critical required instance extension %s is not present",
			    extension.name
			);
			has_invalid_extensions = true;
		} else if (valid) {
			rawstring extension_name;
			clone(rawstring)(&extension.name, &extension_name, context->global_allocator);

			vector_append(rawstring)(&tmp_valid_extensions, extension_name);
		}
	}

	*valid_extensions = vector_as_slice(rawstring)(&tmp_valid_extensions);
	return !has_invalid_extensions;
}

static bool gfx_vkinstance_check_layer_support(
    const gfx_VkInstanceProber* prober, 
    Slice(gfx_VkInitializationLayer) layers,
    Slice(rawstring)* valid_layers,
    Context* context
) {
	Vector(rawstring) tmp_valid_layers = vector_make(rawstring)(context->global_allocator);
	bool has_invalid_layers = false;

	log_trace(context, "Checking for Vulkan instance layers compatibility...");

	for (usize i = 0; i < layers.length; i++) {
		gfx_VkInitializationLayer layer = layers.data[i];
		if (layer.name == nullptr) {
			continue;
		}

		bool valid = gfx_vkinstanceprober_is_layer_supported(prober, layer.name);

		if (!valid && !layer.critical) {
			log_warn(context,
			    "Non critical required instance layer %s is not present",
			    layer.name
			);
		} else if (!valid && layer.critical) {
			log_error(context,
			    "Critical required instance layer %s is not present",
			    layer.name
			);
			has_invalid_layers = true;
		} else if (valid) {
			rawstring layer_name;
			clone(rawstring)(&layer.name, &layer_name, context->global_allocator);

			vector_append(rawstring)(&tmp_valid_layers, layer_name);
		}
	}

	*valid_layers = vector_as_slice(rawstring)(&tmp_valid_layers);
	return !has_invalid_layers;
}

gfx_Result gfx_vkinstance_make(gfx_VkInstance* instance, const descriptor_of(gfx_VkInstance)* descriptor, Context* context) {
	gfx_Result result;

	log_trace(context, "Creating a gfx_VkInstance for descriptor:");
	log_trace(context, "\t- application_name: %s", descriptor->application_name);
	log_trace(context, "\t- application_version: %x", descriptor->application_version);
	log_trace(context, "\t- engine_name: %s", descriptor->engine_name);
	log_trace(context, "\t- engine_version: %x", descriptor->engine_version);
	log_trace(context, "\t- requested_version: %x", descriptor->requested_version);
	log_trace(context, "\t- requested_extensions:");
	for (usize i = 0; i < descriptor->requested_extensions.length; i++){
		gfx_VkInitializationExtension* extension = &descriptor->requested_extensions.data[i];
		log_trace(context, "\t\t%c: %s", 
			(extension->critical ? '*' : '-'),
			extension->name
		);
	}
	log_trace(context, "\t-requested_layers:");
	for (usize i = 0; i < descriptor->requested_layers.length; i++){
		gfx_VkInitializationLayer* layer = &descriptor->requested_layers.data[i];
		log_trace(context, "\t\t%c: %s", 
			(layer->critical ? '*' : '-'),
			layer->name
		);
	}
	log_trace(context, "\t- creation_debug_messenger: %p", (void*)(descriptor->creation_debug_messenger));

	gfx_VkInstanceProber prober;
	result = gfx_vkinstanceprober_make(&prober, context->temp_allocator);
	if (result != GFX_SUCCESS) {
		return result;
	}

	gfx_vkinstanceprober_report(&prober, context->logger);

	log_debug(context, "Checking Vulkan instance compatibility against descriptor...");
	if (!gfx_vkinstanceprober_is_version_supported(&prober, descriptor->requested_version)) {
		log_error(context,
			"gfx_VkInstance creation failed: Unsupported vulkan version. Required version %x, found version %x",
			descriptor->requested_version,
			prober.supported_vulkan_version
		);
		return GFX_UNSUPPORTED_VK_VERSION;
	}
	if (!gfx_vkinstance_check_extension_support(
	    &prober, 
	    descriptor->requested_extensions, 
	    &instance->enabled_extensions, 
	    context)
	) {
		log_error(context, "gfx_VkInstance creation failed: Found unsupported Vulkan extension");
		return GFX_UNSUPPORTED_VK_INSTANCE_EXTENSION;
	}
	if (!gfx_vkinstance_check_layer_support(
	    &prober, 
	    descriptor->requested_layers, 
	    &instance->enabled_layers, 
	    context)
	) {
		log_error(context, "gfx_VkInstance creation failed: Found unsupported Vulkan layer");
		return GFX_UNSUPPORTED_VK_VERSION;
	}

	VkApplicationInfo application_info = (VkApplicationInfo){
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName = descriptor->application_name,
		.applicationVersion = descriptor->application_version,
		.pEngineName = descriptor->engine_name,
		.engineVersion = descriptor->engine_version,
		.apiVersion = descriptor->requested_version,
	};

	VkInstanceCreateInfo instance_info = (VkInstanceCreateInfo){
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR,
		.pApplicationInfo = &application_info,
		// .enabledExtensionCount = instance->enabled_extensions.length,
		// .ppEnabledExtensionNames = (const char**)instance->enabled_extensions.data,
		// .enabledlayercount = instance->enabled_layers.length,
		// .ppenabledlayernames = (const char**)(instance->enabled_layers.data)
	};

	// if (descriptor->creation_debug_messenger != nullptr) {
	// 	rawstring debug_extension = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
	// 	bool can_enable_debug_messenger = slice_contains_element(rawstring)(
	// 		instance->enabled_extensions, 
	// 		&debug_extension
	// 	);

	// 	if (can_enable_debug_messenger) {
	// 		VkDebugUtilsMessengerCreateInfoEXT messenger_info;
	// 		gfx_vkdebugmessenger_get_vulkan_createinfo(descriptor->creation_debug_messenger, &messenger_info);

	// 		instance_info.pNext = &messenger_info;
	// 	}
	// }

	log_debug(context, "Creating Vulkan instance...");
	log_trace(context, "Using VkInstanceCreateInfo:");
	log_trace(context, "\t- sType: %x", instance_info.sType);
	log_trace(context, "\t- pNext: %p", instance_info.pNext);
	log_trace(context, "\t- flags: %x", instance_info.flags);
	log_trace(context, "\t- pApplicationInfo: %p", (void*)(instance_info.pApplicationInfo));
	log_trace(context, "\t\t- sType: %x", instance_info.pApplicationInfo->sType);
	log_trace(context, "\t\t- pNext: %p", (void*)(instance_info.pApplicationInfo->pNext));
	log_trace(context, "\t\t- pApplicationName: %s", instance_info.pApplicationInfo->pApplicationName);
	log_trace(context, "\t\t- pApplicationVersion: %x", instance_info.pApplicationInfo->applicationVersion);
	log_trace(context, "\t\t- pEngineName: %s", instance_info.pApplicationInfo->pEngineName);
	log_trace(context, "\t\t- pEngineVersion: %x", instance_info.pApplicationInfo->engineVersion);
	log_trace(context, "\t\t- apiVersion: %x", instance_info.pApplicationInfo->apiVersion);
	log_trace(context, "\t- enabledExtensionCount: %d", instance_info.enabledExtensionCount);
	log_trace(context, "\t- ppEnabledExtensionNames: %p", (void*)(instance_info.ppEnabledExtensionNames));
	for (usize i = 0; i < instance_info.enabledExtensionCount; i++) {
		log_trace(context, "\t\t- %s", instance_info.ppEnabledExtensionNames[i]);
	}
	log_trace(context, "\t- enabledLayerCount: %d", instance_info.enabledLayerCount);
	log_trace(context, "\t- ppEnabledLayerNames: %p", (void*)(instance_info.ppEnabledLayerNames));
	for (usize i = 0; i < instance_info.enabledLayerCount; i++) {
		log_trace(context, "\t\t- %s", instance_info.ppEnabledLayerNames[i]);
	}

	result = (gfx_Result)(vkCreateInstance(
         &instance_info, 
         nullptr, 
         &instance->instance
    ));
	if (result != GFX_SUCCESS) {
		log_error(context, "gfx_VkInstance creation failed: Could not create a Vulkan instance (error code: %d)", result);
		return result;
	}

	instance->context = context;
	instance->supported_version = descriptor->requested_version;

	log_debug(context, "Successfully created a gfx_VkInstance");
	return GFX_SUCCESS;
}

void gfx_vkinstance_delete(const gfx_VkInstance* instance) {
	Context* context = instance->context;

	log_trace(context, "Destroying Vulkan instance...");
	vkDestroyInstance(instance->instance, nullptr);
}
