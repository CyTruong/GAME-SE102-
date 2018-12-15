#pragma once
#include "MegamanState.h"

class MegamanJumpState : public MegamanState
{
private:
	bool isMoving;
	bool isJumpingPress;
	float speedX;
	//float acceleration;
public:
	MegamanJumpState(MegamanData * data, bool isMoving = false , float vy =-5.0f);
	~MegamanJumpState();
	void onMovePressed(Direction dir);
	void onMoveReleased(Direction dir);
	void onJumpRelease();
	void onSlidePressed();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDynamicObjectCollision(CollisionRectF* cRect);
	void onUpdate();
	void onFirePressed();
	void onFireRelease();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();

};

