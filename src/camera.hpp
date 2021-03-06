#ifndef CAMERA_H
#define CAMERA_H

#include "window.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

class FPCamera {
public:
  FPCamera(Window const &window,
           glm::vec3 const &position,
           glm::vec3 const &lookAt,
           float sensitivity,
           float speed);
  FPCamera(Window const &window,
           glm::vec3 const &position,
           glm::vec3 const &lookAt,
           float sensitivity);
  FPCamera(Window const &window, glm::vec3 const &position, glm::vec3 const &lookAt);
  FPCamera(Window const &window, glm::vec3 const &position, float sensitivity, float speed);
  FPCamera(Window const &window, glm::vec3 const &position, float sensitivity);
  FPCamera(Window const &window, glm::vec3 const &position);
  FPCamera(Window const &window, float sensitivity, float speed);
  FPCamera(Window const &window, float sensitivity);
  FPCamera(Window const &indow);
  void update();
  glm::mat4 viewMatrix();

  glm::vec3 position;
  float sensitivity;
  float speed;

private:
  Window const &window;
  float verticalAngle;
  float horizontalAngle;
};

#endif