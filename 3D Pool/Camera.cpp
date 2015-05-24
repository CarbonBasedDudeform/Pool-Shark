#include "Camera.h"

Camera::Camera() : _yaw(0), _pitch(0), _roll(0), _speed(0.5f)
{
	_position = new Vector(0.0f, 10.0f, -10.0f);
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
	*_position = _centreOfTheUniverse;
	_position->Z -= 10;
	_position->Y += 10;
}

void Camera::Draw() const {

	gluLookAt(_position->X, _position->Y, _position->Z,
		_centreOfTheUniverse.X, _centreOfTheUniverse.Y, _centreOfTheUniverse.Z,
		0.0f, 1.0f, 0.0f); //up vector

	glTranslatef(_centreOfTheUniverse.X, _centreOfTheUniverse.Y, _centreOfTheUniverse.Z);
	glRotatef(_yaw, 0.0f, 1.0f, 0.0f);
	glRotatef(_pitch, 1.0f, 0.0f, 0.0f);
	glTranslatef(-_centreOfTheUniverse.X, -_centreOfTheUniverse.Y, -_centreOfTheUniverse.Z);
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
	Vector direction;
	
	//problem, the position is different to the displayed position as the displayed position undergoes the rotation matrix transformation, so this gives a false value and the rest of the code doesn't work correctly
	//to fix this using a hacky 2D rotation matrix to create a temp vector which allows for the rest of the math to work.
	Vector temp;
	float rads = _yaw * (3.1428f / 180.0f);
	temp.X = (*_position).X * (cos(rads)) + (*_position).Y * -(sin(rads));
	temp.Z = (*_position).X * (sin(rads)) + (*_position).Y * (cos(rads));
	temp.Y = (*_position).Y;
	
	//substract the centre of the universe from the positon to get a vector going from the centre of the universe to the position
	direction = temp - _centreOfTheUniverse;
	//flip that vector
	direction *= -1;
	//normalize that bitch
	direction.Normalize();
	//just going to have 2D physics for now, so ignoring the Y axis
	direction.Y = 0;
	 
	return direction;
}