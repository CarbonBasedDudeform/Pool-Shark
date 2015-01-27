#include "Table.h"


Table::Table()
{
	_vertices = SimpleModelLoader::Load("Models/room.txt");
	_colours = SimpleModelLoader::Load("Models/room colours.txt");
	_position = new Vector(1.0f, 1.0f, -2.0f);
	_size = new Vector(1.0f, 1.0f, 1.0f);
}


Table::~Table()
{
}

void Table::Draw() const {
	glPushMatrix();
		glTranslatef(_position->X, _position->Y, _position->Z);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, 108);
	glPopMatrix();
}