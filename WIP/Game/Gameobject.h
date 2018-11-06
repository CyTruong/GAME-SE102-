#pragma once
#include "IAnimation.h"
#include "IControl.h"
#include "AnimationControl.h"
#include "Tranform.h"
#include "Colider.h"
#include <string>
using namespace std;

class Gameobject
{
public :
	Tranform* tranform;
	Colider* colider;
	IControl* control;
	IAnimation* animation;
	AnimationControl* animation_control;
	char* name;
	char* tag; 
	int id;
	
	
public:
	Gameobject();
	void virtual Start();
	void virtual Update();
	void virtual Stop();
	~Gameobject();
};

