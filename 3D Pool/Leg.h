#pragma once
#include "Entity.h"
class Leg :
	public Entity
{
public:
	Leg(float, float, float);
	Leg(Vector&);
	~Leg();
	void Draw() const override;
};

