#include <assert.h>

#include <std/std.h>
#include <vulkan/vulkan.h>
#include <glfw/glfw3.h>
#include <gfx/hal/instance.h>
#include <gfx/hal/vk/physical_device_picker.h>

#ifdef BUILD_DEBUG
#	define GFX_HAL_DEBUG 1
#else
#	define GFX_HAL_DEBUG 0
#endif

void show_banner(Logger logger) {
	log_info(logger, "Renderer - v.0.0.1");
	log_info(logger, "\tby Vicix");
}

int main(void) {
	unimplemented();

	Allocator allocator = singleton_of(SystemAllocator);
	Allocator temp_allocator = arenaallocator_create(allocator);
	defer(arenaallocator_delete(temp_allocator));
	Allocator global_allocator = arenaallocator_create(allocator);
	defer(arenaallocator_delete(global_allocator));

	Logger logger = consolelogger_make(LOG_LEVEL_TRACE, allocator);

	Context context = (Context){
		.allocator = allocator,
		.temp_allocator = temp_allocator,
		.global_allocator = global_allocator,
		.logger = logger,
	};

	show_banner(logger);

	glfwInitVulkanLoader(vkGetInstanceProcAddr);
	glfwInit();
	defer(glfwTerminate());
	
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	auto window = glfwCreateWindow(640, 480, "Renderer", nullptr, nullptr);
	defer(glfwDestroyWindow(window));

	gfx_Result instance_init_result = gfx_instance_init(&(descriptor_of(gfx_Instance)){
		.application_name = "Renderer",
		.application_version = gfx_version_make(0, 0, 1),
		.enable_debug = GFX_HAL_DEBUG,
	}, &context);
	assert(instance_init_result == GFX_SUCCESS);
	defer(gfx_instance_deinit());

	gfx_VkPhysicalDeviceProber prober;
	gfx_vkphysicaldeviceprober_make(
		&prober,
		&(descriptor_of(gfx_VkPhysicalDeviceProber)){
			.instance = &singleton_of(gfx_Instance).instance,
		},
		allocator,
		temp_allocator
	);
	gfx_vkphysicaldeviceprober_report(&prober, logger);

	gfx_VkPhysicalDevicePicker picker;
	gfx_vkphysicaldevicepicker_make(&picker, &(descriptor_of(gfx_VkPhysicalDevicePicker)){
		.prober = &prober,
	});

	VkPhysicalDeviceLimits limits = {};
	limits.maxImageDimension1D = 16384;
	limits.maxImageDimension2D = 16384;
	limits.maxImageDimension3D = 2048;
	limits.maxImageDimensionCube = 16384;
	limits.maxImageArrayLayers = 2048;
	limits.maxTexelBufferElements = 134217728;
	limits.maxUniformBufferRange = 65536;
	limits.maxStorageBufferRange = 4294967295;
	limits.maxPushConstantsSize = 128;
	limits.maxMemoryAllocationCount = 4096;
	limits.maxSamplerAllocationCount = 4000;
	limits.bufferImageGranularity = 64;
	limits.sparseAddressSpaceSize = 2147483648;
	limits.maxBoundDescriptorSets = 8;
	limits.maxPerStageDescriptorSamplers = 16;
	limits.maxPerStageDescriptorUniformBuffers = 12;
	limits.maxPerStageDescriptorStorageBuffers = 4;
	limits.maxPerStageDescriptorSampledImages = 16;
	limits.maxPerStageDescriptorStorageImages = 4;
	limits.maxPerStageDescriptorInputAttachments = 4;
	limits.maxPerStageResources = 128;
	limits.maxDescriptorSetSamplers = 16;
	limits.maxDescriptorSetUniformBuffers = 12;
	limits.maxDescriptorSetUniformBuffersDynamic = 8;
	limits.maxDescriptorSetStorageBuffers = 4;
	limits.maxDescriptorSetStorageBuffersDynamic = 4;
	limits.maxDescriptorSetSampledImages = 16;
	limits.maxDescriptorSetStorageImages = 4;
	limits.maxDescriptorSetInputAttachments = 4;
	limits.maxVertexInputAttributes = 32;
	limits.maxVertexInputBindings = 32;
	limits.maxVertexInputAttributeOffset = 2047;
	limits.maxVertexInputBindingStride = 2048;
	limits.maxVertexOutputComponents = 128;
	limits.maxTessellationGenerationLevel = 64;
	limits.maxTessellationPatchSize = 32;
	limits.maxTessellationControlPerVertexInputComponents = 128;
	limits.maxTessellationControlPerVertexOutputComponents = 128;
	limits.maxTessellationControlPerPatchOutputComponents = 120;
	limits.maxTessellationControlTotalOutputComponents = 4096;
	limits.maxTessellationEvaluationInputComponents = 128;
	limits.maxTessellationEvaluationOutputComponents = 128;
	limits.maxGeometryShaderInvocations = 32;
	limits.maxGeometryInputComponents = 64;
	limits.maxGeometryOutputComponents = 128;
	limits.maxGeometryOutputVertices = 256;
	limits.maxGeometryTotalOutputComponents = 1024;
	limits.maxFragmentInputComponents = 128;
	limits.maxFragmentOutputAttachments = 8;
	limits.maxFragmentDualSrcAttachments = 1;
	limits.maxFragmentCombinedOutputResources = 8;
	limits.maxComputeSharedMemorySize = 16384;
	limits.maxComputeWorkGroupCount[0] = 65535;
	limits.maxComputeWorkGroupCount[1] = 65535;
	limits.maxComputeWorkGroupCount[2] = 65535;
	limits.maxComputeWorkGroupInvocations = 128;
	limits.maxComputeWorkGroupSize[0] = 128;
	limits.maxComputeWorkGroupSize[1] = 128;
	limits.maxComputeWorkGroupSize[2] = 64;
	limits.subPixelPrecisionBits = 4;
	limits.subTexelPrecisionBits = 4;
	limits.mipmapPrecisionBits = 4;
	limits.maxDrawIndexedIndexValue = 1048575;
	limits.maxDrawIndirectCount = 1073741824;
	limits.maxSamplerLodBias = 16.0;
	limits.maxSamplerAnisotropy = 16.0;
	limits.maxViewports = 16;
	limits.maxViewportDimensions[0] = 16384;
	limits.maxViewportDimensions[1] = 16384;
	limits.viewportBoundsRange[0] = -32768.0;
	limits.viewportBoundsRange[1] = 32767.0;
	limits.viewportSubPixelBits = 8;
	limits.minMemoryMapAlignment = 64;
	limits.minTexelBufferOffsetAlignment = 16;
	limits.minUniformBufferOffsetAlignment = 256;
	limits.minStorageBufferOffsetAlignment = 256;
	limits.minTexelOffset = -8;
	limits.maxTexelOffset = 7;
	limits.minTexelGatherOffset = -32;
	limits.maxTexelGatherOffset = 31;
	limits.minInterpolationOffset = -0.5;
	limits.maxInterpolationOffset = 0.5;
	limits.subPixelInterpolationOffsetBits = 4;
	limits.maxFramebufferWidth = 16384;
	limits.maxFramebufferHeight = 16384;
	limits.maxFramebufferLayers = 2048;
	limits.framebufferColorSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.framebufferDepthSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.framebufferStencilSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.framebufferNoAttachmentsSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.maxColorAttachments = 8;
	limits.sampledImageColorSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.sampledImageIntegerSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.sampledImageDepthSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.sampledImageStencilSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.storageImageSampleCounts = VK_SAMPLE_COUNT_1_BIT | VK_SAMPLE_COUNT_2_BIT | VK_SAMPLE_COUNT_4_BIT | VK_SAMPLE_COUNT_8_BIT;
	limits.maxSampleMaskWords = 1;
	limits.timestampComputeAndGraphics = VK_TRUE;
	limits.timestampPeriod = 1.0;
	limits.maxClipDistances = 8;
	limits.maxCullDistances = 8;
	limits.maxCombinedClipAndCullDistances = 8;
	limits.discreteQueuePriorities = 2;
	limits.pointSizeRange[0] = 1.0;
	limits.pointSizeRange[1] = 64.0;
	limits.lineWidthRange[0] = 1.0;
	limits.lineWidthRange[1] = 8.0;
	limits.pointSizeGranularity = 0.1;
	limits.lineWidthGranularity = 0.1;
	limits.strictLines = VK_TRUE;
	limits.standardSampleLocations = VK_TRUE;
	limits.optimalBufferCopyOffsetAlignment = 16;
	limits.optimalBufferCopyRowPitchAlignment = 256;
	limits.nonCoherentAtomSize = 256;

	static const VkPhysicalDeviceType ALLOWED_DEVICE_TYPES[] = {
		VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU,
		VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU,
	};
	auto devices = gfx_vkphysicaldevicepicker_rank_devices(
		&picker,
		&(gfx_VkPhysicalDevicePicker_DevicePreferences){
			.allow_uncapable_devices = true,
			.allowed_device_types = slice_from(VkPhysicalDeviceType)((VkPhysicalDeviceType*)(ALLOWED_DEVICE_TYPES), countof(ALLOWED_DEVICE_TYPES)),
			.required_limits = limits,
		},
		temp_allocator,
		allocator
	);

	for (usize i = 0; i < devices.length; i++) {
		log_info(logger, "%ld: %s - %ld", i, devices.data[i].first->properties.deviceName, devices.data[i].second);
	}

	while (!glfwWindowShouldClose(window)) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}

		glfwPollEvents();
		allocator_dealloc_all(context.temp_allocator);
	}

	return 0;
}

