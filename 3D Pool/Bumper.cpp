#include "Bumper.h"


Bumper::Bumper()
{
	auto verts = SimpleModelLoader::Load("Models/bumper.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/bumper colours.txt");
	_colours = colours->Data;
	_size = new Vector(0.25f, 1.0f, 0.25f);
	_position = new Vector(0, 0, 0);
}

Bumper::Bumper(RenderSettings settings)
{
	auto verts = SimpleModelLoader::Load(settings.Resource);
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load(settings.Colours);
	_colours = colours->Data;
	_size = new Vector(settings.Scale.X, settings.Scale.Y, settings.Scale.Z);
	_position = new Vector(settings.Position.X, settings.Position.Y, settings.Position.Z);
	_rotation = settings.Rotation;
}

Bumper::Bumper(float X, float Y, float Z, float xScale, float zScale) {
	auto verts = SimpleModelLoader::Load("Models/bumper.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/bumper colours.txt");
	_colours = colours->Data;
	_size = new Vector(xScale, 0.25f, zScale);
	_position = new Vector(X, Y, Z);
}

Bumper::Bumper(Vector & vec, float xScale, float zScale)
{
	auto verts = SimpleModelLoader::Load("Models/bumper.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/bumper colours.txt");
	_colours = colours->Data;
	_position = new Vector(vec.X, vec.Y, vec.Z);
	_size = new Vector(xScale, 1.0f, zScale);
}

Bumper::~Bumper()
{
}