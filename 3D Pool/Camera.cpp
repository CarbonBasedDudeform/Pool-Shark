#include "Camera.h"

Camera::Camera() : _yaw(0), _pitch(0), _roll(0), _speed(0.5f)
{
	_position = new Vector(0.0f, 15.0f, -10.0f);
	_centreOfTheUniverse.X = 0.0f;
	_centreOfTheUniverse.Y = 1.0f;
	_centreOfTheUniverse.Z = -15.0f;
}


Camera::~Camera()
{
}

void Camera::SetCentreOfTheUniverse(Vector centre)
{
	_centreOfTheUniverse = centre;
}

void Camera::Draw() const {
	glTranslatef(_centreOfTheUniverse.X, _centreOfTheUniverse.Y, _centreOfTheUniverse.Z);
	glRotatef(_yaw, 0.0f, 1.0f, 0.0f);
	glRotatef(_pitch, 1.0f, 0.0f, 0.0f);
	glTranslatef(-_centreOfTheUniverse.X, -_centreOfTheUniverse.Y, -_centreOfTheUniverse.Z);

	gluLookAt(_position->X, _position->Y, _position->Z,
		_centreOfTheUniverse.X, _centreOfTheUniverse.Y, _centreOfTheUniverse.Z,
		0.0f, 1.0f, 0.0f); //up vector
}

void Camera::IncreaseYaw() {
	_yaw += _speed;
}

void Camera::DecreaseYaw() {
	_yaw -= _speed;
}

void Camera::IncreaseRoll() {
	_pitch -= _speed;
}

void Camera::DecreaseRoll() {
	_pitch += _speed;
}

Vector Camera::GetNormalizedDirection() const
{
	Vector v;
	return v;
}