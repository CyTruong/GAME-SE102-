#include "MegamanSlideState.h"
#include "MegamanJumpState.h"
#include "MegamanRunningState.h"
#include "MegamanStandingState.h"


MegamanSlideState::~MegamanSlideState()
{
}

MegamanSlideState::MegamanSlideState(MegamanData* data)
{
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::SLIDE);
	speedSlideX = 8;
	Friction = 0.35f;
}

void MegamanSlideState::onMovePressed(Direction dir)
{
	pData->dir = dir;
}

void MegamanSlideState::onMoveReleased(Direction dir)
{
	
}

void MegamanSlideState::onVeticalDirectionPressed(Direction dir)
{
	pData->dir = dir;
}

void MegamanSlideState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
}

void MegamanSlideState::onJumpPressed()
{
}

void MegamanSlideState::onJumpRelease()
{
	transition(new MegamanJumpState(this->pData, true, -4.5f));
}

void MegamanSlideState::onSlidePressed()
{
}

void MegamanSlideState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[MegamanData::SLIDE]->update();
	pData->vx = pData->transform(speedSlideX);
	speedSlideX -= Friction;
	pData->x += pData->vx;
	
	
	if(speedSlideX<= 0)
	{
		if (pData->vy != 0) {
			transition(new MegamanJumpState(pData, true, pData->vy));
		}
		else
		{
			transition(new MegamanStandingState(pData));

		}
	}

}

void MegamanSlideState::onCollision(RectF rect)
{
}

void MegamanSlideState::onCollision(CollisionRectF rect)
{
}

void MegamanSlideState::onDynamicObjectCollision(CollisionRectF * rect)
{
}

void MegamanSlideState::onFall()
{
}

void MegamanSlideState::onMoveVerticalPressed(Direction dir)
{
}

void MegamanSlideState::onMoveVerticalReleased(Direction dir)
{
}

void MegamanSlideState::onFirePressed()
{
}

void MegamanSlideState::onDead()
{
}

void MegamanSlideState::onCameraCollision(RectF cameraRect)
{
}

void MegamanSlideState::createBullet(float x, float y, float angle)
{
}
