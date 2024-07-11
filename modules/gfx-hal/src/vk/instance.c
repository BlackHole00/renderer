#include <gfx/hal/vk/instance.h>

#include "instance_prober.h"

static bool gfx_vkinstance_check_extension_support(
    const gfx_VkInstanceProber* prober, 
    Slice(gfx_VkInitializationExtension) extensions,
    Slice(rawstring)* valid_extensions,
    Allocator allocator
) {
	Vector(rawstring) tmp_valid_extensions = vector_make(rawstring)(allocator);
	bool has_invalid_extensions = false;

	for (usize i = 0; i < extensions.length; i++) {
		gfx_VkInitializationExtension extension = extensions.data[i];
		bool valid = !gfx_vkinstanceprober_is_extension_supported(prober, extension.name);

		if (!valid && extension.critical) {
			has_invalid_extensions = true;
		} else if (valid) {
			// TODO(Vicix): Fix memory management
			vector_append(rawstring)(&tmp_valid_extensions, extension.name);
		}
	}

	*valid_extensions = vector_as_slice(rawstring)(&tmp_valid_extensions);
	return !has_invalid_extensions;
}

static bool gfx_vkinstance_check_layer_support(
    const gfx_VkInstanceProber* prober, 
    Slice(gfx_VkInitializationLayer) layers,
    Slice(rawstring)* valid_layers,
    Allocator allocator
) {
	Vector(rawstring) tmp_valid_layers = vector_make(rawstring)(allocator);
	bool has_invalid_layers = false;

	for (usize i = 0; i < layers.length; i++) {
		gfx_VkInitializationLayer layer = layers.data[i];
		bool valid = !gfx_vkinstanceprober_is_layer_supported(prober, layer.name);

		if (!valid && layer.critical) {
			has_invalid_layers = true;
		} else if (valid) {
			// TODO(Vicix): Fix memory management
			vector_append(rawstring)(&tmp_valid_layers, layer.name);
		}
	}

	*valid_layers = vector_as_slice(rawstring)(&tmp_valid_layers);
	return !has_invalid_layers;
}

gfx_Result gfx_vkinstance_make(gfx_VkInstance* instance, const descriptor_of(gfx_VkInstance)* descriptor, Allocator allocator) {
	gfx_Result result;

	gfx_VkInstanceProber prober;
	result = gfx_vkinstanceprober_make(&prober, allocator);
	if (result != GFX_SUCCESS) {
		return result;
	}

	if (!gfx_vkinstanceprober_is_version_supported(&prober, descriptor->requested_version)) {
		return GFX_UNSUPPORTED_VK_VERSION;
	}
	if (!gfx_vkinstance_check_extension_support(
	    &prober, 
	    descriptor->requested_extensions, 
	    &instance->enabled_extensions, 
	    allocator)
	) {
		result = GFX_UNSUPPORTED_VK_INSTANCE_EXTENSION;
		goto error;
	}
	if (!gfx_vkinstance_check_layer_support(
	    &prober, 
	    descriptor->requested_layers, 
	    &instance->enabled_layers, 
	    allocator)
	) {
		result = GFX_UNSUPPORTED_VK_INSTANCE_LAYER;
		goto error;
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
		.enabledExtensionCount = instance->enabled_extensions.length,
		.ppEnabledExtensionNames = (const char**)instance->enabled_extensions.data,
		.enabledLayerCount = instance->enabled_layers.length,
		.ppEnabledLayerNames = (const char**)(instance->enabled_layers.data)
	};

	result = (gfx_Result)(vkCreateInstance(
         &instance_info, 
         nullptr, 
         &instance->instance
    ));
	if (result != GFX_SUCCESS) {
		return result;
	}

	instance->allocator = allocator;
	instance->supported_version = descriptor->requested_version;

	return GFX_SUCCESS;

error:
	slice_delete(rawstring)(instance->enabled_extensions, instance->allocator);
	slice_delete(rawstring)(instance->enabled_layers, instance->allocator);

	return result;
}

void gfx_vkinstance_delete(const gfx_VkInstance* instance) {
	slice_delete(rawstring)(instance->enabled_extensions, instance->allocator);
	slice_delete(rawstring)(instance->enabled_layers, instance->allocator);

	vkDestroyInstance(instance->instance, nullptr);
}
