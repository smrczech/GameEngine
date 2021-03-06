#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "inputhandler.h"

namespace Engine
{

    enum camMovement
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    #define PI 3.14159265

    class camera
    {
    public:
        glm::vec3 camPos;
        glm::vec3 camFace; //where is the camera facing(to which point in front it) []< ---> * ; | []< * | = 1 - it's normalized
                           //can be visualised as a small point, which camera is facing all the time(that illustration above where * is the point)
        glm::vec3 camUp; //defines the up direction for the camera

        double pitch = 0;
        double yaw = 0;

        camera();
        camera(glm::vec3 pos, glm::vec3 face, glm::vec3 upDir);
        camera(glm::vec3 pos, double pitch, double yaw, glm::vec3 upDir);

        glm::mat4 getViewMat();
        float getFOV() const;

        void rotateCameraMouse(double xpos, double ypos);
        void changeFOVScroll(double xoffset, double yoffset);

        void translateCam(int direction);
    private:
        glm::mat4 viewMat;

        double lastX;
        double lastY;
        bool firstMouse = true;

        float sensitivity = 0.025f;
        float camTranslateSpeed = 2.5f;

        float fov = 45.0f;

        void calcCamFaceFromRot();
        void calcRotFromCamFace();
    };

}
