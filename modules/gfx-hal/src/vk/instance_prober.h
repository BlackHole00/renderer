#pragma once

#include <gfx/hal/instance.h>
#include <gfx/hal/vk/std_glue.h>

typedef struct {
	Allocator allocator;
	VkVersion supported_vulkan_version;
	Slice(VkExtensionProperties) supported_extensions;
	Slice(VkLayerProperties) supported_layers;
} gfx_VkInstanceProber;

gfx_Result gfx_vkinstanceprober_make(gfx_VkInstanceProber* prober, Allocator allocator);
void gfx_vkinstanceprober_delete(const gfx_VkInstanceProber* prober);

bool gfx_vkinstanceprober_is_extension_supported(const gfx_VkInstanceProber* prober, rawstring extension_name);
bool gfx_vkinstanceprober_is_layer_supported(const gfx_VkInstanceProber* prober, rawstring layer_name);
static inline bool gfx_vkinstanceprober_is_version_supported(const gfx_VkInstanceProber* prober, VkVersion version) {
	return prober->supported_vulkan_version >= version;
}

