#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>

#include <gfx/hal/result.h>
#include <gfx/hal/vk/instance.h>

typedef struct {
	const char* application_name;
	gfx_Version application_version;

	bool enable_debug;
} descriptor_of(gfx_Instance);

extern singleton struct gfx_Instance {
	Context* context;

	gfx_VkInstance instance;
	bool debug_enabled;
} singleton_of(gfx_Instance);

gfx_Result gfx_instance_init(const descriptor_of(gfx_Instance)* descriptor, Context* context);
void gfx_instance_deinit();
