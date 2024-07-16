#include <gfx/hal/instance.h>

#include <glfw/glfw3.h>


static const gfx_VkInitializationExtension GFX_INSTANCE_BASE_EXTENSIONS[] = {
	(gfx_VkInitializationExtension){ VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME, false }
};
static const gfx_VkInitializationExtension GFX_INSTANCE_BASE_DEBUG_EXTENSIONS[] = {
	(gfx_VkInitializationExtension){ VK_EXT_DEBUG_UTILS_EXTENSION_NAME, true }
};
static const gfx_VkInitializationLayer GFX_INSTANCE_BASE_LAYERS[] = {
	// NOTE(Vicix): Empty vectors are not strictly supported by C, so a dummy element is inserted
	(gfx_VkInitializationLayer){ nullptr, false }
};
static const gfx_VkInitializationLayer GFX_INSTANCE_BASE_DEBUG_LAYERS[] = {
	(gfx_VkInitializationLayer){ "VK_LAYER_KHRONOS_validation", false }
};

singleton struct gfx_Instance singleton_of(gfx_Instance);

static Slice(gfx_VkInitializationExtension) gfx_instance_get_initialization_extensions(bool debug, Allocator allocator) {
	usize default_extensions_count = countof(GFX_INSTANCE_BASE_EXTENSIONS);
	if (debug) {
		default_extensions_count += countof(GFX_INSTANCE_BASE_DEBUG_EXTENSIONS);
	}

	u32 glfw_extension_count;
	const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	Slice(gfx_VkInitializationExtension) extensions = slice_make(gfx_VkInitializationExtension)(
        glfw_extension_count + default_extensions_count, 
        allocator
	);

	memcpy(
		&extensions.data[0], 
		&GFX_INSTANCE_BASE_EXTENSIONS[0], 
		countof(GFX_INSTANCE_BASE_EXTENSIONS) * sizeof(gfx_VkInitializationExtension)
	);
	if (debug) {
		memcpy(
			&extensions.data[countof(GFX_INSTANCE_BASE_EXTENSIONS)], 
			&GFX_INSTANCE_BASE_DEBUG_EXTENSIONS[0], 
			countof(GFX_INSTANCE_BASE_DEBUG_EXTENSIONS) * sizeof(gfx_VkInitializationExtension)
		);
	}
	
	for (usize i = 0; i < glfw_extension_count; i++) {
		extensions.data[i + default_extensions_count] = (gfx_VkInitializationExtension){
			.critical = true,
			.name = (rawstring)glfw_extensions[i]
		};
	}

	return extensions;
}

static Slice(gfx_VkInitializationLayer) gfx_instance_get_initialization_layers(bool debug, Allocator allocator) {
	usize default_layers_count = countof(GFX_INSTANCE_BASE_LAYERS);
	if (debug) {
		default_layers_count += countof(GFX_INSTANCE_BASE_DEBUG_LAYERS);
	}

	Slice(gfx_VkInitializationLayer) layers = slice_make(gfx_VkInitializationLayer)(
        default_layers_count, 
        allocator
	);

	memcpy(
		&layers.data[0],
		&GFX_INSTANCE_BASE_LAYERS[0],
		countof(GFX_INSTANCE_BASE_LAYERS) * sizeof(gfx_VkInitializationLayer)
	);
	if (debug) {
		memcpy(
			&layers.data[countof(GFX_INSTANCE_BASE_LAYERS)],
			&GFX_INSTANCE_BASE_DEBUG_LAYERS[0],
			countof(GFX_INSTANCE_BASE_DEBUG_LAYERS) * sizeof(gfx_VkInitializationLayer)
		);
	}

	return layers;
}

gfx_Result gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor, Context* context) {
	gfx_Result result = GFX_SUCCESS;

	log_info(context, "Initializing the gfx-hal instance...");
	log_trace(context, "Using descriptor:");
	log_trace(context, "\t- application_name: %s", descriptor->application_name);
	log_trace(context, "\t- application_version: %x", descriptor->application_version);
	log_trace(context, "\t- enable_debug: %d", descriptor->enable_debug);

	Slice(gfx_VkInitializationExtension) extensions = gfx_instance_get_initialization_extensions(descriptor->enable_debug, context->allocator);
	Slice(gfx_VkInitializationLayer) layers = gfx_instance_get_initialization_layers(descriptor->enable_debug, context->allocator);

	descriptor_of(gfx_VkInstance) instance_descriptor = (descriptor_of(gfx_VkInstance)){
		.application_name = (const rawstring)descriptor->application_name,
		.application_version = descriptor->application_version,
		.requested_extensions = extensions,
		.requested_layers = layers,
		.engine_name = "Vulkan GfxHal",
		.engine_version = gfx_version_make(0, 0, 1),
		.requested_version = gfx_version_make(1, 2, 0),
	};

	log_debug(context, "Creating a gfx_VkInstance...");
	singleton_of(gfx_Instance).context = context;
	singleton_of(gfx_Instance).debug_enabled = descriptor->enable_debug;
	result = gfx_vkinstance_make(
         &singleton_of(gfx_Instance).instance, 
         &instance_descriptor, 
         context
     );
	if (result != GFX_SUCCESS) {
		log_error(context, "gfx-hal instance initialization failed: Could not create a gfx_VkInstance");
	}

	slice_delete(gfx_VkInitializationExtension)(extensions, context->allocator);
	slice_delete(gfx_VkInitializationLayer)(layers, context->allocator);

	log_debug(context, "Successfully initialized the gfx-hal instance");
	return result;
}

void gfx_instance_deinit() {
	gfx_vkinstance_delete(&singleton_of(gfx_Instance).instance);
}
