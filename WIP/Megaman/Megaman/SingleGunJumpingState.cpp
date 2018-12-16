#include "SingleGunJumpingState.h"
#include "SingleGunData.h"



SingleGunJumpingState::SingleGunJumpingState(EnemyData * pData)
{
	this->gravity = 0.2;
	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::JUMP;
	this->pData->vy = -3.0f;
}

void SingleGunJumpingState::onUpdate()
{

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();

	pData->vx = pData->transform(SINGLEGUNRUNSPEED);
	pData->x += pData->vx;

	pData->vy += gravity;
	pData->y += pData->vy;
}

void SingleGunJumpingState::onCollision(RectF rect)
{
}

void SingleGunJumpingState::onCollision(CollisionRectF rect)
{
}

SingleGunJumpingState::~SingleGunJumpingState()
{
}
