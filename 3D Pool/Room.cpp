#include "Room.h"

Room::Room(RenderSettings settings)
{
	//Load vertices from file
	auto verts = SimpleModelLoader::Load(settings.Resource);
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load(settings.Colours);
	_colours = colours->Data;
	_rotation = settings.Rotation;

	_position = new Vector(settings.Position);
	_size = new Vector(settings.Scale);
}


Room::~Room()
{
}