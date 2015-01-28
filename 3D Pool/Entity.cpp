#include "Entity.h"


Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Draw() const {
	glPushMatrix();
	glTranslatef(_position->X, _position->Y, _position->Z);
	glScalef(_size->X, _size->Y, _size->Z);
	glColorPointer(3, GL_FLOAT, 0, _colours);
	glVertexPointer(3, GL_FLOAT, 0, _vertices);
	glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
}