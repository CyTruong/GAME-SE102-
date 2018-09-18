#include "Cat.h"



Cat::Cat(HWND hWnd,LPDIRECT3DDEVICE9 d3ddev)
{
	this->animation  = new Animation_defaut();
//	IControl *contr = new Keyboard_Input();
	this->animation->Create(hWnd, d3ddev, CAT_SPRITE_NAME, CAT_SPRITE_WIDTH, CAT_SPRTIE_HEIGHT, CAT_SPRITE_COLLUMS,CAT_SPRITE_NUMBEROFSPRITE,CAT_SPRITE_ANIMATION_FRAME_DELAY);

}



void Cat::OnreciveControl(char keys[256]) 
{

}

Cat::~Cat()
{
}
