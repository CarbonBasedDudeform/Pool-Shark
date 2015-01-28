#pragma once
#include "Entity.h"
#include <vector>
#include "Leg.h"
#include "Bumper.h"

class Table : public Entity
{
public:
	Table();
	~Table();
	void Draw() const override;
private:
	std::vector<Leg *> * _legs;
	std::vector<Bumper *> * _bumpers;
};

