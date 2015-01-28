#pragma once
#include "Entity.h"

class Bumper : public Entity
{
public:
	Bumper();
	Bumper(float, float, float, float, float);
	Bumper(Vector &, float, float);
	~Bumper();
};

