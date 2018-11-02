#pragma once
#include "Tranform.h"
#include "Gameobject.h"
#include "define.h"
class Camera
{
public: 
	Position* position;
	int Width;
	int Height;
	Gameobject* targetObj;
public:
	Camera();
	void setTarget(Gameobject* obj);
	void Update();
	~Camera();
};

