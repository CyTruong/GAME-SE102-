#include "ZuliaStingState.h"
#include "ZuliaData.h"
#include "ZuliaAlphaFlyState.h"
#include "ZuliaNormalFlyState.h"

float ZuliaStingState::getYfromX(float X)
{
	this->A = (ya - yb) / (xa - xb);
	this->B = ya - A * xa;
	return A * X + B;
}

ZuliaStingState::ZuliaStingState(EnemyData * pData, RectF Range)
{
	this->Range = Range;
	waiiting2stingcount = 0;
	this->pData = pData;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::STING;
	this->speed = 2;
	this->xa = pData->x;
	this->ya = pData->y;
	this->xb = this->pData->Megaman_X;
	this->yb = this->pData->Megaman_Y;
	if (xb > xa) {
		this->pData->dir = Direction::createRight();
	}
	else {
		this->pData->dir = Direction::createLeft();
	}
}

void ZuliaStingState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	this->pData->ppTextureArrays[ZuliaData::WINGS]->update();

	this->pData->vx = this->pData->transform(speed);
	if ( waiiting2stingcount++ > 50)
	{
		this->pData->x += this->pData->vx;
		this->pData->y = getYfromX(this->pData->x);
	}
	if( abs(this->pData->y -  yb) <= 5 && abs(this->pData->x - xb) <= 5)
	{ 
		transition(new ZuliaNormalFlyState(this->pData, Range.x+5, Range.y + 5, Range, (int)ZuliaData::ZuliaMechIndex::BEESHOOT));

		/*if (this->pData->x < Range.x + Range.width) {
			transition(new ZuliaNormalFlyState(this->pData, Range.x+50, Range.y+ 50, Range, (int)ZuliaData::ZuliaMechIndex::BEESHOOT));
		}
		else
		{
		}*/
	}

}

void ZuliaStingState::onCollision(RectF rect)
{
}

void ZuliaStingState::onCollision(CollisionRectF rect)
{
}

void ZuliaStingState::onDead()
{
}

ZuliaStingState::~ZuliaStingState()
{
}
