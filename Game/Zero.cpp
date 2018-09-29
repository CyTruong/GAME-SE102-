#include "Zero.h"



Zero::Zero(HWND hWnd)
{
	//Bước 1 Khởi tạo animation
	// Đầu tiên, chúng ta cần 1 controler cho animation
	this->animation_control = new AnimationControl(hWnd);
	//Tạo các loại animation
	Animation* Idle = new Animation(hWnd, ZERO_IDLE, D3DCOLOR_XRGB(255, 255, 255), ZERO_IDLEDELAY,ZERO_IDLEID); //Các hằng số lưu vào define tất
	Idle->Creat();
	Animation* Run = new Animation(hWnd, ZERO_RUNRIGHT, D3DCOLOR_XRGB(255, 255, 255), ZERO_RUNRIGHTDELAY,ZERO_RUNRIGHTID);
	Run->Creat();
	//Thêm Animation vào controler
	this->animation_control->AddAnimation(Idle);
	this->animation_control->AddAnimation(Run);

	//Khởi tạo keyboard Input
	this->control = new  Keyboard_Input();
	this->control->Creat_Input(hWnd);
}

void Zero::Start() {

}

void Zero::Update() {
	Gameobject::Update();
	this->animation_control->PushInput(this->control->key);
}

void Zero::Stop() {

}

Zero::~Zero()
{
}


