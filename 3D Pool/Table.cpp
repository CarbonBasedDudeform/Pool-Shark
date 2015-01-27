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
	_legs->push_back(new Leg(1.0f, 0.0f, 0.0f));
	_legs->push_back(new Leg(-1.0f, 0.0f, 0.0f));
	_legs->push_back(new Leg(1.0f, 0.0f, -1.0f));
	_legs->push_back(new Leg(-1.0f, 0.0f, -1.0f));

}


Table::~Table()
{
}


void Table::Draw() const {
	for (auto iter = _legs->begin(); iter != _legs->end(); iter++)
	{
		(*iter)->Draw();
	}

	glPushMatrix();
		glTranslatef(_position->X, _position->Y, _position->Z);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
	
}