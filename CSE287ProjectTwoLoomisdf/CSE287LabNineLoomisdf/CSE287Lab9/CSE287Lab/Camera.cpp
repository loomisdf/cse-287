#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up) 
{
	viewTrans = glm::lookAt(position, position + direction, up);
}

void Camera::setPositionDirectionUp(glm::vec3 position, glm::vec3 direction, glm::vec3 up)
{
	viewTrans = glm::lookAt(position, direction, up);
}

glm::vec3 Camera::getWorldCoordinateViewPosition()
{
	return glm::inverse(viewTrans)[3].xyz;
}

glm::mat4 Camera::getViewingTransformation()
{
	return viewTrans;
}