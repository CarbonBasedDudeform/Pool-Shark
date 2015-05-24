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
		glRotatef(_rotation, 0, 1.0f, 0);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
}

void Entity::Move(Vector offset) {
	*_position += offset;
}

Vector Entity::GetPosition() const {
	return *_position;
}