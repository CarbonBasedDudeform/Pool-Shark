#pragma once
#include "Entity.h"
#include <vector>

class Physics
{
public:
	Physics();
	~Physics();
	void AddEntityToSystem(Entity*);
	void Update(float gameTime);
private:
	std::vector<Entity *> _entities;
};

