#pragma once
#include "Entity.h"
class Leg :
	public Entity
{
public:
	Leg(RenderSettings);
	Leg(Vector&);
	~Leg();
};

