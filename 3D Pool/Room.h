#pragma once
#include "IDrawable.h"
#include "SimpleModelLoader.h"

class Room : public IDrawable
{
public:
	Room();
	~Room();

	//IDrawable overide
	void Draw() const override;
private:
	const int NUM_OF_VERTICES = 108;

	GLfloat * _colours;
	GLfloat * _vertices;

	Vector * _position;
	Vector * _size;
};

