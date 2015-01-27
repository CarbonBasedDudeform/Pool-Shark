#include "Table.h"

#include <iostream>
Table::Table()
{
	auto verts = SimpleModelLoader::Load("Models/table.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/table colours.txt");
	_colours = colours->Data;
	col = colours->Amount;
	_position = new Vector(0.0f, 1.0f, -1.0f);
	_size = new Vector(2.0f, 1.0f, 4.0f);
}


Table::~Table()
{
}


void Table::Draw() const {
	//glCullFace(GL_FRONT_AND_BACK);
	

	glPushMatrix();
		glTranslatef(_position->X, _position->Y, _position->Z);
		glScalef(_size->X, _size->Y, _size->Z);
		//glRotatef(-70.5f, 1.0f, 0.0f, 0.0f);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
	//glCullFace(GL_BACK);
}