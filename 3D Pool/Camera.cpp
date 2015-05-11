#include "Camera.h"

Camera::Camera() : _yaw(0), _pitch(0), _roll(0), _speed(0.5f)
{
	_position = new Vector(0.0f, 15.0f, -10.0f);
}


Camera::~Camera()
{
}

void Camera::Draw() const {
	//to hell with eulers theorem
	glTranslatef(0.0f, 1.0f, -15.0f);
	glRotatef(_yaw, 0.0f, 1.0f, 0.0f);
	glRotatef(_pitch, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, -1.0f, 15.0f);

	gluLookAt(_position->X, _position->Y, _position->Z,
		0.0f, 1.0f, -15.0f,
		0.0f, 1.0f, 0.0f);
}

void Camera::IncreaseYaw() {
	_yaw += _speed;
	//_position->X += _speed;
}

void Camera::DecreaseYaw() {
	_yaw -= _speed;
	//_position->X -= _speed;
}

void Camera::IncreaseRoll() {
	//if (_roll < MAXIMUM_ROLL) _roll += _speed;
	//_position->Z += _speed;
	_pitch -= _speed;
}

void Camera::DecreaseRoll() {
	//if (_roll > MINIMUM_ROLL) _roll -= _speed;
	//_position->Z -= _speed;
	_pitch += _speed;
}

Vector Camera::GetNormalizedDirection() const
{
	Vector v;
	return v;
}