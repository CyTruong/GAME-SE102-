#pragma once
#include "Gameobject.h"
#include "Keyboard_Input.h"
class Megaman :
	public Gameobject
{
public:
	Megaman(HWND);
	~Megaman();
public:
	void onCollision() override; 
	void Start() override;
	void Update() override;
	void Stop() override;
};

