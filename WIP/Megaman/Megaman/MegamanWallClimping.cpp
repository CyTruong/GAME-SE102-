#include "MegamanWallClimping.h"



MegamanWallClimping::MegamanWallClimping(MegamanData * data)
{
	DownGraviy = 0.3;
	data->dir.reverse();
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::WALLSLIDE);
	this->pData->vy = 1;
}


MegamanWallClimping::~MegamanWallClimping()
{
}

void MegamanWallClimping::onMovePressed(Direction dir)
{
	if (this->pData->dir == dir) {
		transition(new MegamanJumpState(this->pData, true, 0));
	}
}

void MegamanWallClimping::onMoveReleased(Direction dir)
{
}

void MegamanWallClimping::onVeticalDirectionPressed(Direction dir)
{
	if (this->pData->dir == dir) {
		transition(new MegamanJumpState(this->pData, true, 0));
	}
}

void MegamanWallClimping::onVeticalDirectionReleased()
{
}

void MegamanWallClimping::onJumpPressed()
{
	transition(new MegamanJumpState(this->pData, true));
}

void MegamanWallClimping::onJumpRelease()
{
}

void MegamanWallClimping::onSlidePressed()
{
	transition(new MegamanSlideState(this->pData));

	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();

	this->pData->vy += DownGraviy;
	this->pData->y += pData->vy;

	if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletSize = getSizeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletSize]->update();
	}

	if (pData->isFrire && pData->iCurrentArr == MegamanData::WALLSLIDE) {
		pData->setiCurrentArray(MegamanData::WALLSLIDESHOOT);
	}
	if (!pData->isFrire && pData->iCurrentArr == MegamanData::WALLSLIDESHOOT) {
		pData->setiCurrentArray(MegamanData::WALLSLIDE);
	}

	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
		}
	}

	this->pData->y += pData->vy;

}

void MegamanWallClimping::onUpdate()
{
}

void MegamanWallClimping::onCollision(RectF rect)
{
}

void MegamanWallClimping::onCollision(CollisionRectF rect)
{
}

void MegamanWallClimping::onDynamicObjectCollision(CollisionRectF * rect)
{
}

void MegamanWallClimping::onFall()
{
}

void MegamanWallClimping::onMoveVerticalPressed(Direction dir)
{
}

void MegamanWallClimping::onMoveVerticalReleased(Direction dir)
{
}

void MegamanWallClimping::onFirePressed()
{
	pData->isCharging = true;

}

void MegamanWallClimping::onFireRelease()
{
}

void MegamanWallClimping::onDead()
{
}

void MegamanWallClimping::onCameraCollision(RectF cameraRect)
{
}

void MegamanWallClimping::createBullet(float x, float y, float angle)
{
}
