#include "ZuliaShoot2State.h"
#include "ZuliaData.h"




ZuliaShoot2State::ZuliaShoot2State(EnemyData * enemydata, RectF Range)
{
	this->pData = enemydata;
	this->range = Range;
	this->pData->iCurrentArr = ZuliaData::ZuliaAniIndex::SHOOT;
}

void ZuliaShoot2State::onUpdate()
{
}

void ZuliaShoot2State::createBee()
{
}

void ZuliaShoot2State::onCollision(RectF rect)
{
}

void ZuliaShoot2State::onCollision(CollisionRectF rect)
{
}

void ZuliaShoot2State::onDead()
{
}

ZuliaShoot2State::~ZuliaShoot2State()
{
}
