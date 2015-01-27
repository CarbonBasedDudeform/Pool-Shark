#include "Camera.h"

Camera::Camera()
{
	Position = new Vector(0.0f, -2.0f, -2.0f);
}


Camera::~Camera()
{
}

void Camera::Draw() const {
	glTranslatef(Position->X, Position->Y, Position->Z);
}