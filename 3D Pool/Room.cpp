#include "Room.h"


Room::Room()
{
	//Initialise vertex array
	_vertices = new GLfloat[NUM_OF_VERTICES] {
		1.0f, 0.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f
	};
}


Room::~Room()
{
}


void Room::Draw() const {
	//needs to be updated to use VBOs
	glVertexPointer(3, GL_FLOAT, 0, _vertices);
	glDrawArrays(GL_TRIANGLES, 0, NUM_OF_VERTICES);
}