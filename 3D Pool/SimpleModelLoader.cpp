#include "SimpleModelLoader.h"

#include <iostream>
SimpleModel * SimpleModelLoader::Load(char * file)
{
	std::ifstream input;
	input.open(file);

	int number_of_vertices = 0;
	input >> number_of_vertices;

	GLfloat * verts_array = new GLfloat[number_of_vertices];

	GLfloat temp;

	for (int i = 0; i <= number_of_vertices; ++i)
	{
		input >> temp;
		verts_array[i] = (GLfloat)temp;
	}
	SimpleModel * obj = new SimpleModel();
	obj->Data = verts_array;
	obj->Amount = number_of_vertices/3;
	return obj;
}

//Private, not supposed to be able to initiate a class of this type
SimpleModelLoader::SimpleModelLoader()
{
}


SimpleModelLoader::~SimpleModelLoader()
{
}
