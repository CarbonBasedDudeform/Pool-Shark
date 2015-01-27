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


Vector::~Vector()
{
}
