#include "Table.h"

#include <iostream>
Table::Table(RenderSettings settings)
{
	auto verts = SimpleModelLoader::Load(settings.Resource);
	_vertices = verts->Data;
	num_of_verts = verts->Amount;
	auto colours = SimpleModelLoader::Load(settings.Colours);
	_colours = colours->Data;
	_position = new Vector(settings.Position);
	_size = new Vector(settings.Scale);
	_rotation = settings.Rotation;
	LoadLegs();
	LoadBumpers();
}


Table::~Table()
{
}

void Table::LoadLegs() {
	_legs = new std::vector<Leg *>();
	//four legs on a table
	RenderSettings leg1;
	leg1.Position.X = 0.75f; leg1.Position.Y = 0.0f; leg1.Position.Z = -1.0f;
	leg1.Scale.X = 0.25f; leg1.Scale.Y = 1.0f; leg1.Scale.Z = 0.25f;
	leg1.Rotation = 0.0f;
	leg1.Resource = "Models/leg.txt";
	leg1.Colours = "Models/leg colours.txt";
	_legs->push_back(new Leg(leg1)); //1 is the size of the leg, moving it back 1 to align the edge of the leg with the edge of the table, 0.75f to inset the legs a bit

	RenderSettings leg2;
	leg2.Position.X = -0.75f; leg2.Position.Y = 0.0f; leg2.Position.Z = -1.0f;
	leg2.Scale.X = 0.25f; leg2.Scale.Y = 1.0f; leg2.Scale.Z = 0.25f;
	leg2.Rotation = 0.0f;
	leg2.Resource = "Models/leg.txt";
	leg2.Colours = "Models/leg colours.txt";
	_legs->push_back(new Leg(leg2));

	RenderSettings leg3;
	leg3.Position.X = 0.75f; leg3.Position.Y = 0.0f; leg3.Position.Z = (-1.0f)*_size->Z - 0.25f;
	leg3.Scale.X = 0.25f; leg3.Scale.Y = 1.0f; leg3.Scale.Z = 0.25f;
	leg3.Rotation = 0.0f;
	leg3.Resource = "Models/leg.txt";
	leg3.Colours = "Models/leg colours.txt";
	_legs->push_back(new Leg(leg3));

	RenderSettings leg4;
	leg4.Position.X = -0.75f; leg4.Position.Y = 0.0f; leg4.Position.Z = (-1.0f)*_size->Z - 0.25f;
	leg4.Scale.X = 0.25f; leg4.Scale.Y = 1.0f; leg4.Scale.Z = 0.25f;
	leg4.Rotation = 0.0f;
	leg4.Resource = "Models/leg.txt";
	leg4.Colours = "Models/leg colours.txt";
	_legs->push_back(new Leg(leg4));
}

void Table::LoadBumpers() {
	_bumpers = new std::vector<Bumper *>();
	RenderSettings frontBumper;
	frontBumper.Position.X = 0.0f; frontBumper.Position.Y = 1.0f; frontBumper.Position.Z = -1.0f;
	frontBumper.Scale.X = _size->X - 0.25f; frontBumper.Scale.Y = 0.25f; frontBumper.Scale.Z = 0.25f;
	frontBumper.Rotation = 0.0;
	frontBumper.Resource = "Models/bumper.txt";
	frontBumper.Colours = "Models/bumper colours.txt";

	_bumpers->push_back(new Bumper(frontBumper)); //front bumper

	RenderSettings leftBumper;
	leftBumper.Position.X = -1.0f; leftBumper.Position.Y = 1.0f; leftBumper.Position.Z = -1.0f;
	leftBumper.Scale.X = 0.25f; leftBumper.Scale.Y = 0.25f; leftBumper.Scale.Z = _size->Z;
	leftBumper.Rotation = 0.0f;
	leftBumper.Resource = "Models/side bumper.txt";
	leftBumper.Colours = "Models/side bumper colours.txt";

	_bumpers->push_back(new Bumper(leftBumper)); //left bumper

	RenderSettings rightBumper;
	rightBumper.Position.X = 1.0f; rightBumper.Position.Y = 1.0f; rightBumper.Position.Z = -1.0f;
	rightBumper.Scale.X = 0.25f; rightBumper.Scale.Y = 0.25f; rightBumper.Scale.Z = _size->Z;
	rightBumper.Rotation = 0.0f;
	rightBumper.Resource = "Models/side bumper.txt";
	rightBumper.Colours = "Models/side bumper colours.txt";

	_bumpers->push_back(new Bumper(rightBumper)); //right bumper

	RenderSettings backBumper;
	backBumper.Position.X = 0.0f; backBumper.Position.Y = 1.0f; backBumper.Position.Z = -1.0f + (-1.0f * _size->Z) + 0.25f;
	backBumper.Scale.X = _size->X - 0.25f; backBumper.Scale.Y = 0.25f; backBumper.Scale.Z = 0.25f;
	backBumper.Rotation = M_PI / 2;
	backBumper.Resource = "Models/bumper.txt";
	backBumper.Colours = "Models/bumper colours.txt";

	_bumpers->push_back(new Bumper(backBumper)); //back bumper
}


void Table::Draw() const {
	glPushMatrix();
	glTranslatef(_position->X, _position->Y, _position->Z);
	//Draw Legs
	for (auto iter = _legs->begin(); iter != _legs->end(); ++iter)
	{
		(*iter)->Draw();
	}

	//Draw green table top
	glPushMatrix();
		//glTranslatef(_position->X, _position->Y, _position->Z);
		glTranslatef(0, 1.0f, -1.0f);
		glScalef(_size->X, _size->Y, _size->Z);
		glColorPointer(3, GL_FLOAT, 0, _colours);
		glVertexPointer(3, GL_FLOAT, 0, _vertices);
		glDrawArrays(GL_TRIANGLES, 0, num_of_verts);
	glPopMatrix();
	
	//Draw bumpers
	for (auto iter = _bumpers->begin(); iter != _bumpers->end(); ++iter)
	{
		(*iter)->Draw();
	}

	glPopMatrix();
}