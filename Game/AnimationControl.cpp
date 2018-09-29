#include "AnimationControl.h"




AnimationControl::AnimationControl(HWND hWnd)
{
	this->hWnd = hWnd;
}

void AnimationControl::AddAnimation(Animation* animate) {
	if (this->CurentAnimation==NULL && animate->ID == 0) {
		this->CurentAnimation = animate;
	}
	AnimationList.push_back(animate);
}

int AnimationControl::PushInput(char keys[]) {
	for each (Animation* ani in AnimationList)
	{
		if ((keys[ani->ID] & 0x80)!=0) {
			TriggerAnimate(ani->ID);
			return ani->ID;
		}
	}
	if(CurentAnimation->ID != 0)
			TriggerAnimate(0); //Idle animation
	return 0;
}

void AnimationControl::TriggerAnimate(int Key) {
	if (CurentAnimation->ID != Key) {
		Animation* AnimationTrigger;
		for each (Animation* ani in AnimationList)
		{
			if (ani->ID == Key) {
				AnimationTrigger = ani;
				break;
			}
		}
		if (&AnimationTrigger != NULL) {
			CurentAnimation = AnimationTrigger;
		}
	}
}

void AnimationControl::DrawCurrentFrame(D3DXVECTOR3 position){
	CurentAnimation->DrawCurframe(position);
}

AnimationControl::~AnimationControl()
{
}
