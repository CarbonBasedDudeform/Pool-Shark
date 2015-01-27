/*
	==============SUMMARY==============
	An Interface class for all drawable
	objects. Any class that needs to 
	render something must implement
	this class.
*/
#pragma once

class IDrawable
{
public:
	virtual void Draw() const = 0;
};