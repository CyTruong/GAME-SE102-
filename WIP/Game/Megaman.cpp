#include "Megaman.h"



Megaman::Megaman(HWND hWnd)
{
	this->animation_control = new StateControl(hWnd);

	State* runright_ani = new State(hWnd, MEGAMAN_RUNRIGHT, TRANSCOLOR, MEGAMAN_RUNRIGHTDELAY, MEGAMAN_RUNRIGHTID);
	runright_ani->Create();
	
	State* idle_ani = new State(hWnd, MEGAMAN_IDLE, TRANSCOLOR, MEGAMAN_IDLEDELAY, MEGAMAN_IDLEID);
	idle_ani->Create();

	this->colider = new Colider(Position(20, 2980),40,40);

	this->animation_control->AddState(idle_ani);
	this->animation_control->AddState(runright_ani);

	this->control = new  Keyboard_Input();

	this->control->Creat_Input(hWnd);
}

void Megaman::onCollision()
{
	// dosomething 
	// ex:


}

void Megaman::Start() {

}

void Megaman::Update() {
	Gameobject::Update();
	this->animation_control->PushInput(this->control->key);

	if (this->control->key[DIK_RIGHTARROW] & 0x80) {
		this->tranform->position->pX += 2;

	}

}

void Megaman::Stop() {

}

Megaman::~Megaman()
{
}
