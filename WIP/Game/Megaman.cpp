#include "Megaman.h"



Megaman::Megaman(HWND hWnd)
{
	this->animation_control = new StateControl(hWnd);

	State* runright_ani = new State(hWnd, MEGAMAN_RUNRIGHT, TRANSCOLOR, MEGAMAN_RUNRIGHTDELAY, MEGAMAN_RUNRIGHTID);
	runright_ani->Create();
	
	State* idle_ani = new State(hWnd, MEGAMAN_IDLE, TRANSCOLOR, MEGAMAN_IDLEDELAY, MEGAMAN_IDLEID);
	idle_ani->Create();

	State* chargerun_ani = new State(hWnd, MEGAMAN_CHARGE_RUN, TRANSCOLOR, MEGAMAN_CHARGE_RUNDELAY, MEGAMAN_CHARGE_RUNID);
	chargerun_ani->Create();

	State* charge_ani = new State(hWnd, MEGAMAN_CHARGE, TRANSCOLOR, MEGAMAN_CHARGEDELAY, MEGAMAN_CHARGEID);
	charge_ani->Create();

	State* jump_ani = new State(hWnd, MEGAMAN_JUMP, TRANSCOLOR, MEGAMAN_JUMPDELAY, MEGAMAN_JUMPID);
	jump_ani->Create();

	State* slide_ani = new State(hWnd, MEGAMAN_SLIDE, TRANSCOLOR, MEGAMAN_SLIDEDELAY, MEGAMAN_SLIDEID);
	slide_ani->Create();

	State* slidecharge_ani = new State(hWnd, MEGAMAN_SLIDE_CHARGE, TRANSCOLOR, MEGAMAN_SLIDE_CHARGEDELAY, MEGAMAN_SLIDE_CHARGEID);
	slidecharge_ani->Create();


	this->colider = new Colider(Position(20, 2980),40,40);

	this->animation_control->AddState(idle_ani);
	this->animation_control->AddState(runright_ani);
	this->animation_control->AddState(chargerun_ani);
	this->animation_control->AddState(charge_ani);
	this->animation_control->AddState(jump_ani);
	this->animation_control->AddState(slide_ani);
	this->animation_control->AddState(slidecharge_ani);
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
