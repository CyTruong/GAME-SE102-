#pragma once
#include <dinput.h>

 class IControl {
public :
	LPDIRECTINPUT8 dinput;

public:
	virtual int Creat_Input(HWND) = 0;
	virtual void Poll_input() = 0;
	virtual void Clear_input() = 0;
	virtual int Get_State(int) = 0;
};

