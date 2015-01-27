#pragma once
#include "Entity.h"

class Table : public Entity
{
public:
	Table();
	~Table();
	void Draw() const override;
	int col;
};

