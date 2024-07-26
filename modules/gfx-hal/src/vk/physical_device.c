#include <gfx/hal/vk/physical_device.h>

void gfx_vkphysicaldevice_from_vulkan_physical_device(gfx_VkPhysicalDevice* device, VkPhysicalDevice vulkan_device, Allocator allocator) {
	vkGetPhysicalDeviceProperties(vulkan_device, &device->properties);
	vkGetPhysicalDeviceFeatures(vulkan_device, &device->features);

	u32 queue_families_count;
	vkGetPhysicalDeviceQueueFamilyProperties(vulkan_device, &queue_families_count, nullptr);

	Slice(gfx_VkQueueFamily) families = slice_make(gfx_VkQueueFamily)(queue_families_count, allocator);

	// NOTE(Vicix): The following lines assume that gfx_VkQueueFamily is just 
	//              VkQueueFamilyProperties, in order to avoid unnecessary data 
	//              copies. This holds true for now, but if it is changed in the
	//              future also the following code must change
	static_assert(
		sizeof(gfx_VkQueueFamily) == sizeof(VkQueueFamilyProperties), 
		"This code assumes that gfx_VkQueueFamilies is VkQueueFamilyProperties"
	);
	vkGetPhysicalDeviceQueueFamilyProperties(vulkan_device, &queue_families_count, (VkQueueFamilyProperties*)(families.data));
	
	device->physical_device = vulkan_device;
}
