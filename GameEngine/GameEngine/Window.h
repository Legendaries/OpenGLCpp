#include <string>
#include <GLFW/glfw3.h>
class Window {
  public:
    GLFWwindow* window;
    inline Window(string title, int width, int height) {
      window = glfwCreateWindow(width, height, title, NULL, NULL);
    }
    inline ~Window() {
      glfwDestroyWindow(window); 
    }
  private:
}
