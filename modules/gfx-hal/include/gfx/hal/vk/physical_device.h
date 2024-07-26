#pragma once

#include <vulkan/vulkan.h>
#include <gfx/hal/vk/instance.h>
#include <gfx/hal/vk/std_glue.h>
#include <gfx/hal/vk/queue_family.h>

typedef struct {
	Allocator allocator;

	VkPhysicalDevice physical_device;
	VkPhysicalDeviceProperties properties;
	VkPhysicalDeviceFeatures features;

	Slice(gfx_VkQueueFamily) queue_families;
} gfx_VkPhysicalDevice;

STD_DECLARE_SLICE_OF(gfx_VkPhysicalDevice)
STD_DECLARE_SLICE_MEM_UTILS_OF(gfx_VkPhysicalDevice)

void gfx_vkphysicaldevice_from_vulkan_physical_device(gfx_VkPhysicalDevice* device, VkPhysicalDevice vulkan_device, Allocator allocator);
static inline void gfx_vkphysicaldevice_delete(const gfx_VkPhysicalDevice* device) {
	slice_delete(gfx_VkQueueFamily)(device->queue_families, device->allocator);
}

static inline VkPhysicalDevice gfx_vkphysicaldevice_as_vulkan_physical_device(const gfx_VkPhysicalDevice* device) {
	return device->physical_device;
}
static inline const VkPhysicalDeviceProperties* gfx_vkphysicaldevice_get_properties(const gfx_VkPhysicalDevice* device) {
	return &device->properties;
}
static inline const VkPhysicalDeviceFeatures* gfx_vkphysicaldevice_get_features(const gfx_VkPhysicalDevice* device) {
	return &device->features;
}
static inline const Slice(gfx_VkQueueFamily) gfx_vkphysicaldevice_get_queue_families(const gfx_VkPhysicalDevice* device) {
	return device->queue_families;
}

Slice(gfx_VkQueueFamily_Ptr) gfx_vkphysicaldevice_get_queue_families_for(const gfx_VkPhysicalDevice* device, VkQueueFlags flag, Allocator allocator);
