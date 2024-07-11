#pragma once

#include <std/std.h>

typedef struct {
	rawstring name;
	bool critical;
} gfx_VkInitializationExtension;
typedef gfx_VkInitializationExtension gfx_VkInitializationLayer;

STD_DECLARE_SLICE_OF(gfx_VkInitializationExtension)
STD_DECLARE_SLICE_MEM_UTILS_OF(gfx_VkInitializationExtension)
STD_DECLARE_SLICE_OF(gfx_VkInitializationLayer)
STD_DECLARE_SLICE_MEM_UTILS_OF(gfx_VkInitializationLayer)
