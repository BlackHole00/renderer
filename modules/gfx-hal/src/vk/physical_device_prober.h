#pragma once

#include <std/std.h>
#include <gfx/hal/vk/instance.h>
#include <gfx/hal/vk/physical_device.h>
#include <gfx/hal/vk/std_glue.h>

typedef struct {
	const gfx_VkInstance* instance;
} descriptor_of(gfx_VkPhysicalDeviceProber);

typedef struct {
	Allocator allocator;
	Slice(gfx_VkPhysicalDevice) avaliable_devices;
} gfx_VkPhysicalDeviceProber;

gfx_Result gfx_vkphysicaldeviceprober_make(gfx_VkPhysicalDeviceProber* prober, const descriptor_of(gfx_VkPhysicalDeviceProber)* descriptor, Allocator allocator, TempAllocator temp_allocator);
// Not needed when using a temporary allocator 
void gfx_vkphysicaldeviceprober_delete(const gfx_VkPhysicalDeviceProber* prober);

static inline usize gfx_vkphysicaldeviceprober_get_device_count(const gfx_VkPhysicalDeviceProber* prober) {
	return prober->avaliable_devices.length;
}

static inline Slice(gfx_VkPhysicalDevice) gfx_vkphysicaldeviceprober_get_devices(const gfx_VkPhysicalDeviceProber* prober) {
	return prober->avaliable_devices;
}

