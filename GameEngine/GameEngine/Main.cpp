//Include GLFW  
#include <GL\glew.h>
#include <GLFW/glfw3.h>  

#include "Window.h"

//Include the standard C++ headers  
#include <stdio.h>  
#include <stdlib.h> 

//Define an error callback  
static void error_callback(int error, const char* description) {
	fputs(description, stderr);
	_fgetchar();
}

int main(void) {
	//Set the error callback  
	glfwSetErrorCallback(error_callback);

	//Set the GLFW window creation hints - these are optional  
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version  
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version  
	//glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing  
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  

	//Declare a window object
	Window window ("Test", 1280, 720);

	if (!window.init())
		return -1;

	
	//Main Loop  
	do {
		window.clear();

		glBegin(GL_QUADS);
		glVertex2f(0.0, 0.0); glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0.0, 1.0); glColor3f(1.0, 1.0, 0.0);
		glVertex2f(1.0, 1.0); glColor3f(1.0, 0.0, 1.0);
		glVertex2f(1.0, 0.0);
		glEnd();

		window.update();
	} while (!window.isCloseRequested());

	exit(EXIT_SUCCESS);
}
