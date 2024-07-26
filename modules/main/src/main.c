#include <assert.h>

#include <std/std.h>
#include <vulkan/vulkan.h>
#include <glfw/glfw3.h>
#include <gfx/hal/instance.h>

void show_banner(Logger logger) {
	log_info(logger, "Renderer - v.0.0.1");
	log_info(logger, "\tby Vicix");
}

static inline void slice_sort_elements(usize)(Slice(usize) slice) {
	usize start = slice.length / 2;
	usize end = slice.length;
	while (end > 1) {
		if (start > 0) {
			start--;
		} else {
			end--;
			swap(&slice.data[end], &slice.data[0]);
		}
		usize root = start;
		usize left_child = (2 * root) + 1;
		while (left_child < end) {
			usize child = left_child;
			if ((child + 1 < end) && 
				(usize_scalar_comparator(&slice.data[child], &slice.data[child + 1]) < 0)
			) {
				child = child + 1;
			}
			if (usize_scalar_comparator(&slice.data[root], &slice.data[child]) < 0) {
				swap(&slice.data[root], &slice.data[child]);
				root = child;
			} else {
				break;
			}
		}
	}
}

int main(void) {
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

	usize AAAA[] = {
		10, 2, 3, 5, 6, 8, 9, 1, 0
	};
	auto s = slice_from(usize)(&AAAA[0], countof(AAAA));
	slice_sort_elements(usize)(s);
	for (usize i = 0; i < s.length; i++) {
		log_error(logger, "%ld: %ld", i, s.data[i]);
	}

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
		.enable_debug = BUILDER_DEBUG
	}, &context);
	assert(instance_init_result == GFX_SUCCESS);
	defer(gfx_instance_deinit());

	while (!glfwWindowShouldClose(window)) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}

		glfwPollEvents();
		allocator_dealloc_all(context.temp_allocator);
	}

	return 0;
}

