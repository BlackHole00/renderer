#include <stdio.h>
#include <assert.h>

#include <std/std.h>
#include <glfw/glfw3.h>
#include <vulkan/vulkan.h>
#include <gfx/hal/instance.h>

int main(void) {
	printf("Hello world!\n");

	int* c = new(int, singleton_of(SystemAllocator));
	delete(c, singleton_of(SystemAllocator));

	Vector(int) v = vector_make_with_capacity(int)(256, singleton_of(SystemAllocator));
	v[255] = 10;
	vector_destroy(int)(v);

	Slice(byte) b;

	glfwInit();
	
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	auto window = glfwCreateWindow(640, 480, "Renderer", nullptr, nullptr);

	while (!glfwWindowShouldClose(window)) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}

		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

