#pragma once

#include <strings.h>
#include <std/std.h>
#include <vulkan/vulkan.h>

static inline bool equality_comparator_of(VkExtensionProperties)(
    const VkExtensionProperties* left, 
    const VkExtensionProperties* right
) {
	return left->specVersion == right->specVersion && equality_comparator(rawstring)(
		(rawstring*)(&left->extensionName), 
		(rawstring*)(&right->extensionName)
	);
}

static inline bool equality_comparator_of(VkLayerProperties)(
    const VkLayerProperties* left, 
    const VkLayerProperties* right
) {
	return left->specVersion == right->specVersion && 
	    left->implementationVersion == right->implementationVersion &&
		equality_comparator(rawstring)(
			(rawstring*)(&left->layerName), 
			(rawstring*)(&right->layerName)
		);
}

STD_DECLARE_SLICE_OF(VkExtensionProperties)
STD_DECLARE_SLICE_MEM_UTILS_OF(VkExtensionProperties)
STD_DECLARE_SLICE_COMMON_UTILS_OF(VkExtensionProperties, equality_comparator_of(VkExtensionProperties))

STD_DECLARE_SLICE_OF(VkLayerProperties)
STD_DECLARE_SLICE_MEM_UTILS_OF(VkLayerProperties)
STD_DECLARE_SLICE_COMMON_UTILS_OF(VkLayerProperties, equality_comparator_of(VkLayerProperties))


