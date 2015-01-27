#include "Room.h"

Room::Room()
{
	_size = 5.0f;
	//Load vertices from file
	_vertices = SimpleModelLoader::Load("Models/room.txt");
	_colours = SimpleModelLoader::Load("Models/room colours.txt");

}


Room::~Room()
{
}

void Room::Draw() const {
	//glLoadIdentity();
	glPushMatrix();
		glScalef(_size, _size, _size);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, NUM_OF_VERTICES);
	glPopMatrix();
}