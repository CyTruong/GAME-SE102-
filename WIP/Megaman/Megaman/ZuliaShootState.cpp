#include "ZuliaShootState.h"
#include "ZuliaData.h"
#include "ZuliaNormalBulletSprite.h"
#include "ZuliaNormalFlyState.h"
#include <random>

ZuliaShootState::ZuliaShootState(EnemyData * enemydata, RectF Range)
{
	this->pData = enemydata;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::SHOOT;
	this->range = Range;
	this->counterFrame = 0;
}

void ZuliaShootState::onUpdate()
{

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();

	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture())
	{
		if(counterFrame == 0)
			createBee();
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->resetIndex();
		if (counterFrame++ > 4) {
			if (rand() % 2) {
				transition(new ZuliaNormalFlyState(this->pData, range.x + 20, range.y + 20, range, ZuliaData::ZuliaMechIndex::STING_PLAYER));
				return;
			}
			else
			{
				transition(new ZuliaNormalFlyState(this->pData, range.x + range.width - 20, range.y + 20, range, ZuliaData::ZuliaMechIndex::STING_PLAYER));
			}
		}
	}
	else
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
}

void ZuliaShootState::createBee()
{
	float alpha;
	if (this->pData->dir.isLeft()) {
		alpha = M_PI;
	}
	else
	{
		alpha = 0;
	}
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x,this->pData->y,alpha,range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha - M_PI_2 / 9, range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha - 2*M_PI_2 / 9, range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha + M_PI_2 / 9, range));
	this->pData->bulletsVector.push_back(new ZuliaNormalBulletSprite(this->pData->x, this->pData->y, alpha + 2 * M_PI_2 / 9, range));

}

void ZuliaShootState::onCollision(RectF rect)
{
}

void ZuliaShootState::onCollision(CollisionRectF rect)
{
}

void ZuliaShootState::onDead()
{
}

ZuliaShootState::~ZuliaShootState()
{
}
