#pragma once
#include "Tranform.h"
class Colider
{
public:
	Position* position; 
	int height, width;
public:
	Colider() {
		position = new Position();
	}
	Colider(Position p, int w,int h) {
		this->position = new Position(&p);
		this->width = w;
		this->height = h;
	}

	Colider(int w,int h) {
		this->width = w;
		this->height = h;
	}

	bool checkCollision(Colider  c2)
	{
		if (this->position->pX + this->width <= c2.position->pX)
			return false;
		if (this->position->pX >= position->pX + c2.width)
			return false;
		if (this->position->pY + this->height <= c2.position->pY)
			return false;
		if (this->position->pY >= c2.position->pY + c2.height)
			return false;
		return true;
	}
	~Colider() {};
};

