#include "Leg.h"


Leg::Leg(float X, float Y, float Z)
{
	auto verts = SimpleModelLoader::Load("Models/room.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/room colours.txt");
	_colours = colours->Data;
	_position = new Vector(X, Y, Z);
	_size = new Vector(1.0f, 1.0f, 1.0f);
}

Leg::Leg(Vector &vec)
{
	auto verts = SimpleModelLoader::Load("Models/room.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/room colours.txt");
	_colours = colours->Data;
	_position = new Vector(vec.X, vec.Y, vec.Z);
	_size = new Vector(1.0f, 10.0f, 1.0f);
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