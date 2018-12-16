#include "SingleGunStandState.h"
#include "SingleGunJumpingState.h"



SingleGunStandState::SingleGunStandState(EnemyData * pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::STAND;
	this->pData->dir = this->pData->appearDir; // để xác định hướng cho creep khi vẽ

	this->waittingFrame = 300;
	this->waittingCount = 0;
}

void SingleGunStandState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (pData->Megaman_X > this->pData->x) {
		this->pData->dir = Direction::createRight();
	}
	else
	{
		this->pData->dir = Direction::createLeft();
	}

	if (waittingCount++ > waittingFrame) {
		transition(new SingleGunJumpingState(this->pData));
	}
}

void SingleGunStandState::onCollision(RectF rect)
{
}

void SingleGunStandState::onCollision(CollisionRectF rect)
{
}

SingleGunStandState::~SingleGunStandState()
{
}
