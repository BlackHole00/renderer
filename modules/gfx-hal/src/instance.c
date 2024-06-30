#include <gfx/hal/instance.h>

#include <glfw/glfw3.h>

static const rawstring GFX_INSTANCE_BASE_EXTENSIONS[] = (const rawstring[]){
	// VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME,
};
static const rawstring GFX_INSTANCE_BASE_DEBUG_EXTENSIONS[] = (const rawstring[]){
	// EMPTY
};

singleton struct gfx_Instance singleton_of(gfx_Instance);

static Slice(rawstring) gfx_instance_get_required_extensions(bool request_debug_extensions, Allocator allocator);
static Slice(rawstring) gfx_instance_get_required_layers(bool request_debug_layers, Allocator allocator);
static VkResult gfx_instance_setup_vk_instance(const descriptor_of(gfx_Instance)* descriptor, Allocator allocator);

gfx_Result gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor, Allocator allocator) {
	singleton_of(gfx_Instance).allocator = allocator;

	VkResult instance_creation_result = gfx_instance_setup_vk_instance(descriptor, allocator);
	if (instance_creation_result != VK_SUCCESS) {
		return (gfx_Result)(instance_creation_result);
	}

	return GFX_SUCCESS;
}

void gfx_instance_deinit() {
	vkDestroyInstance(singleton_of(gfx_Instance).instance, nullptr);
}

Slice(rawstring) gfx_instance_get_required_extensions(bool request_debug_extensions, Allocator allocator) {
	assert(glfwVulkanSupported());

	u32 glfw_required_extensions_count;
	const char** glfw_required_extensions = glfwGetRequiredInstanceExtensions(&glfw_required_extensions_count);
	assert(glfw_required_extensions != nullptr);

	auto extensions = slice_make(rawstring)(
	    glfw_required_extensions_count + count_of(GFX_INSTANCE_BASE_EXTENSIONS),
	    allocator
	);

	usize idx = 0;
	for (usize i = 0; i < count_of(GFX_INSTANCE_BASE_EXTENSIONS); i++, idx++) {
		extensions.data[idx] = GFX_INSTANCE_BASE_EXTENSIONS[i];
	}
	if (request_debug_extensions) for (usize i = 0; i < count_of(GFX_INSTANCE_BASE_DEBUG_EXTENSIONS); i++, idx++) {
		extensions.data[idx] = GFX_INSTANCE_BASE_DEBUG_EXTENSIONS[i];
	}
	for (usize i = 0; i < glfw_required_extensions_count; i++, idx++) {
		extensions.data[idx] = (rawstring)(glfw_required_extensions[i]);
	}

	for (usize i = 0; i < extensions.length; i++) {
		printf("Extension %lu: %s\n", i, extensions.data[i]);
	}

	return extensions;
}

VkResult gfx_instance_setup_vk_instance(const descriptor_of(gfx_Instance)* descriptor, Allocator allocator) {
	VkApplicationInfo application_info = (VkApplicationInfo){
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName = descriptor->application_name,
		.applicationVersion = descriptor->application_version,
		.pEngineName = "gfx-hal",
		.engineVersion = VK_MAKE_VERSION(0, 0, 1),
		.apiVersion = VK_MAKE_VERSION(1, 2, 0),
	};

	Slice(rawstring) extensions = gfx_instance_get_required_extensions(descriptor->enable_debug, allocator);
	
	VkInstanceCreateInfo instance_info = (VkInstanceCreateInfo){
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR,
		.pApplicationInfo = &application_info,
		.enabledExtensionCount = extensions.length,
		.ppEnabledExtensionNames = (const char**)(extensions.data)
	};

	VkInstance instance;
	VkResult instance_creation_result = vkCreateInstance(
         &instance_info, 
         nullptr, 
         &instance
    );
	if (instance_creation_result != GFX_SUCCESS) {
		goto vk_instance_creation_failed;
	}

	singleton_of(gfx_Instance).instance = instance;
	singleton_of(gfx_Instance).instance_extensions = extensions;
	singleton_of(gfx_Instance).debug_enabled = descriptor->enable_debug;

	return instance_creation_result;


vk_instance_creation_failed:
	slice_delete(rawstring)(extensions, allocator);
	return instance_creation_result;
}

