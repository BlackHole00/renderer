#pragma once

#include <std/std.h>
#include <vulkan/vulkan.h>

#include <gfx/hal/result.h>
#include <gfx/hal/vk/instance.h>

typedef struct {
	VkDebugUtilsMessageTypeFlagsEXT allowed_message_types;
	Logger logger;
} descriptor_of(gfx_VkDebugMessenger);

typedef struct gfx_VkDebugMessenger {
	Logger vulkan_logger;
	VkDebugUtilsMessageTypeFlagsEXT allowed_message_types;

	// nullptr if not attached to an instance
	const gfx_VkInstance* instance;
	// nullptr if not attached to an instance
	VkDebugUtilsMessengerEXT messenger;

	Logger logger;
} gfx_VkDebugMessenger;

void gfx_vkdebugmessenger_make(
    gfx_VkDebugMessenger* messenger, 
    const descriptor_of(gfx_VkDebugMessenger)* descriptor, 
    Logger logger
);
void gfx_vkdebugmessenger_delete(gfx_VkDebugMessenger* messenger);

gfx_Result gfx_vkdebugmessenger_attach_to_instance(gfx_VkDebugMessenger* messenger, const gfx_VkInstance* instance);
void gfx_vkdebugmessenger_detach(gfx_VkDebugMessenger* messenger);
void gfx_vkdebugmessenger_get_vulkan_createinfo(const gfx_VkDebugMessenger* messenger, VkDebugUtilsMessengerCreateInfoEXT* result);

static inline bool gfx_vkdebugmessenger_is_attached_to_instance(const gfx_VkDebugMessenger* messenger) {
	return messenger->instance != nullptr;
}
static inline const gfx_VkInstance* gfx_vkdebugmessenger_get_attached_instance(const gfx_VkDebugMessenger* messenger) {
	return messenger->instance;
}
