#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>

#include <gfx/hal/version.h>
#include <gfx/hal/result.h>
#include <gfx/hal/vk/initialization_extension_layer.h>

typedef struct {
	Slice(gfx_VkInitializationExtension) requested_extensions;
	Slice(gfx_VkInitializationLayer) requested_layers;
	gfx_Version requested_version;
	rawstring application_name;
	gfx_Version application_version;
	rawstring engine_name;
	gfx_Version engine_version;
} descriptor_of(gfx_VkInstance);

typedef struct {
	Context* context;
	VkInstance instance;
	Slice(rawstring) enabled_extensions;
	Slice(rawstring) enabled_layers;
	gfx_Version supported_version;
} gfx_VkInstance;

gfx_Result gfx_vkinstance_make(gfx_VkInstance* instance, const descriptor_of(gfx_VkInstance)* descriptor, Context* context);
void gfx_vkinstance_delete(const gfx_VkInstance* instance);
