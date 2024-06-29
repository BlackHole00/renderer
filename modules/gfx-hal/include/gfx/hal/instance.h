#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>

typedef u32 VkVersion;

typedef struct {
	const char* application_name;
	VkVersion application_version;

	bool support_glfw;
} descriptor_of(gfx_Instance);

extern singleton struct gfx_Instance {
	VkInstance instance;
} singleton_of(gfx_Instance);

void gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor);
