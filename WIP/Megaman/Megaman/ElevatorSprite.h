#pragma once
#include "ObjectSprite.h"
class ElevatorSprite :
	public ObjectSprite
{
public:
	ElevatorSprite(float x,float y);
	void update();
	~ElevatorSprite();
};

