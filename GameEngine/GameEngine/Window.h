#pragma once

#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 16

class Window {
private:
	GLFWwindow* id;
	char* title;
	int width, height;

	static bool keys[MAX_KEYS];
	static bool mouse[MAX_BUTTONS];
public:
	Window(char title[], int width, int height);
	~Window();
	bool init();
	bool isCloseRequested();
	void clear() const;
	void update() const;
	static friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
};
