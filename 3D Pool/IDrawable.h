/*
	==============SUMMARY==============
	An Interface class for all drawable
	objects. Any class that needs to 
	render something must implement
	this class.
*/
#pragma once
#include <SDL.h>
#include <GL/glew.h>
#include <GL\GL.h>
#include "Vector.h"

class IDrawable
{
public:
	virtual void Draw() const = 0;
};