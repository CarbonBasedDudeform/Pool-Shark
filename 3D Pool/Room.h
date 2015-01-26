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
	GLuint * _vbos;

	GLfloat * _colours;
	GLfloat * _vertices;
	float _size;
	
};

