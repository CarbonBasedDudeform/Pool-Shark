#pragma once
#include "Entity.h"

class Room : public Entity
{
public:
	Room();
	~Room();

	//IDrawable overide
	void Draw() const override;
};

