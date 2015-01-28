#include "Table.h"

#include <iostream>
Table::Table()
{
	auto verts = SimpleModelLoader::Load("Models/table.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/table colours.txt");
	_colours = colours->Data;
	_position = new Vector(0.0f, 1.0f, -1.0f);
	_size = new Vector(2.0f, 1.0f, 4.0f);

	_legs = new std::vector<Leg *>();
	//four legs on a table
	_legs->push_back(new Leg(0.75f, 0.0f, -1.0f)); //1 is the size of the leg, moving it back 1 to align the edge of the leg with the edge of the table, 0.75f to inset the legs a bit
	_legs->push_back(new Leg(-0.75f, 0.0f, -1.0f));
	_legs->push_back(new Leg(0.75f, 0.0f, (-1.0f)*_size->Z - 0.25f));
	_legs->push_back(new Leg(-0.75f, 0.0f, (-1.0f)*_size->Z - 0.25f));

	_bumpers = new std::vector<Bumper *>();
	_bumpers->push_back(new Bumper(0.0f, 1.0f, -1.0f, _size->X - 0.25f, _size->Z)); //front bumper
	_bumpers->push_back(new Bumper(-1.0f, 1.0f, -1.0f, 0.25f, _size->Z)); //left bumper
	_bumpers->push_back(new Bumper(1.0f, 1.0f, -1.0f, 0.25f, _size->Z)); //right bumper
	_bumpers->push_back(new Bumper(0.0f, 1.0f, -1.0f + (-1.0f*_size->Z), _size->X - 0.25f, _size->Z)); //back bumper
}


Table::~Table()
{
}


void Table::Draw() const {
	//Draw Legs
	for (auto iter = _legs->begin(); iter != _legs->end(); iter++)
	{
		(*iter)->Draw();
	}

	//Draw green table top
	glPushMatrix();
		glTranslatef(_position->X, _position->Y, _position->Z);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
	
	//Draw bumpers
	for (auto iter = _bumpers->begin(); iter != _bumpers->end(); iter++)
	{
		(*iter)->Draw();
	}
}