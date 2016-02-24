#include <Window.h>
#include <string>
#include <GLFW/glfw3.h>

Window(string title, int width, int height) {   
	window = glfwCreateWindow(width, height, title, NULL, NULL);
}

~Window() {
	glfwDestroyWindow(window); 
}
