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
	~Colider();
};

