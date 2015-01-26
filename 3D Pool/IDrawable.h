/*
	==============SUMMARY==============
	An Interface class for all drawable
	objects. Any class that needs to 
	render something must implement
	this class.
*/
#pragma once
#include <GL/glew.h>

class IDrawable
{
public:
	virtual void Draw() const = 0;
	float rotation;

};