#include "Bumper.h"


Bumper::Bumper()
{
	auto verts = SimpleModelLoader::Load("Models/leg.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/leg colours.txt");
	_colours = colours->Data;
	_size = new Vector(0.25f, 1.0f, 0.25f);
	_position = new Vector(0, 0, 0);
}

Bumper::Bumper(float X, float Y, float Z, float xScale, float zScale) {
	auto verts = SimpleModelLoader::Load("Models/leg.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/leg colours.txt");
	_colours = colours->Data;
	_size = new Vector(xScale, 0.25f, zScale);
	_position = new Vector(X, Y, Z);
}

Bumper::Bumper(Vector & vec, float xScale, float zScale)
{
	auto verts = SimpleModelLoader::Load("Models/leg.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/leg colours.txt");
	_colours = colours->Data;
	_position = new Vector(vec.X, vec.Y, vec.Z);
	_size = new Vector(xScale, 1.0f, zScale);
}


Bumper::~Bumper()
{
}