#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>
#include <gfx/hal/result.h>
#include <gfx/hal/vk/std_glue.h>

typedef struct {
	VkQueueFamilyProperties properties;
} gfx_VkQueueFamily;
typedef const gfx_VkQueueFamily* gfx_VkQueueFamily_Ptr;

STD_DECLARE_SLICE_OF(gfx_VkQueueFamily)
STD_DECLARE_SLICE_MEM_UTILS_OF(gfx_VkQueueFamily)

STD_DECLARE_SLICE_OF(gfx_VkQueueFamily_Ptr)
STD_DECLARE_SLICE_MEM_UTILS_OF(gfx_VkQueueFamily_Ptr)

static inline void gfx_vkqueuefamily_from_vkqueuefamilyproperties(
	gfx_VkQueueFamily* family, 
	const VkQueueFamilyProperties* properties
) {
	family->properties = *properties;
}

static inline const VkQueueFamilyProperties* gfx_vkqueuefamily_get_properties(const gfx_VkQueueFamily* family) {
	return &family->properties;
}
static inline bool gfx_vkqueuefamily_does_support(const gfx_VkQueueFamily* family, VkQueueFlags type) {
	return (family->properties.queueFlags & type) == type;
}

