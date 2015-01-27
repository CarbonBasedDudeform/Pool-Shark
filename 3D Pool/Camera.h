#pragma once
#include "IDrawable.h"

class Camera : public IDrawable
{
public:
	Camera();
	~Camera();
	Vector * Position;
	void Draw() const override;
	void IncreaseYaw();
	void DecreaseYaw();
	void IncreaseRoll();
	void DecreaseRoll();

private:
	float _speed; //speed at which camera rotates

	float _yaw;
	float _pitch;
	float _roll;
};

