#include "instance_prober.h"

static VkResult gfx_query_vk_instance_supported_extensions(Slice(VkExtensionProperties)* extensions, Allocator allocator) {
	VkResult result;

	u32 extension_count;
	result = vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);
	if (result != VK_SUCCESS) {
		return result;
	}

	*extensions = slice_make(VkExtensionProperties)(extension_count, allocator);
	result = vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, extensions->data);
	if (result != VK_SUCCESS) {
		slice_delete(VkExtensionProperties)(*extensions, allocator);
		return result;
	}

	return VK_SUCCESS;
}

static VkResult gfx_query_vk_instance_supported_layers(Slice(VkLayerProperties)* layers, Allocator allocator) {
	VkResult result;

	u32 layer_count;
	result = vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
	if (result != VK_SUCCESS) {
		return result;
	}

	*layers = slice_make(VkLayerProperties)(layer_count, allocator);
	result = vkEnumerateInstanceLayerProperties(&layer_count, layers->data);
	if (result != VK_SUCCESS) {
		slice_delete(VkLayerProperties)(*layers, allocator);
		return result;
	}

	return VK_SUCCESS;
}

static inline VkResult gfx_query_vk_supported_version(VkVersion* version) {
	return vkEnumerateInstanceVersion(version);
}

gfx_Result gfx_vkinstanceprober_make(gfx_VkInstanceProber* prober, Allocator allocator) {
	VkResult result;

	*prober = (gfx_VkInstanceProber){ 0 };

	result = gfx_query_vk_instance_supported_extensions(&prober->supported_extensions, allocator);
	if (result != VK_SUCCESS) {
		goto query_failed;
	}
	result = gfx_query_vk_instance_supported_layers(&prober->supported_layers, allocator);
	if (result != VK_SUCCESS) {
		goto query_failed;
	}
	result = gfx_query_vk_supported_version(&prober->supported_vulkan_version);
	if (result != VK_SUCCESS) {
		goto query_failed;
	}

	prober->allocator = allocator;
	return GFX_SUCCESS;

query_failed:
	slice_delete(VkExtensionProperties)(prober->supported_extensions, allocator);
	slice_delete(VkLayerProperties)(prober->supported_layers, allocator);

	return (gfx_Result)(result);
}

void gfx_vkinstanceprober_delete(const gfx_VkInstanceProber* prober) {
	slice_delete(VkExtensionProperties)(prober->supported_extensions, prober->allocator);
	slice_delete(VkLayerProperties)(prober->supported_layers, prober->allocator);
}

bool gfx_vkinstanceprober_is_extension_supported(const gfx_VkInstanceProber* prober, rawstring extension_name) {
	return slice_contains(VkExtensionProperties)(
	    prober->supported_extensions, 
	    lambda((const VkExtensionProperties* extension){
	        rawstring search_name = extension_name;
	        rawstring extension_name = (rawstring)extension->extensionName;
	        return equality_comparator(rawstring)(
	            (rawstring*)(&extension_name), 
	            &search_name
	        );
		})
	);
}

bool gfx_vkinstanceprober_is_layer_supported(const gfx_VkInstanceProber* prober, rawstring layer_name) {
	return slice_contains(VkLayerProperties)(
	    prober->supported_layers, 
	    lambda((const VkLayerProperties* layer){
	        rawstring search_name = layer_name;
	        rawstring layer_name = (rawstring)(layer->layerName);
	        return equality_comparator(rawstring)(
	            &layer_name, 
	            &search_name
	        );
		})
	);
}

