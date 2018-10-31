#include "Megaman.h"



Megaman::Megaman(HWND hWnd)
{
	this->animation_control = new AnimationControl(hWnd);

	Animation* runright_ani = new Animation(hWnd, MEGAMAN_RUNRIGHT, TRANSCOLOR, MEGAMAN_RUNRIGHTDELAY, MEGAMAN_RUNRIGHTID);
	runright_ani->Create();
	
	Animation* idle_ani = new Animation(hWnd, MEGAMAN_IDLE, TRANSCOLOR, MEGAMAN_IDLEDELAY, MEGAMAN_IDLEID);
	idle_ani->Create();

	this->animation_control->AddAnimation(idle_ani);
	this->animation_control->AddAnimation(runright_ani);

	this->control = new  Keyboard_Input();

	this->control->Creat_Input(hWnd);
}

void Megaman::Start() {

}

void Megaman::Update() {
	Gameobject::Update();
	this->animation_control->PushInput(this->control->key);

}

void Megaman::Stop() {

}

Megaman::~Megaman()
{
}
