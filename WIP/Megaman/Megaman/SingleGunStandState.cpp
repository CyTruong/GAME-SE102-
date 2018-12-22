#include "SingleGunStandState.h"
#include "SingleGunJumpingState.h"
#include "SingleGunNormalBulletSprite.h"
#include "SingleGunFireState.h"

SingleGunStandState::SingleGunStandState(EnemyData * pData)
{
	//LogWriter::getInstance()->write("SingleGun Standing State");
	//LogWriter::getInstance()->write(6,(int)pData->dir.dir);
	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::STAND;
	this->waittingFrame =30;
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
		if (abs(this->pData->Megaman_X - this->pData->x) <= SINGLEGUN_FIRE_RANGE)
		{
			transition(new SingleGunFireState(this->pData));
		}else
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
