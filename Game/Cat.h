#pragma once
#include "Gameobject.h"
#include "IAnimation.h"
#include "IControl.h"
#include "Animation_defaut.h"
#include "Keyboard_Input.h"

class Cat : public Gameobject	
{
public:
	Cat(HWND,LPDIRECT3DDEVICE9);
	~Cat();

	void OnreciveControl (char[256]) override;
};

