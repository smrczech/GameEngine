#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine
{
    bool processInput(GLFWwindow* window, int key);

    void closeWindow(GLFWwindow* window);
}
