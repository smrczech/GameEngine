#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Engine
{
    class shader
    {
    public:
        unsigned int ID; //the program ID

        //constructor reads and builds the shader
        shader(const GLchar* vertexPath, const GLchar* fragmentPath);

        //use/active the shader
        void use();
        //uniform functions
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        void setMat4(const std::string &name, glm::mat4 value) const;


    };
}
