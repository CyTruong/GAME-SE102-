#include "ZuliaAlphaFlyState.h"
#include "ZuliaData.h"
#include "ZuliaNormalFlyState.h"


float ZuliaAlphaFlyState::getYfromX(float X)
{

	float value =3 * sin(X/15);
	if ( (this->pData->dir.isLeft() && X < Range.x+Range.width/2)  || (this->pData->dir.isRight() && X > Range.x + Range.width / 2)) {
		return -value;
	}
	return value;
}

ZuliaAlphaFlyState::ZuliaAlphaFlyState(EnemyData * pData,RectF Range)
{
	this->Range = Range;
	mechCounter == 0;
	this->pData = pData;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::NORMALFLY;
	this->speed = 0.5;
}

void ZuliaAlphaFlyState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();


	if (this->pData->x	<= Range.x || this->pData->x + this->pData->body.width >= Range.x + Range.width) {
		this->pData->dir.reverse();
	}

	this->pData->vx = this->pData->transform(speed);

	this->pData->x += this->pData->vx;

	this->pData->y += getYfromX(this->pData->x);
	
	if (mechCounter ++ > 200) {
		mechCounter = 0;
		if (this->pData->x < Range.x + Range.width) {
			transition(new ZuliaNormalFlyState(this->pData, Range.x, Range.y,Range,(int)ZuliaData::ZuliaMechIndex::STING_PLAYER));
		}
		else
		{
			transition(new ZuliaNormalFlyState(this->pData, Range.x+ Range.width, Range.y, Range,(int)ZuliaData::ZuliaMechIndex::STING_PLAYER));
		}
	}
}

void ZuliaAlphaFlyState::onCollision(RectF rect)
{
}

void ZuliaAlphaFlyState::onCollision(CollisionRectF rect)
{
}

void ZuliaAlphaFlyState::onDead()
{
}

ZuliaAlphaFlyState::~ZuliaAlphaFlyState()
{
}
