#pragma once

#include "MegamanState.h"
#include "Rect.h"
#include "CollisionRect.h"
class MegamanStandingState : public MegamanState
{
private:
public:
	~MegamanStandingState() {}
	MegamanStandingState(MegamanData* data);
	void onMovePressed(Direction d);
	void onJumpPressed();
	void onSlidePressed() override;
	void onUpdate();
	// hcmt add physic 
	void onCollision(CollisionRectF cRect ); 

	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	void onFirePressed();
	void onFireRelease();
	void onFall();
	virtual void onDead();	
};