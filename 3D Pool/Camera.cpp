#include "Camera.h"

Camera::Camera()
{
	_position = new Vector(0.0f, -2.0f, 0.0f);
	_yaw = _pitch = _roll = 0.0f;
	_speed = 0.5f;
}


Camera::~Camera()
{
}

void Camera::Draw() const {
	glTranslatef(_position->X, _position->Y, _position->Z);
	glRotatef(_roll, 1.0f, 0.0f, 0);
	glRotatef(_yaw, 0.0f, 1.0f, 0);
	glRotatef(_pitch, 0.0f, 0.0f, 1.0f);
}

void Camera::IncreaseYaw() {
	_yaw += _speed;
}

void Camera::DecreaseYaw() {
	_yaw -= _speed;
}

void Camera::IncreaseRoll() {
	if (_roll < MAXIMUM_ROLL) _roll += _speed;
}

void Camera::DecreaseRoll() {
	if (_roll > MINIMUM_ROLL) _roll -= _speed;
}
