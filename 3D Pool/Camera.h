#pragma once
#include "IDrawable.h"

class Camera : public IDrawable
{
public:
	Camera();
	~Camera();
	Vector * Position;
	void Draw() const override;
};

