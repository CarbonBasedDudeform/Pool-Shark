#include "Room.h"

Room::Room()
{
	//Load vertices from file
	_vertices = SimpleModelLoader::Load("Models/room.txt");
	_colours = SimpleModelLoader::Load("Models/room colours.txt");
	_position = new Vector();
	_size = new Vector(10.0f, 5.0f, 10.0f);
}


Room::~Room()
{
}

void Room::Draw() const {
	//glLoadIdentity();
	glPushMatrix();
		glTranslatef(_position->X, _position->Y, _position->Z);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, NUM_OF_VERTICES);
	glPopMatrix();
}