#include "MegamanRunningState.h"
#include "define.h"
#include "MegamanStandingState.h"
#include "MegamanJumpState.h"
#include "KeyBoard.h"
#include "MegamanSlideState.h"

MegamanRunningState::MegamanRunningState(MegamanData* data) 
{
	this->pData = data;
	pData->setiCurrentArray(MegamanData::RUN);
	pData->vy = 0;
	tempDir = pData->dir;
}

void MegamanRunningState::onMovePressed(Direction d)
{
	pData->dir = d;
	tempDir = d;
}

void MegamanRunningState::onMoveReleased(Direction d)
{
	tempDir = tempDir ^ d;
	if(!tempDir.isNone())
	{		
		pData -> dir = tempDir;
	}
	else
	transition(new MegamanStandingState(pData)); // thả đúng phím
}

void MegamanRunningState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();	
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	pData->vx = pData->transform(MEGAMANRUNSPEED);
	pData->x += pData->vx;

	if (pData->isFiring)
	{
		pData->count++;
		pData->count %= pData->nFiringHoldFrames;
		if (pData->count == 0)
		{
			pData->isFiring = false;

			pData->setiCurrentArray(MegamanData::RUN);
		}
	}
}

void MegamanRunningState::onJumpPressed()
{
	transition(new MegamanJumpState(this->pData, true, -4.5f));
}

void MegamanRunningState::onSlidePressed()
{
	transition(new MegamanSlideState(this->pData));
}

void MegamanRunningState::onCollision(RectF rect)
{
	if (pData->vx > 0)
	{
		pData->x -= pData->getBody().x + pData->getBody().width - rect.x;
		pData->vx = 0;
	}
	else
	{
		pData->x += rect.x + rect.width - pData->getBody().x;
		pData->vx = 0;
	}
}

void MegamanRunningState::onCollision(CollisionRectF rect)
{
	pData->cThroughRect.push_back(rect);
}

void MegamanRunningState::onDynamicObjectCollision(CollisionRectF * rect)
{
	pData->dynamicThroughRect.push_back(rect);
}

void MegamanRunningState::onFall()
{
	//chuyển jumpung
}

void MegamanRunningState::onFirePressed()
{
}

void MegamanRunningState::onFireRelease()
{
}

void MegamanRunningState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void MegamanRunningState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	pData->setiCurrentArray(MegamanData::RUN);
}

void MegamanRunningState::onDead()
{
}
