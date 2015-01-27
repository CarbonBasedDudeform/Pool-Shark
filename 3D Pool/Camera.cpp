#include "Camera.h"

Camera::Camera()
{
	Position = new Vector(0.0f, -2.0f, -20.0f);
	_yaw = _pitch = _roll = 0.0f;
}


Camera::~Camera()
{
}

void Camera::Draw() const {
	glTranslatef(Position->X, Position->Y, Position->Z);
	glRotatef(_roll, 1.0f, 0.0f, 0);
	glRotatef(_yaw, 0.0f, 1.0f, 0);
	glRotatef(_pitch, 0.0f, 0.0f, 1.0f);
}