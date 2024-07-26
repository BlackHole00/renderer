#include "physical_device_picker.h"

static const usize VK_PHYSICALDEVICETYPE_SCORE[] = {
	[VK_PHYSICAL_DEVICE_TYPE_OTHER] = 0,
	[VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU] = 1000,
	[VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU] = 2000,
	[VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU] = 500,
	[VK_PHYSICAL_DEVICE_TYPE_CPU] = 100,
};

static bool gfx_vkphysicaldevice_is_suitable(
    const gfx_VkPhysicalDevice* device, 
    const gfx_VkPhysicalDevicePicker_DevicePreferences* preferences
) {
	bool is_device_type_valid = slice_find(VkPhysicalDeviceType)(
	    preferences->allowed_device_types, 
	    lambda((const VkPhysicalDeviceType* type){
	        bool res = device->properties.deviceType == *type;
	        return res;
		})
	);

	return is_device_type_valid &&
	    (!preferences->required_features.robustBufferAccess                           || device->features.robustBufferAccess                                      ) &&
		(!preferences->required_features.fullDrawIndexUint32                          || device->features.fullDrawIndexUint32                                     ) &&
		(!preferences->required_features.imageCubeArray                               || device->features.imageCubeArray                                          ) &&
		(!preferences->required_features.independentBlend                             || device->features.independentBlend                                        ) &&
		(!preferences->required_features.geometryShader                               || device->features.geometryShader                                          ) &&
		(!preferences->required_features.tessellationShader                           || device->features.tessellationShader                                      ) &&
		(!preferences->required_features.sampleRateShading                            || device->features.sampleRateShading                                       ) &&
		(!preferences->required_features.dualSrcBlend                                 || device->features.dualSrcBlend                                            ) &&
		(!preferences->required_features.logicOp                                      || device->features.logicOp                                                 ) &&
		(!preferences->required_features.multiDrawIndirect                            || device->features.multiDrawIndirect                                       ) &&
		(!preferences->required_features.drawIndirectFirstInstance                    || device->features.drawIndirectFirstInstance                               ) &&
		(!preferences->required_features.depthClamp                                   || device->features.depthClamp                                              ) &&
		(!preferences->required_features.depthBiasClamp                               || device->features.depthBiasClamp                                          ) &&
		(!preferences->required_features.fillModeNonSolid                             || device->features.fillModeNonSolid                                        ) &&
		(!preferences->required_features.depthBounds                                  || device->features.depthBounds                                             ) &&
		(!preferences->required_features.wideLines                                    || device->features.wideLines                                               ) &&
		(!preferences->required_features.largePoints                                  || device->features.largePoints                                             ) &&
		(!preferences->required_features.alphaToOne                                   || device->features.alphaToOne                                              ) &&
		(!preferences->required_features.multiViewport                                || device->features.multiViewport                                           ) &&
		(!preferences->required_features.samplerAnisotropy                            || device->features.samplerAnisotropy                                       ) &&
		(!preferences->required_features.textureCompressionETC2                       || device->features.textureCompressionETC2                                  ) &&
		(!preferences->required_features.textureCompressionASTC_LDR                   || device->features.textureCompressionASTC_LDR                              ) &&
		(!preferences->required_features.textureCompressionBC                         || device->features.textureCompressionBC                                    ) &&
		(!preferences->required_features.occlusionQueryPrecise                        || device->features.occlusionQueryPrecise                                   ) &&
		(!preferences->required_features.pipelineStatisticsQuery                      || device->features.pipelineStatisticsQuery                                 ) &&
		(!preferences->required_features.vertexPipelineStoresAndAtomics               || device->features.vertexPipelineStoresAndAtomics                          ) &&
		(!preferences->required_features.fragmentStoresAndAtomics                     || device->features.fragmentStoresAndAtomics                                ) &&
		(!preferences->required_features.shaderTessellationAndGeometryPointSize       || device->features.shaderTessellationAndGeometryPointSize                  ) &&
		(!preferences->required_features.shaderImageGatherExtended                    || device->features.shaderImageGatherExtended                               ) &&
		(!preferences->required_features.shaderStorageImageExtendedFormats            || device->features.shaderStorageImageExtendedFormats                       ) &&
		(!preferences->required_features.shaderStorageImageMultisample                || device->features.shaderStorageImageMultisample                           ) &&
		(!preferences->required_features.shaderStorageImageReadWithoutFormat          || device->features.shaderStorageImageReadWithoutFormat                     ) &&
		(!preferences->required_features.shaderStorageImageWriteWithoutFormat         || device->features.shaderStorageImageWriteWithoutFormat                    ) &&
		(!preferences->required_features.shaderUniformBufferArrayDynamicIndexing      || device->features.shaderUniformBufferArrayDynamicIndexing                 ) &&
		(!preferences->required_features.shaderSampledImageArrayDynamicIndexing       || device->features.shaderSampledImageArrayDynamicIndexing                  ) &&
		(!preferences->required_features.shaderStorageBufferArrayDynamicIndexing      || device->features.shaderStorageBufferArrayDynamicIndexing                 ) &&
		(!preferences->required_features.shaderStorageImageArrayDynamicIndexing       || device->features.shaderStorageImageArrayDynamicIndexing                  ) &&
		(!preferences->required_features.shaderClipDistance                           || device->features.shaderClipDistance                                      ) &&
		(!preferences->required_features.shaderCullDistance                           || device->features.shaderCullDistance                                      ) &&
		(!preferences->required_features.shaderFloat64                                || device->features.shaderFloat64                                           ) &&
		(!preferences->required_features.shaderInt64                                  || device->features.shaderInt64                                             ) &&
		(!preferences->required_features.shaderInt16                                  || device->features.shaderInt16                                             ) &&
		(!preferences->required_features.shaderResourceResidency                      || device->features.shaderResourceResidency                                 ) &&
		(!preferences->required_features.shaderResourceMinLod                         || device->features.shaderResourceMinLod                                    ) &&
		(!preferences->required_features.sparseBinding                                || device->features.sparseBinding                                           ) &&
		(!preferences->required_features.sparseResidencyBuffer                        || device->features.sparseResidencyBuffer                                   ) &&
		(!preferences->required_features.sparseResidencyImage2D                       || device->features.sparseResidencyImage2D                                  ) &&
		(!preferences->required_features.sparseResidencyImage3D                       || device->features.sparseResidencyImage3D                                  ) &&
		(!preferences->required_features.sparseResidency2Samples                      || device->features.sparseResidency2Samples                                 ) &&
		(!preferences->required_features.sparseResidency4Samples                      || device->features.sparseResidency4Samples                                 ) &&
		(!preferences->required_features.sparseResidency8Samples                      || device->features.sparseResidency8Samples                                 ) &&
		(!preferences->required_features.sparseResidency16Samples                     || device->features.sparseResidency16Samples                                ) &&
		(!preferences->required_features.sparseResidencyAliased                       || device->features.sparseResidencyAliased                                  ) &&
		(!preferences->required_features.variableMultisampleRate                      || device->features.variableMultisampleRate                                 ) &&
		(!preferences->required_features.inheritedQueries                             || device->features.inheritedQueries                                        ) &&
		(preferences->required_limits.maxImageDimension1D                             <= device->properties.limits.maxImageDimension1D                            ) &&
		(preferences->required_limits.maxImageDimension2D                             <= device->properties.limits.maxImageDimension2D                            ) &&
		(preferences->required_limits.maxImageDimension3D                             <= device->properties.limits.maxImageDimension3D                            ) &&
		(preferences->required_limits.maxImageDimensionCube                           <= device->properties.limits.maxImageDimensionCube                          ) &&
		(preferences->required_limits.maxImageArrayLayers                             <= device->properties.limits.maxImageArrayLayers                            ) &&
		(preferences->required_limits.maxTexelBufferElements                          <= device->properties.limits.maxTexelBufferElements                         ) &&
		(preferences->required_limits.maxUniformBufferRange                           <= device->properties.limits.maxUniformBufferRange                          ) &&
		(preferences->required_limits.maxStorageBufferRange                           <= device->properties.limits.maxStorageBufferRange                          ) &&
		(preferences->required_limits.maxPushConstantsSize                            <= device->properties.limits.maxPushConstantsSize                           ) &&
		(preferences->required_limits.maxMemoryAllocationCount                        <= device->properties.limits.maxMemoryAllocationCount                       ) &&
		(preferences->required_limits.maxSamplerAllocationCount                       <= device->properties.limits.maxSamplerAllocationCount                      ) &&
		(preferences->required_limits.bufferImageGranularity                          <= device->properties.limits.bufferImageGranularity                         ) &&
		(preferences->required_limits.sparseAddressSpaceSize                          <= device->properties.limits.sparseAddressSpaceSize                         ) &&
		(preferences->required_limits.maxBoundDescriptorSets                          <= device->properties.limits.maxBoundDescriptorSets                         ) &&
		(preferences->required_limits.maxPerStageDescriptorSamplers                   <= device->properties.limits.maxPerStageDescriptorSamplers                  ) &&
		(preferences->required_limits.maxPerStageDescriptorUniformBuffers             <= device->properties.limits.maxPerStageDescriptorUniformBuffers            ) &&
		(preferences->required_limits.maxPerStageDescriptorStorageBuffers             <= device->properties.limits.maxPerStageDescriptorStorageBuffers            ) &&
		(preferences->required_limits.maxPerStageDescriptorSampledImages              <= device->properties.limits.maxPerStageDescriptorSampledImages             ) &&
		(preferences->required_limits.maxPerStageDescriptorStorageImages              <= device->properties.limits.maxPerStageDescriptorStorageImages             ) &&
		(preferences->required_limits.maxPerStageDescriptorInputAttachments           <= device->properties.limits.maxPerStageDescriptorInputAttachments          ) &&
		(preferences->required_limits.maxPerStageResources                            <= device->properties.limits.maxPerStageResources                           ) &&
		(preferences->required_limits.maxDescriptorSetSamplers                        <= device->properties.limits.maxDescriptorSetSamplers                       ) &&
		(preferences->required_limits.maxDescriptorSetUniformBuffers                  <= device->properties.limits.maxDescriptorSetUniformBuffers                 ) &&
		(preferences->required_limits.maxDescriptorSetUniformBuffersDynamic           <= device->properties.limits.maxDescriptorSetUniformBuffersDynamic          ) &&
		(preferences->required_limits.maxDescriptorSetStorageBuffers                  <= device->properties.limits.maxDescriptorSetStorageBuffers                 ) &&
		(preferences->required_limits.maxDescriptorSetStorageBuffersDynamic           <= device->properties.limits.maxDescriptorSetStorageBuffersDynamic          ) &&
		(preferences->required_limits.maxDescriptorSetSampledImages                   <= device->properties.limits.maxDescriptorSetSampledImages                  ) &&
		(preferences->required_limits.maxDescriptorSetStorageImages                   <= device->properties.limits.maxDescriptorSetStorageImages                  ) &&
		(preferences->required_limits.maxDescriptorSetInputAttachments                <= device->properties.limits.maxDescriptorSetInputAttachments               ) &&
		(preferences->required_limits.maxVertexInputAttributes                        <= device->properties.limits.maxVertexInputAttributes                       ) &&
		(preferences->required_limits.maxVertexInputBindings                          <= device->properties.limits.maxVertexInputBindings                         ) &&
		(preferences->required_limits.maxVertexInputAttributeOffset                   <= device->properties.limits.maxVertexInputAttributeOffset                  ) &&
		(preferences->required_limits.maxVertexInputBindingStride                     <= device->properties.limits.maxVertexInputBindingStride                    ) &&
		(preferences->required_limits.maxVertexOutputComponents                       <= device->properties.limits.maxVertexOutputComponents                      ) &&
		(preferences->required_limits.maxTessellationGenerationLevel                  <= device->properties.limits.maxTessellationGenerationLevel                 ) &&
		(preferences->required_limits.maxTessellationPatchSize                        <= device->properties.limits.maxTessellationPatchSize                       ) &&
		(preferences->required_limits.maxTessellationControlPerVertexInputComponents  <= device->properties.limits.maxTessellationControlPerVertexInputComponents ) &&
		(preferences->required_limits.maxTessellationControlPerVertexOutputComponents <= device->properties.limits.maxTessellationControlPerVertexOutputComponents) &&
		(preferences->required_limits.maxTessellationControlPerPatchOutputComponents  <= device->properties.limits.maxTessellationControlPerPatchOutputComponents ) &&
		(preferences->required_limits.maxTessellationControlTotalOutputComponents     <= device->properties.limits.maxTessellationControlTotalOutputComponents    ) &&
		(preferences->required_limits.maxTessellationEvaluationInputComponents        <= device->properties.limits.maxTessellationEvaluationInputComponents       ) &&
		(preferences->required_limits.maxTessellationEvaluationOutputComponents       <= device->properties.limits.maxTessellationEvaluationOutputComponents      ) &&
		(preferences->required_limits.maxGeometryShaderInvocations                    <= device->properties.limits.maxGeometryShaderInvocations                   ) &&
		(preferences->required_limits.maxGeometryInputComponents                      <= device->properties.limits.maxGeometryInputComponents                     ) &&
		(preferences->required_limits.maxGeometryOutputComponents                     <= device->properties.limits.maxGeometryOutputComponents                    ) &&
		(preferences->required_limits.maxGeometryOutputVertices                       <= device->properties.limits.maxGeometryOutputVertices                      ) &&
		(preferences->required_limits.maxGeometryTotalOutputComponents                <= device->properties.limits.maxGeometryTotalOutputComponents               ) &&
		(preferences->required_limits.maxFragmentInputComponents                      <= device->properties.limits.maxFragmentInputComponents                     ) &&
		(preferences->required_limits.maxFragmentOutputAttachments                    <= device->properties.limits.maxFragmentOutputAttachments                   ) &&
		(preferences->required_limits.maxFragmentDualSrcAttachments                   <= device->properties.limits.maxFragmentDualSrcAttachments                  ) &&
		(preferences->required_limits.maxFragmentCombinedOutputResources              <= device->properties.limits.maxFragmentCombinedOutputResources             ) &&
		(preferences->required_limits.maxComputeSharedMemorySize                      <= device->properties.limits.maxComputeSharedMemorySize                     ) &&
		(preferences->required_limits.maxComputeSharedMemorySize                      <= device->properties.limits.maxComputeSharedMemorySize                     ) &&
		(preferences->required_limits.maxComputeWorkGroupCount[0]                     <= device->properties.limits.maxComputeWorkGroupSize[0]                     ) &&
		(preferences->required_limits.maxComputeWorkGroupCount[1]                     <= device->properties.limits.maxComputeWorkGroupSize[1]                     ) &&
		(preferences->required_limits.maxComputeWorkGroupCount[2]                     <= device->properties.limits.maxComputeWorkGroupSize[2]                     ) &&
		(preferences->required_limits.maxComputeWorkGroupInvocations                  <= device->properties.limits.maxComputeWorkGroupInvocations                 ) &&
		(preferences->required_limits.maxComputeWorkGroupSize[0]                      <= device->properties.limits.maxComputeWorkGroupSize[0]                     ) &&
		(preferences->required_limits.maxComputeWorkGroupSize[1]                      <= device->properties.limits.maxComputeWorkGroupSize[1]                     ) &&
		(preferences->required_limits.maxComputeWorkGroupSize[2]                      <= device->properties.limits.maxComputeWorkGroupSize[2]                     ) &&
		(preferences->required_limits.subPixelPrecisionBits                           <= device->properties.limits.subPixelPrecisionBits                          ) &&
		(preferences->required_limits.subTexelPrecisionBits                           <= device->properties.limits.subPixelPrecisionBits                          ) &&
		(preferences->required_limits.mipmapPrecisionBits                             <= device->properties.limits.mipmapPrecisionBits                            ) &&
		(preferences->required_limits.maxDrawIndexedIndexValue                        <= device->properties.limits.maxDrawIndexedIndexValue                       ) &&
		(preferences->required_limits.maxDrawIndirectCount                            <= device->properties.limits.maxDrawIndirectCount                           ) &&
		(preferences->required_limits.maxSamplerLodBias                               <= device->properties.limits.maxSamplerLodBias                              ) &&
		(preferences->required_limits.maxSamplerAnisotropy                            <= device->properties.limits.maxSamplerAnisotropy                           ) &&
		(preferences->required_limits.maxViewports                                    <= device->properties.limits.maxViewports                                   ) &&
		(preferences->required_limits.maxViewportDimensions[0]                        <= device->properties.limits.maxViewportDimensions[0]                       ) &&
		(preferences->required_limits.maxViewportDimensions[1]                        <= device->properties.limits.maxViewportDimensions[1]                       ) &&
		(preferences->required_limits.viewportBoundsRange[0]                          <= device->properties.limits.viewportBoundsRange[0]                         ) &&
		(preferences->required_limits.viewportBoundsRange[1]                          <= device->properties.limits.viewportBoundsRange[1]                         ) &&
		(preferences->required_limits.viewportSubPixelBits                            <= device->properties.limits.viewportSubPixelBits                           ) &&
		(preferences->required_limits.minMemoryMapAlignment                           <= device->properties.limits.minMemoryMapAlignment                          ) &&
		(preferences->required_limits.minTexelBufferOffsetAlignment                   <= device->properties.limits.minTexelBufferOffsetAlignment                  ) &&
		(preferences->required_limits.minUniformBufferOffsetAlignment                 <= device->properties.limits.minUniformBufferOffsetAlignment                ) &&
		(preferences->required_limits.minStorageBufferOffsetAlignment                 <= device->properties.limits.minStorageBufferOffsetAlignment                ) &&
		(preferences->required_limits.minTexelOffset                                  <= device->properties.limits.minTexelOffset                                 ) &&
		(preferences->required_limits.maxTexelOffset                                  <= device->properties.limits.maxTexelOffset                                 ) &&
		(preferences->required_limits.minTexelGatherOffset                            <= device->properties.limits.minTexelGatherOffset                           ) &&
		(preferences->required_limits.maxTexelGatherOffset                            <= device->properties.limits.maxTexelGatherOffset                           ) &&
		(preferences->required_limits.minInterpolationOffset                          <= device->properties.limits.minInterpolationOffset                         ) &&
		(preferences->required_limits.maxInterpolationOffset                          <= device->properties.limits.maxInterpolationOffset                         ) &&
		(preferences->required_limits.subPixelInterpolationOffsetBits                 <= device->properties.limits.subPixelInterpolationOffsetBits                ) &&
		(preferences->required_limits.maxFramebufferWidth                             <= device->properties.limits.maxFramebufferWidth                            ) &&
		(preferences->required_limits.maxFramebufferHeight                            <= device->properties.limits.maxFramebufferHeight                           ) &&
		(preferences->required_limits.maxFramebufferLayers                            <= device->properties.limits.maxFramebufferLayers                           ) &&
		((preferences->required_limits.framebufferColorSampleCounts   & device->properties.limits.framebufferColorSampleCounts)   == preferences->required_limits.framebufferColorSampleCounts  ) &&
		((preferences->required_limits.framebufferDepthSampleCounts   & device->properties.limits.framebufferDepthSampleCounts)   == preferences->required_limits.framebufferDepthSampleCounts  ) &&
		((preferences->required_limits.framebufferStencilSampleCounts & device->properties.limits.framebufferStencilSampleCounts) == preferences->required_limits.framebufferStencilSampleCounts) &&
		((preferences->required_limits.framebufferNoAttachmentsSampleCounts & device->properties.limits.framebufferNoAttachmentsSampleCounts) == preferences->required_limits.framebufferNoAttachmentsSampleCounts) &&
		(preferences->required_limits.maxColorAttachments                             <= device->properties.limits.maxColorAttachments                            ) &&
		(preferences->required_limits.maxColorAttachments                             <= device->properties.limits.maxColorAttachments                            ) &&
		((preferences->required_limits.sampledImageColorSampleCounts   & device->properties.limits.sampledImageColorSampleCounts)   == preferences->required_limits.sampledImageColorSampleCounts  ) &&
		((preferences->required_limits.sampledImageIntegerSampleCounts & device->properties.limits.sampledImageIntegerSampleCounts) == preferences->required_limits.sampledImageIntegerSampleCounts) &&
		((preferences->required_limits.sampledImageDepthSampleCounts   & device->properties.limits.sampledImageDepthSampleCounts)   == preferences->required_limits.sampledImageDepthSampleCounts  ) &&
		((preferences->required_limits.sampledImageStencilSampleCounts & device->properties.limits.sampledImageStencilSampleCounts) == preferences->required_limits.sampledImageStencilSampleCounts) &&
		((preferences->required_limits.storageImageSampleCounts        & device->properties.limits.storageImageSampleCounts)        == preferences->required_limits.storageImageSampleCounts       ) &&
		(preferences->required_limits.maxSampleMaskWords                              <= device->properties.limits.maxSampleMaskWords                             ) &&
		(preferences->required_limits.maxSampleMaskWords                              <= device->properties.limits.maxSampleMaskWords                             ) &&
		(preferences->required_limits.timestampComputeAndGraphics                     <= device->properties.limits.timestampComputeAndGraphics                    ) &&
		(preferences->required_limits.timestampPeriod                                 <= device->properties.limits.timestampPeriod                                ) &&
		(preferences->required_limits.maxClipDistances                                <= device->properties.limits.maxClipDistances                               ) &&
		(preferences->required_limits.maxCullDistances                                <= device->properties.limits.maxCullDistances                               ) &&
		(preferences->required_limits.maxCombinedClipAndCullDistances                 <= device->properties.limits.maxCombinedClipAndCullDistances                ) &&
		(preferences->required_limits.discreteQueuePriorities                         <= device->properties.limits.discreteQueuePriorities                        ) &&
		(preferences->required_limits.pointSizeRange[0]                               <= device->properties.limits.pointSizeRange[0]                              ) &&
		(preferences->required_limits.pointSizeRange[1]                               <= device->properties.limits.pointSizeRange[1]                              ) &&
		(preferences->required_limits.lineWidthRange[0]                               <= device->properties.limits.lineWidthRange[0]                              ) &&
		(preferences->required_limits.lineWidthRange[1]                               <= device->properties.limits.lineWidthRange[1]                              ) &&
		(preferences->required_limits.pointSizeGranularity                            <= device->properties.limits.pointSizeGranularity                           ) &&
		(preferences->required_limits.lineWidthGranularity                            <= device->properties.limits.lineWidthGranularity                           ) &&
		(preferences->required_limits.strictLines                                     <= device->properties.limits.strictLines                                    ) &&
		(preferences->required_limits.standardSampleLocations                         <= device->properties.limits.standardSampleLocations                        ) &&
		(preferences->required_limits.optimalBufferCopyOffsetAlignment                <= device->properties.limits.optimalBufferCopyOffsetAlignment               ) &&
		(preferences->required_limits.optimalBufferCopyRowPitchAlignment              <= device->properties.limits.optimalBufferCopyRowPitchAlignment             ) &&
		(preferences->required_limits.nonCoherentAtomSize                             <= device->properties.limits.nonCoherentAtomSize                            );
}

static usize gfx_vkphysicaldevice_rank(const gfx_VkPhysicalDevice* device) {
	usize score = 0;

	// TODO(Vicix): Improve scoring
	score += VK_PHYSICALDEVICETYPE_SCORE[device->properties.deviceType];
	score += device->properties.limits.maxImageDimension2D;

	return score;
}

Slice(gfx_VkPhysicalDevice) gfx_vkphysicaldevicepicker_rank_devices(
	const gfx_VkPhysicalDevicePicker* picker,
	const gfx_VkPhysicalDevicePicker_DevicePreferences* preferences,
	Allocator allocator
) {
	// TODO(Vicix): Implement
	return slice_make_null(gfx_VkPhysicalDevice)();
}

