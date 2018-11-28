#pragma once
#include "KeyBoard.h"

class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}
	virtual void draw() = 0;
	virtual void Update() = 0;
};

