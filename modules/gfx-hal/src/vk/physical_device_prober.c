#include "physical_device_prober.h"

gfx_Result gfx_vkphysicaldeviceprober_make(
    gfx_VkPhysicalDeviceProber* prober, 
    const descriptor_of(gfx_VkPhysicalDeviceProber)* descriptor, 
    Allocator allocator, 
    TempAllocator temp_allocator
) {
	gfx_Result result;
	VkInstance instance = gfx_vkinstance_as_vulkan_instance(descriptor->instance);

	u32 physical_device_count;
	result = (gfx_Result)(vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr));
	if (result != GFX_SUCCESS) {
		return result;
	}

	Slice(VkPhysicalDevice) vulkan_devices = slice_make(VkPhysicalDevice)(physical_device_count, temp_allocator);
	result = (gfx_Result)(vkEnumeratePhysicalDevices(instance, &physical_device_count, vulkan_devices.data));
	if (result != GFX_SUCCESS) {
		return result;
	}

	Slice(gfx_VkPhysicalDevice) available_devices = slice_make(gfx_VkPhysicalDevice)(physical_device_count, allocator);
	for (usize i = 0; i < physical_device_count; i++) {
		gfx_vkphysicaldevice_from_vulkan_physical_device(
			&available_devices.data[i],
			vulkan_devices.data[i],
			allocator
		);
	}

	*prober = (gfx_VkPhysicalDeviceProber){
		.allocator = allocator,
		.avaliable_devices = available_devices
	};

	return GFX_SUCCESS;
}

void gfx_vkphysicaldeviceprober_delete(const gfx_VkPhysicalDeviceProber* prober) {
	slice_delete(gfx_VkPhysicalDevice)(prober->avaliable_devices, prober->allocator);
	for (usize i = 0; i < prober->avaliable_devices.length; i++) {
		gfx_vkphysicaldevice_delete(&prober->avaliable_devices.data[i]);
	}
}

