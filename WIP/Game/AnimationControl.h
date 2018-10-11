
/*
	Đây là 1 đối tượng dùng để điều khiển các animation của 1 nhân vật
	Animation Idle ( hay còn gọi là Emotion ( animtion khi afk ) ) luôn có ID = 0
	Các Animation khác như RUn, jump thì có Id là mã phím 
	Đối vs các đối tượng animaion có id là mã phím thì có thể push mảng keys ( 256 key zô ) thì nó sẽ trigger animation đúng theo id
	Đối vs các đối tượng animation đặc biệt thì có thể trigger thông qua hàm trigger animation 
*/
#pragma once
#include "Animation.h"
#include "define.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

using namespace std;

class AnimationControl
{
public:
	Animation* CurentAnimation;
	vector<Animation*> AnimationList;
	HWND hWnd;
public:
	AnimationControl(HWND);
	~AnimationControl();
	int PushInput(char[]);
	void AddAnimation(Animation*);	
	void TriggerAnimate(int);
	void DrawCurrentFrame(D3DXVECTOR3);
	
};

