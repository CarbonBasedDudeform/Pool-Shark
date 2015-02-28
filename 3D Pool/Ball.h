#pragma once
#include "Entity.h"
#include <deque>

class Ball : public Entity
{
public:
	Ball(RenderSettings);
	~Ball();
private:
	SimpleModel * Generate(SimpleModel*);
	float _radius;
};

