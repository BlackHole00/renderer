#pragma once

#include <vulkan/vulkan.h>

typedef enum { // superset of VkResult
	GFX_SUCCESS = VK_SUCCESS,
	// VkResult enum
	GFX_UNSUPPORTED_VK_VERSION = VK_ERROR_UNKNOWN - 1,
	GFX_UNSUPPORTED_VK_INSTANCE_EXTENSION = GFX_UNSUPPORTED_VK_VERSION - 1,
	GFX_UNSUPPORTED_VK_INSTANCE_LAYER = GFX_UNSUPPORTED_VK_INSTANCE_EXTENSION - 1,
	GFX_INVALID_INSTANCE_FUNCTION_QUERY = GFX_UNSUPPORTED_VK_INSTANCE_LAYER - 1,
} gfx_Result;
