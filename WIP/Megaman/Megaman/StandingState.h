#pragma once

#include "MegamanState.h"

class StandingState : public MegamanState
{
private:
public:
	~StandingState() {}
	StandingState(MegamanData* data);
	void onMovePressed(Direction d);
	void onJumpPressed();
	void onUpdate();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	void onFirePressed();
	void onFall();
	virtual void onDead();	
};