#pragma once
#include "IDrawable.h"
#include "SimpleModelLoader.h"

class RenderSettings {
public:
	RenderSettings() {};
	~RenderSettings() {};
	Vector Position;
	Vector Scale;
	float Rotation;
	char * Resource;
	char * Colours;
};

/*
	An Entity is a Drawable object with a "physical" presence.
	Ie. a table, a chair, a rock band are entities
	a song and a camera (in the opengl sense...) are not.
*/
class Entity : public IDrawable
{
public:
	Entity();
	virtual ~Entity();
	virtual void Draw() const override;
protected:
	GLfloat * _colours;
	GLfloat * _vertices;

	int num_of_verts;

	Vector * _position;
	Vector * _size;
	float _rotation;
};

