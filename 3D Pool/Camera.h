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
	
	//min and max for camera control, these give the user a nice feel but don't allow them to go too low where culling makes the table disappear
	//the maximum is just to add a little realism (it's very peculiar for a pool player to take a shot from standing on the ceiling, or to do a flip over the table to get to the other side -- usually they walk around
	const int MINIMUM_ROLL = -20;
	const int MAXIMUM_ROLL = 90;

	float _yaw;
	float _pitch;
	float _roll;
};

