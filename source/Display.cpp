#include "Display.h"
#include <memory>
#include <iostream>

// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

namespace Display {
	constexpr static int WIDTH = 800;
	constexpr static int HEIGHT = 600;

	GLFWwindow* window;

	bool keys[1024];
	
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	void init()
	{
		std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
		// Init GLFW
		glfwInit();
		// Set all the required options for GLFW
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "Cool Engine", nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_callback);

		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW" << std::endl;
		}

		glViewport(0, 0, WIDTH, HEIGHT);
	}
	void close()
	{
		glfwTerminate();
	}
	bool shouldClose() 
	{
		return glfwWindowShouldClose(window);
	}
	void clear()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		if (key >= 0 && key < 1024)
		{
			if (action == GLFW_PRESS)
				keys[key] = true;
			else if (action == GLFW_RELEASE)
				keys[key] = false;
		}
	}
}
