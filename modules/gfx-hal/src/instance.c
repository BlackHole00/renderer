#include <gfx/hal/instance.h>

singleton struct gfx_Instance singleton_of(gfx_Instance);

void gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor) {
	VkApplicationInfo application_info = (VkApplicationInfo){
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName = descriptor->application_name,
		.applicationVersion = descriptor->application_version,
		.pEngineName = "gfx-hal",
		.engineVersion = VK_MAKE_VERSION(0, 0, 1),
		.apiVersion = VK_MAKE_VERSION(1, 2, 0)
	};

	VkInstanceCreateInfo instance_info = (VkInstanceCreateInfo){
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	};
}

