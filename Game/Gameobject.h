#pragma once
#include "IAnimation.h"
#include "IControl.h"
#include <string>
using namespace std;

class Gameobject
{
public :
	IControlEventSender	Esource;
	IControl* control;
	IAnimation* animation;
	string name;
	int id;
	
	
public:
	void virtual OnreciveControl(char[256]);
	Gameobject();
	void Start();
	void Stop();
	~Gameobject();
};

