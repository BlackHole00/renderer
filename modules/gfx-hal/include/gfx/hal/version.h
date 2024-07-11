#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>

typedef u32 VkVersion;
typedef VkVersion gfx_Version;

static inline gfx_Version gfx_version_make(usize major, usize minor, usize rev) {
	return VK_MAKE_VERSION(major, minor, rev);
}

