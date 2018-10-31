#pragma once
#include "IControl.h"
#include "define.h"

class Keyboard_Input :
	public IControl
{
public:

	LPDIRECTINPUTDEVICE8 dikeyboard;
	
public:
	
	int Creat_Input(HWND) override;
	void Poll_input() override;
	void Clear_input() override;
	int Get_State(int) override;

};

