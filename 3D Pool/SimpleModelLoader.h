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

class SimpleModelLoader
{
public:
	SimpleModelLoader();
	~SimpleModelLoader();
};

