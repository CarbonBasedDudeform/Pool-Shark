#include "Vector.h"

//Sets XYZ all to 0;
Vector::Vector()
{
	X = Y = Z = 0;
}

Vector::Vector(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z; 
}

//Sets the XYZ valuse to a uniform value. IE. Vector(7) => X = 7, Y = 7, Z = 7
Vector::Vector(float uniform)
{
	X = Y = Z = uniform;
}

//yay copy constructor
Vector::Vector(const Vector & copy) : X(copy.X), Y(copy.Y), Z(copy.Z) {}

Vector::~Vector()
{
}

//calculates the length or magnitude of this vector
float Vector::Length() const {
	//sqrt of x^2 + y^2 + z^2
	float x_sqrd = X*X;
	float y_sqrd = Y*Y;
	float z_sqrd = Z*Z;

	return sqrtf(x_sqrd + y_sqrd + z_sqrd);
}

//Normalizes the X,Y,Z of this vector
void Vector::Normalize()
{
	float length = Length();
	X /= length;
	Y /= length;
	Z /= length;
}