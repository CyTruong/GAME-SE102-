#pragma once
#include "IControl.h"
#include "define.h"

class Keyboard_Input :
	public IControl
{
public:
	LPDIRECTINPUTDEVICE8 dikeyboard;
	char key[256];
public:
	int Creat_Input(HWND) override;
	void Poll_input() override;
	void Clear_input() override;
	int Get_State(int) override;
};

