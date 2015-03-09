#pragma once
#include "Entity.h"
#include <deque>

class BallRenderSettings : public RenderSettings
{
public:
	float Radius;
};

class Ball : public Entity
{
public:
	Ball(BallRenderSettings);
	~Ball();
private:
	SimpleModel * Generate(SimpleModel*);
	float _radius;
};

