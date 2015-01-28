#include "Leg.h"


Leg::Leg(RenderSettings settings)
{
	auto verts = SimpleModelLoader::Load(settings.Resource);
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load(settings.Colours);
	_colours = colours->Data;
	_size = new Vector(settings.Scale);
	_position = new Vector(settings.Position);
	_rotation = settings.Rotation;
}

Leg::Leg(Vector &vec)
{
	auto verts = SimpleModelLoader::Load("Models/leg.txt");
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load("Models/leg colours.txt");
	_colours = colours->Data;
	_position = new Vector(vec.X, vec.Y, vec.Z);
	_size = new Vector(0.5f, 1.0f, 0.5f);
}

Leg::~Leg()
{
}