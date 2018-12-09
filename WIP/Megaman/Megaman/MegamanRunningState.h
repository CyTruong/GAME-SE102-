#pragma once
#include "MegamanState.h"
#include "MegamanData.h"

class MegamanRunningState : public MegamanState
{


public:
	MegamanRunningState(MegamanData* data);
	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	void onUpdate() ;
	void onJumpPressed();
	void onSlidePressed();
	void onCollision(RectF rect );
	void onCollision(CollisionRectF rect );
	void onDynamicObjectCollision(CollisionRectF* rect);
	void onFall();
	void onFirePressed();
	void onFireRelease();
	void onVeticalDirectionPressed( Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();
};

