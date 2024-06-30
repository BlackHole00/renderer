#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>

#include <gfx/hal/result.h>

typedef u32 VkVersion;

typedef struct {
	const char* application_name;
	VkVersion application_version;

	bool enable_debug;
} descriptor_of(gfx_Instance);

extern singleton struct gfx_Instance {
	Allocator allocator;

	VkInstance instance;
	bool debug_enabled;

	Slice(rawstring) instance_extensions;
} singleton_of(gfx_Instance);

gfx_Result gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor, Allocator allocator);
void gfx_instance_deinit();
