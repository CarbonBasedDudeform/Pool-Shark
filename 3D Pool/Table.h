#pragma once
#include "Entity.h"
#include <vector>
#include "Leg.h"
#include "Bumper.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Table : public Entity
{
public:
	Table(RenderSettings);
	~Table();
	void Draw() const override;
private:
	void LoadLegs();
	void LoadBumpers();

	std::vector<Leg *> * _legs;
	std::vector<Bumper *> * _bumpers;
};

