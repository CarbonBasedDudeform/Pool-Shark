#pragma once
#include "IDrawable.h"
#include "SFML/OpenGL.hpp"
#include "SimpleModelLoader.h"

class Room : public IDrawable
{
public:
	Room();
	~Room();

	//IDrawable overide
	void Draw() const override;
private:
	const int NUM_OF_VERTICES = 9;
	GLfloat * _vertices;
};

