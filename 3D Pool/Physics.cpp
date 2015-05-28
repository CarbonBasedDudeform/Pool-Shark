#include "Physics.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

void Physics::AddEntityToSystem(Entity * entity) {
	_entities.push_back(entity);
}

#include <iostream>
void Physics::Update(float gameTime)
{
	//de nada
	std::cout << gameTime << std::endl;
}