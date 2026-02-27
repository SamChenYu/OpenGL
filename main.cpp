#include <iostream>
#include <glad/glad.hpp>
#include <GLFW/glfw3.hpp>

using namespace std;


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// Resize window callback function
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


int main() {

	// Instantiate GLFW window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// GLAD manages function pointers for OpenGL
	// GLAD initialization
	// Pass GLAD the function to load the address of the OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Tell OpenGL the size of the rendering window
	// E.g. transforming screen coordinates to normalized device coordinates
	glViewport(0, 0, 800, 600);

	// Callback function for resizing window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Rendering loop
	while (!glfwWindowShouldClose(window)) {

		// user input
		processInput(window);


		// rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // state setting function
		glClear(GL_COLOR_BUFFER_BIT); // state using function
		
		// check and call events and swap the buffers
		glfwSwapBuffers(window); // swap the color buffer (double buffer)
								 // front buffer: what is currently being displayed
								 // back buffer: what is being rendered
		glfwPollEvents(); // anything like I/O
	}


	glfwTerminate(); // clean up resources
	return 0;
}

