#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>

int main(int, char**){
  GLFWwindow* window;

  if (!glfwInit()){
    return -1;
  }

  window = glfwCreateWindow(640, 480, "Window!", NULL, NULL);
  glfwMakeContextCurrent(window);
  
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout << "Couldn't load opengl!" << std::endl;
    glfwTerminate();
    return -1;
  }

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
 
  int colour = 0;
  while (!glfwWindowShouldClose(window)){
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(colour, colour,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0, 0.5);
    glEnd();
  
    if (colour >= 255){
      colour--;
    }else{
      colour++;
    }

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}
