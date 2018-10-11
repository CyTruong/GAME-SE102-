#pragma once
#include "Gameobject.h"
#include "Keyboard_Input.h"
class Zero : public Gameobject
{
public:
	Zero(HWND);
	~Zero();

public:
	void Start() override;
	void Update() override;
	void Stop() override;
};

