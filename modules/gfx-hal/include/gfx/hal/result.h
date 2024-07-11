#pragma once

#include <vulkan/vulkan.h>

typedef enum { // superset of VkResult
	GFX_SUCCESS = VK_SUCCESS,
	// VkResult enum
	GFX_UNSUPPORTED_VK_VERSION = VK_ERROR_UNKNOWN + 1,
	GFX_UNSUPPORTED_VK_INSTANCE_EXTENSION,
	GFX_UNSUPPORTED_VK_INSTANCE_LAYER,
	GFX_RESULT_COUNT
} gfx_Result;
