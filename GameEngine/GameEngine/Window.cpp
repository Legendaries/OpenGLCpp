#include "Window.h"
#include <string>

Window::Window(char title[], int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;
}

Window::~Window() {
	//Close OpenGL window and terminate GLFW  
	glfwDestroyWindow(id);
	//Finalize and clean up GLFW  
	glfwTerminate();
}

bool Window::init() {
	//Initialize GLFW  
	if (!glfwInit())
		return false;

	id = glfwCreateWindow(width, height, title, NULL, NULL);

	//If the window couldn't be created  
	if (!id) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return false;
	}

	//This function makes the context of the specified window current on the calling thread.   
	glfwMakeContextCurrent(id);

	//Sets the key callback  
	glfwSetKeyCallback(id, key_callback);

	//Set a background color  
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	return true;
}

bool Window::isCloseRequested() {
	return (glfwWindowShouldClose(id) == 1);
}

void Window::clear() const {
	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() const {
	glfwSwapBuffers(id);
	//Get and organize events, like keyboard and mouse input, window resizing, etc...  
	glfwPollEvents();
}

//Define the key input callback
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}