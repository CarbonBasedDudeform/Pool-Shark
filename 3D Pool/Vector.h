#pragma once
#include <math.h>

class Vector
{
public:
	Vector();
	Vector(float, float, float);
	Vector(float);
	Vector(const Vector &);
	~Vector();
	float X;
	float Y;
	float Z;

	void Normalize();
	float Length() const;

	Vector operator/(float rhs) {
		Vector lhs;
		lhs.X = this->X / rhs;
		lhs.Y = this->Y / rhs;
		lhs.Z = this->Z / rhs;
		return lhs;
	};

	Vector& operator/=(float rhs)
	{
		this->X /= rhs;
		this->Y /= rhs;
		this->Z /= rhs;

		return (*this);
	}

	Vector operator*(float rhs)
	{
		Vector lhs;
		lhs.X = this->X * rhs;
		lhs.Y = this->Y * rhs;
		lhs.Z = this->Z * rhs;
		return lhs;
	};

	Vector& operator*=(float rhs)
	{
		this->X *= rhs;
		this->Y *= rhs;
		this->Z *= rhs;

		return (*this);
	}

	Vector operator+(Vector rhs)
	{
		Vector lhs;
		lhs.X = this->X + rhs.X;
		lhs.Y = this->Y + rhs.Y;
		lhs.Z = this->Z + rhs.Z;

		return lhs;
	}

	Vector& operator+=(Vector rhs)
	{
		this->X += rhs.X;
		this->Y += rhs.Y;
		this->Z += rhs.Z;

		return (*this);
	}

	Vector operator-(Vector rhs)
	{
		Vector lhs;
		lhs.X = this->X - rhs.X;
		lhs.Y = this->Y - rhs.Y;
		lhs.Z = this->Z - rhs.Z;

		return lhs;
	}

	Vector& operator-=(Vector rhs)
	{
		this->X -= rhs.X;
		this->Y -= rhs.Y;
		this->Z -= rhs.Z;

		return (*this);
	}
};