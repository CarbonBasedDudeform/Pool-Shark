#pragma once
#include "Entity.h"
#include <vector>
#include "Leg.h"

class Table : public Entity
{
public:
	Table();
	~Table();
	void Draw() const override;
private:
	//std::vector<Leg *> * _legs;
	Leg * leg1;
	Leg * leg2;
	Leg * leg3;
	Leg * leg4;
	Leg * leg5;
};

