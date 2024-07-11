#include <assert.h>

#include <std/std.h>
#include <vulkan/vulkan.h>
#include <glfw/glfw3.h>
#include <gfx/hal/instance.h>

int main(void) {
	Allocator allocator = singleton_of(SystemAllocator);

	Logger logger = consolelogger_make(LOG_LEVEL_TRACE, allocator);

	logger_warn(logger, "Hello World! %d %f", 10, 10.0f);

	// int* c = new(int, allocator);
	// delete(c, allocator);

	// glfwInitVulkanLoader(vkGetInstanceProcAddr);
	// glfwInit();
	// defer(glfwTerminate());
	
	// glfwWindowHint(GLFW_RESIZABLE, false);
	// glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	// auto window = glfwCreateWindow(640, 480, "Renderer", nullptr, nullptr);
	// defer(glfwDestroyWindow(window));

	// gfx_Result instance_init_result = gfx_instance_init(&(descriptor_of(gfx_Instance)){
	// 	.application_name = "Renderer",
	// 	.application_version = VK_MAKE_VERSION(0, 0, 1),
	// 	.enable_debug = true
	// }, allocator);
	// assert(instance_init_result == GFX_SUCCESS);
	// defer(gfx_instance_deinit());

	// while (!glfwWindowShouldClose(window)) {
	// 	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
	// 		glfwSetWindowShouldClose(window, true);
	// 	}

	// 	glfwPollEvents();
	// }

	return 0;
}

