#include "Leg.h"


Leg::Leg(float X, float Y, float Z)
{
	auto verts = SimpleModelLoader::Load("Models/leg.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/leg colours.txt");
	_colours = colours->Data;
	_size = new Vector(0.25f, 1.0f, 0.25f);
	_position = new Vector(X, Y, Z);
}

Leg::Leg(Vector &vec)
{
	auto verts = SimpleModelLoader::Load("Models/leg.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/leg colours.txt");
	_colours = colours->Data;
	_position = new Vector(vec.X, vec.Y, vec.Z);
	_size = new Vector(0.5f, 1.0f, 0.5f);
}

Leg::~Leg()
{
}

void Leg::Draw() const {

	glPushMatrix();
		glTranslatef(_position->X, _position->Y, _position->Z);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
}