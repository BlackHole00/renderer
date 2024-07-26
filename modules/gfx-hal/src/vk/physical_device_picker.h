#pragma once

#include <std/std.h>
#include "physical_device_prober.h"

typedef struct {
	Slice(VkPhysicalDeviceType) allowed_device_types;
	VkPhysicalDeviceLimits required_limits;
	VkPhysicalDeviceFeatures required_features;
} gfx_VkPhysicalDevicePicker_DevicePreferences;

typedef struct {
	const gfx_VkPhysicalDeviceProber* prober;
} descriptor_of(gfx_VkPhysicalDevicePicker);

typedef struct {
	const gfx_VkPhysicalDeviceProber* prober;
} gfx_VkPhysicalDevicePicker;

static inline void gfx_vkphysicaldevicepicker_make(gfx_VkPhysicalDevicePicker* picker, const descriptor_of(gfx_VkPhysicalDevicePicker)* descriptor) {
	picker->prober = descriptor->prober;
}

Slice(gfx_VkPhysicalDevice) gfx_vkphysicaldevicepicker_rank_devices(
	const gfx_VkPhysicalDevicePicker* picker,
	const gfx_VkPhysicalDevicePicker_DevicePreferences* preferences,
	Allocator allocator
);

static inline bool gfx_vkphysicaldevicepicker_pick_best(
	const gfx_VkPhysicalDevicePicker* picker,
	gfx_VkPhysicalDevice* device,
	const gfx_VkPhysicalDevicePicker_DevicePreferences* preferences,
	TempAllocator temp_allocator
) {
	Slice(gfx_VkPhysicalDevice) devices = gfx_vkphysicaldevicepicker_rank_devices(picker, preferences, temp_allocator);
	if (devices.length == 0) {
		return false;
	}

	*device = devices.data[0];
	return true;
}

