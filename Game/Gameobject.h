#pragma once
#include "IAnimation.h"
#include "IControl.h"
#include <string>
using namespace std;

class Gameobject
{
public :
	IControl* control;
	IAnimation* animation;
	string name;
	int id;
	
	
public:
	Gameobject();
	void virtual Start();
	void virtual Update();
	void virtual Stop();
	~Gameobject();
};

