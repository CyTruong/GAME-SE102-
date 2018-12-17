#pragma once
#include "ObjectState.h"
#include "ElevatorData.h"

class ElevatorWaittingState :
	public ObjectState
{
public:
	ElevatorWaittingState(ObjectData* data) ;
	void onUpdate() override ;
	void onCollision(RectF rect) override;
	void onCollision(CollisionRectF rect) override;
	~ElevatorWaittingState() {} ;
};

