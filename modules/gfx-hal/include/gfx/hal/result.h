#pragma once

#include <vulkan/vulkan.h>

typedef enum { // superset of VkResult
	GFX_SUCCESS = VK_SUCCESS,
	// VkResult enum
	GFX_RESULT_COUNT = VK_ERROR_UNKNOWN + 1,
} gfx_Result;
