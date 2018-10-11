#include "Cat.h"



Cat::Cat(HWND hWnd,LPDIRECT3DDEVICE9 d3ddev)
{
	this->animation  = new Animation_defaut();
	this->control = new Keyboard_Input();
	this->animation->Create(hWnd, d3ddev, CAT_SPRITE_NAME, CAT_SPRITE_WIDTH, CAT_SPRTIE_HEIGHT, CAT_SPRITE_COLLUMS,CAT_SPRITE_NUMBEROFSPRITE,CAT_SPRITE_ANIMATION_FRAME_DELAY);
	this->control->Creat_Input(hWnd);
}

void Cat::Start() {

}

void Cat::Update() {
	Gameobject::Update();
	if(this->control->Get_State(DIK_LEFTARROW) ) {
		return;
	}
}

void Cat::Stop() {

}

Cat::~Cat()
{
}
