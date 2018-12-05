#pragma once

#include "MegamanState.h"

class MegamanStandingState : public MegamanState
{
private:
public:
	~MegamanStandingState() {}
	MegamanStandingState(MegamanData* data);
	void onMovePressed(Direction d);
	void onJumpPressed();
	void onUpdate();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	void onFirePressed();
	void onFall();
	virtual void onDead();	
};