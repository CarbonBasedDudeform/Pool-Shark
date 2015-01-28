#pragma once
class Vector
{
public:
	Vector();
	Vector(float, float, float);
	Vector(float);
	Vector(Vector &);
	~Vector();
	float X;
	float Y;
	float Z;
};

