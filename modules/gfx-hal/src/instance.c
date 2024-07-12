#include <gfx/hal/instance.h>

#include <glfw/glfw3.h>

static const gfx_VkInitializationExtension EMPTY_EXTENSION = (gfx_VkInitializationExtension){
	.name = nullptr,
	.critical = false
};
static const gfx_VkInitializationLayer EMPTY_LAYER = (gfx_VkInitializationLayer){
	.name = nullptr,
	.critical = false
};

static const gfx_VkInitializationExtension GFX_INSTANCE_BASE_EXTENSIONS[] = {
	(gfx_VkInitializationExtension){ VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME, false }
};
static const gfx_VkInitializationExtension GFX_INSTANCE_BASE_DEBUG_EXTENSIONS[] = {
	// EMPTY_EXTENSION
};
static const gfx_VkInitializationLayer GFX_INSTANCE_BASE_LAYERS[] = {
	// EMPTY_LAYER
};
static const gfx_VkInitializationLayer GFX_INSTANCE_BASE_DEBUG_LAYERS[] = {
	(gfx_VkInitializationLayer){ "MoltenVK", false },
	(gfx_VkInitializationLayer){ "VK_LAYER_KHRONOS_validation", false }
};

singleton struct gfx_Instance singleton_of(gfx_Instance);

static Slice(gfx_VkInitializationExtension) gfx_instance_get_initialization_extensions(bool debug, Allocator allocator) {
	usize default_extensions_count;
	if (debug) {
		default_extensions_count = countof(GFX_INSTANCE_BASE_DEBUG_EXTENSIONS);
	} else {
		default_extensions_count = countof(GFX_INSTANCE_BASE_EXTENSIONS);
	}

	u32 glfw_extension_count;
	const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	Slice(gfx_VkInitializationExtension) extensions = slice_make(gfx_VkInitializationExtension)(
        glfw_extension_count + default_extensions_count, 
        allocator
	);

	if (debug) {
		memcpy(&extensions.data[0], &GFX_INSTANCE_BASE_DEBUG_EXTENSIONS[0], default_extensions_count);
	} else {
		memcpy(&extensions.data[0], &GFX_INSTANCE_BASE_EXTENSIONS[0], default_extensions_count);
	}
	for (usize i = 0; i < glfw_extension_count; i++) {
		extensions.data[i + default_extensions_count] = (gfx_VkInitializationExtension){
			.critical = true,
			.name = (rawstring)glfw_extensions[i]
		};
	}

	return extensions;
}

static Slice(gfx_VkInitializationLayer) gfx_instance_get_initialization_layers(bool debug) {
	if (debug) {
		return slice_from(gfx_VkInitializationLayer)(
             (gfx_VkInitializationLayer*)&GFX_INSTANCE_BASE_DEBUG_LAYERS[0], 
             countof(GFX_INSTANCE_BASE_DEBUG_LAYERS)
         );
	} else {
		return slice_from(gfx_VkInitializationLayer)(
             (gfx_VkInitializationLayer*)&GFX_INSTANCE_BASE_LAYERS[0], 
             countof(GFX_INSTANCE_BASE_LAYERS)
         );
	}
}

gfx_Result gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor, Context* context) {
	gfx_Result result = GFX_SUCCESS;

	Slice(gfx_VkInitializationExtension) extensions = gfx_instance_get_initialization_extensions(descriptor->enable_debug, context->allocator);
	Slice(gfx_VkInitializationLayer) layers = gfx_instance_get_initialization_layers(descriptor->enable_debug);

	descriptor_of(gfx_VkInstance) instance_descriptor = (descriptor_of(gfx_VkInstance)){
		.application_name = (const rawstring)descriptor->application_name,
		.application_version = descriptor->application_version,
		.requested_extensions = extensions,
		.requested_layers = layers,
		.engine_name = "Vulkan GfxHal",
		.engine_version = gfx_version_make(0, 0, 1),
		.requested_version = gfx_version_make(1, 2, 0),
	};

	singleton_of(gfx_Instance).context = context;
	singleton_of(gfx_Instance).debug_enabled = descriptor->enable_debug;
	result = gfx_vkinstance_make(
         &singleton_of(gfx_Instance).instance, 
         &instance_descriptor, 
         context
     );

	slice_delete(gfx_VkInitializationExtension)(extensions, context->allocator);
	return result;
}

void gfx_instance_deinit() {
	gfx_vkinstance_delete(&singleton_of(gfx_Instance).instance);
}
