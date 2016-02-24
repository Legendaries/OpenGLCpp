#include <Window.h>

Window(string title, int width, int height) {   
	window = glfwCreateWindow(width, height, title, NULL, NULL);
}

~Window() {
	glfwDestroyWindow(window); 
}
