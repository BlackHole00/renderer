#include <gfx/hal/vk/debug_messenger.h>

static const char* VK_DEBUG_UTILS_MESSAGE_TYPE_STRING_NAME[] = {
	[VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT    ] = "GENERAL",
	[VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT ] = "VALIDATION",
	[VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT] = "PERFORMANCE",
	[VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT] = "DEVICE ADDRESS BINDING",
};

static inline VKAPI_ATTR VkBool32 VKAPI_CALL debug_messenger_vulkan_callback(
	VkDebugUtilsMessageSeverityFlagBitsEXT severity,
	VkDebugUtilsMessageTypeFlagsEXT message_type,
	const VkDebugUtilsMessengerCallbackDataEXT* message_data,
	void* user_data
) {
	static_typecheck(PFN_vkDebugUtilsMessengerCallbackEXT, debug_messenger_vulkan_callback);

	Logger logger = *(Logger*)(user_data);

	const char* message_type_string = VK_DEBUG_UTILS_MESSAGE_TYPE_STRING_NAME[message_type];
	switch (severity) {
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT: {
			log_trace(logger, "[VULKAN][%s] - %s", message_type_string, message_data->pMessage);
			break;
		}
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT: {
			log_debug(logger, "[VULKAN][%s] - %s", message_type_string, message_data->pMessage);
			break;
		}
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT: {
			log_warn(logger, "[VULKAN][%s] - %s", message_type_string, message_data->pMessage);
			break;
		}
		case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT: {
			log_error(logger, "[VULKAN][%s] - %s", message_type_string, message_data->pMessage);
			break;
		}
		default: {
			log_trace(logger, "[VULKAN][%s] - %s", message_type_string, message_data->pMessage);
		}
	}

	return false;
}

void gfx_vkdebugmessenger_make(
    gfx_VkDebugMessenger* messenger, 
    const descriptor_of(gfx_VkDebugMessenger)* descriptor, 
    Logger logger
) {
	log_info(logger, "Creating a gfx_VkDebugMessenger...");
	log_trace(logger, "Using descriptor:");
	log_trace(logger, "\t- allowed_message_types: %x", descriptor->allowed_message_types);
	log_trace(logger, "\t- logger");

	messenger->logger = logger;

	messenger->vulkan_logger = descriptor->logger;
	messenger->allowed_message_types = descriptor->allowed_message_types;

	messenger->messenger = VK_NULL_HANDLE;
	messenger->instance = nullptr;

	log_debug(logger, "Created gfx_VkDebugMessenger");
}

void gfx_vkdebugmessenger_delete(gfx_VkDebugMessenger* messenger) {
	log_trace(messenger->logger, "Deleting a gfx_VkDebugMessenger...");

	if (messenger->messenger != VK_NULL_HANDLE) {
		gfx_vkdebugmessenger_detach(messenger);
	}
}

void gfx_vkdebugmessenger_get_vulkan_createinfo(const gfx_VkDebugMessenger* messenger, VkDebugUtilsMessengerCreateInfoEXT* result) {
	*result = (VkDebugUtilsMessengerCreateInfoEXT){
		.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
		.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
		.messageType = messenger->allowed_message_types,
		.pfnUserCallback = debug_messenger_vulkan_callback,
		.pUserData = (void*)(&messenger->vulkan_logger),
	};
}

gfx_Result gfx_vkdebugmessenger_attach_to_instance(gfx_VkDebugMessenger* messenger, const gfx_VkInstance* instance) {
	log_debug(messenger->logger, "Linking debug messenger to instance...");

	log_trace(messenger->logger, "Obtaining vulkan function \"PFN_vkCreateDebugUtilsMessengerEXT\"...");
	auto vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
		gfx_vkinstance_as_vulkan_instance(instance),
		"vkCreateDebugUtilsMessengerEXT"
	);
	if (vkCreateDebugUtilsMessengerEXT == nullptr) {
		log_error(messenger->logger, "Could not link gfx_VkDebugMessenger to an instance: Cound not get vulkan function \"PFN_vkCreateDebugUtilsMessengerEXT\"");
		return GFX_INVALID_INSTANCE_FUNCTION_QUERY;
	}

	VkDebugUtilsMessengerCreateInfoEXT messenger_info;
	gfx_vkdebugmessenger_get_vulkan_createinfo(messenger, &messenger_info);

	log_debug(messenger->logger, "Creating a VkDebugUtilsMessengerEXT...");
	log_trace(messenger->logger, "Using create info:");
	log_trace(messenger->logger, "\t- sType: %x", messenger_info.sType);
	log_trace(messenger->logger, "\t- pNext: %p", (void*)(messenger_info.pNext));
	log_trace(messenger->logger, "\t- flags: %x", messenger_info.flags);
	log_trace(messenger->logger, "\t- messageSeverity: %x", messenger_info.messageSeverity);
	log_trace(messenger->logger, "\t- messageType: %x", messenger_info.messageType);
	log_trace(messenger->logger, "\t- pfnUserCallback: %p", (void*)(messenger_info.pfnUserCallback));
	log_trace(messenger->logger, "\t- pUserData: %p", (messenger_info.pUserData));

	gfx_Result result = (gfx_Result)(vkCreateDebugUtilsMessengerEXT(
	    gfx_vkinstance_as_vulkan_instance(instance), 
	    &messenger_info, 
	    nullptr, 
	    &messenger->messenger
	));
	if (result != GFX_SUCCESS) {
		log_error(messenger->logger, "Could not create a VkDebugUtilsMessengerEXT (error code: %d)", result);
		return result;
	}

	messenger->instance = instance;

	log_debug(messenger->logger, "Successfully linked debug messenger to instance");
	return GFX_SUCCESS;
}

void gfx_vkdebugmessenger_detach(gfx_VkDebugMessenger* messenger) {
	log_trace(messenger->logger, "Detaching a gfx_VkDebugMessenger from a gfx_VkInstance...");

	log_trace(messenger->logger, "Obtaining vulkan function \"PFN_vkDestroyDebugUtilsMessengerEXT\"...");
	auto vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
		gfx_vkinstance_as_vulkan_instance(messenger->instance),
		"vkDestroyDebugUtilsMessengerEXT"
	);
	if (vkDestroyDebugUtilsMessengerEXT == nullptr) {
		log_error(messenger->logger, "Could not delete gfx_VkDebugMessenger: Cound not get vulkan function \"PFN_vkDestroyDebugUtilsMessengerEXT\"");
		return;
	}

	vkDestroyDebugUtilsMessengerEXT(
		gfx_vkinstance_as_vulkan_instance(messenger->instance),
		messenger->messenger,
		nullptr
	);

	messenger->messenger = VK_NULL_HANDLE;
	messenger->instance = nullptr;

	log_trace(messenger->logger, "Successfully detatched the gfx_VkDebugMessenger from the gfx_VkInstance");
}
