#ifndef WINDOW_H
#define	WINDOW_H

#include <string>
#include <GLFW/glfw3.h>
class Window {
	public:
		GLFWwindow* window;
    		Window(string title, int width, int height);
		~Window();
	private:
}

#endif
