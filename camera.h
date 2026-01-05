#pragma once

#include <glm/glm.hpp>

struct GLFWwindow;

class Camera
{
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f));

    glm::mat4 getViewMatrix() const;
    void processInput(GLFWwindow* window, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    glm::vec3 getPosition() const { return position; }
    glm::vec3 getFront() const { return front; }

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;
    float movementSpeed;
    float mouseSensitivity;

    void updateCameraVectors();
};
