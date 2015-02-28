#include "Ball.h"


//helper function to generate a monochromatic colour rather than load from file
GLfloat * GenerateColours(int size)
{
	GLfloat * colours = new GLfloat[size];

	for (int i = 0; i < size; ++i)
	{
		colours[i] = 1.0f;
	}

	return colours;
}

Ball::Ball(RenderSettings settings)
{
	auto verts = SimpleModelLoader::Load(settings.Resource);
	_radius = 1.0f;
	verts = Generate(verts);
	num_of_verts = verts->Amount; //must be set before Generate is called as generate makes use of it. Could be improved by passing Simple Model in as a param to Generate
	 //similar to above, used in Generate.
	_vertices = verts->Data;

	auto colours = SimpleModelLoader::Load(settings.Colours);
	_colours = GenerateColours(num_of_verts*3); //colours->Data;
	_size = new Vector(settings.Scale);
	_position = new Vector(settings.Position);
	_rotation = settings.Rotation;
	
	//Generate(_vertices);
}


Ball::~Ball()
{
}


/*
	Idea is to generate a sphere by tessellating a diamond.
	This is done by finding the midpoint, such as m, for AB, BC, AC
	      B
	     / \
	    /   \
	   m     \
	  /       \
	 /         \
	A-----------C
	then move m out to be radius distance from the origin.
	This is done by normalizing the vector and then multiplying by the radius.

	This is then done recursively (repeat for midpoint between m and A for example) to create smoother and smoother spheres.
*/

#include <iostream>
SimpleModel * Ball::Generate(SimpleModel * model)
{
	//depth of tesselation
	int depth = 5;
	std::deque<Vector> temp; //temp deque to hold vertices

	for (int i = 0; i < (model->Amount*3); i += 3)
	{
		temp.push_back(Vector(model->Data[i], model->Data[i + 1], model->Data[i + 2]));
	}

	std::deque<Vector> work;
	for (int i = 0; i < depth; i++)
	{
		work.clear();

		for (int j = 0; j < temp.size(); j += 3)
		{
			auto A = temp[j];
			auto B = temp[j + 2];
			auto C = temp[j + 1];

			auto ABmid = (A + B) / 2.0f;
			auto BCmid = (B + C) / 2.0f;
			auto ACmid = (A + C) / 1.0f;

			A.Normalize();
			B.Normalize();
			C.Normalize();
			ABmid.Normalize();
			BCmid.Normalize();
			ACmid.Normalize();

			A *= _radius;
			B *= _radius;
			C *= _radius;
			ABmid *= _radius;
			BCmid *= _radius;
			ACmid *= _radius;

			work.push_back(A);
			work.push_back(ABmid);
			work.push_back(ACmid);

			work.push_back(ABmid);
			work.push_back(B);
			work.push_back(BCmid);

			work.push_back(ACmid);
			work.push_back(BCmid);
			work.push_back(C);

			work.push_back(ABmid);
			work.push_back(BCmid);
			work.push_back(ACmid);
		}
		
		temp = work;
	}

	//contsruct array from vector for use in OpenGLs DrawArray
	GLfloat * results = new GLfloat[work.size()*3];

	int resultsIndex = 0;
	for (int i = 0; i < work.size(); i++)
	{
		results[resultsIndex] = work.at(i).X;
		results[resultsIndex + 1] = work.at(i).Y;
		results[resultsIndex + 2] = work.at(i).Z;
		resultsIndex += 3;
	}

	SimpleModel * toReturn = new SimpleModel();
	toReturn->Amount = work.size();
	toReturn->Data = results;

	return toReturn;
}