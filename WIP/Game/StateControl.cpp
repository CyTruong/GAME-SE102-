#include "StateControl.h"




StateControl::StateControl(HWND hWnd)
{
	this->hWnd = hWnd;
}

void StateControl::AddState(State* state) {
	if (this->CurentState ==NULL && state->ID == 0) {
		this->CurentState = state;
	}
	StateList.push_back(state);
}

int StateControl::PushInput(char keys[]) {
	for each (State* state in StateList)
	{
		if ((keys[state->ID] & 0x80)!=0) {
			TriggerAnimate(state->ID);
			return state->ID;
		}
	}
	if(CurentState->ID != 0)
			TriggerAnimate(0); //Idle animation
	return 0;
}

void StateControl::TriggerAnimate(int Key) {
	if (CurentState->ID != Key) {
		State* AnimationTrigger;
		for each (State* ani in StateList)
		{
			if (ani->ID == Key) {
				AnimationTrigger = ani;
				break;
			}
		}
		if (&AnimationTrigger != NULL) {
			CurentState = AnimationTrigger;
		}
	}
}

void StateControl::DrawCurrentFrame(D3DXVECTOR3 position){
	CurentState->DrawCurframe(position);
}

StateControl::~StateControl()
{
}
