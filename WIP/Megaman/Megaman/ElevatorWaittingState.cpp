#include "ElevatorWaittingState.h"



ElevatorWaittingState::ElevatorWaittingState(ObjectData * pdata)
{
	this->pData = pdata;
	this->pData->iCurrentArr = ElevatorData::WAITTING;
}

void ElevatorWaittingState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
}

void ElevatorWaittingState::onCollision(RectF rect)
{
}

void ElevatorWaittingState::onCollision(CollisionRectF rect)
{
}
