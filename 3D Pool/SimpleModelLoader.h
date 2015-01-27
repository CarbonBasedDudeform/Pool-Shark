/*
	==============SUMMARY==============
	Loads the vertices of models in a 
	simple format.
	file are .simple and laid out as
	such:
	first line: number of vertices
	rest: vertices seperated by spaces

	eg.
	9
	1 0 0 -1 0 0 0 1 0
*/

#pragma once
#include <Windows.h>
#include <GL\GL.h>
#include <fstream>

class SimpleModel
{
public:
	SimpleModel() { };
	~SimpleModel() { /*potential dangling pointer (data), objects getting this class should take care of it though */ };
	GLfloat * Data;
	int Amount;
};

class SimpleModelLoader
{
public:
	static SimpleModel * Load(char * file);
private:
	SimpleModelLoader();
	~SimpleModelLoader();
};


