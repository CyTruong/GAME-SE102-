﻿#include "MegamanWallClimping.h"



MegamanWallClimping::MegamanWallClimping(MegamanData * data)
{
	//DownGraviy = 0.3;
//	data->dir.reverse();
	this->pData = data; 

	//this->pData->setiCurrentArray(MegamanData::WALLSLIDE);
	this->pData->vy = 0.01;
}


MegamanWallClimping::~MegamanWallClimping()
{
}

void MegamanWallClimping::onMovePressed(Direction dir)
{
	
}

void MegamanWallClimping::onMoveReleased(Direction dir)
{
	// - x ra 
	// -> rơi 


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
	pData->vy -= acceleration; 
	transition(new MegamanJumpState(this->pData, true ,pData->vy ));
}

void MegamanWallClimping::onJumpRelease()
{
}

void MegamanWallClimping::onSlidePressed()
{
	

	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();

	pData->vx = pData->transform(0.5); 
	
	pData->vy += acceleration; 


	pData->x += pData-> vx; 
	pData->y += pData->vy;


	

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

	

}

void MegamanWallClimping::onUpdate()
{

	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();

	//pData->vx = pData->transform(0.5);
	pData->vx = 0; 
	pData->vy += acceleration;


	pData->x += pData->vx;
	pData->y += pData->vy;

	if (1)
	{
		transition(new MegamanJumpState(pData, false, pData->vy)); 

	}




	//if (pData->isCharging) {
	//	pData->ChargingCount++;
	//	pData->bulletSize = getSizeofBullet(pData->ChargingCount);
	//	pData->ppTextureArrays[pData->bulletSize]->update();
	//}

	//if (pData->isFrire && pData->iCurrentArr == MegamanData::WALLSLIDE) {
	//	pData->setiCurrentArray(MegamanData::WALLSLIDESHOOT);
	//}
	//if (!pData->isFrire && pData->iCurrentArr == MegamanData::WALLSLIDESHOOT) {
	//	pData->setiCurrentArray(MegamanData::WALLSLIDE);
	//}

	//if (pData->isFrire) {
	//	pData->FireCountFrames++;
	//	if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
	//		pData->FireCountFrames = 0;
	//		pData->isFrire = false;
	//	}
	//}

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
	if (!this->pData->isFrire) {
		pData->isCharging = false;
		pData->isFrire = true;
		pData->ChargingCount = 0;


		float bulletX;
		float bulletY;
		float angle;

		if (pData->dir.isRight())
		{
			bulletX = pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}
		else
		{
			bulletX = -pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}

		bulletY = pData->y - pData->ppTextureArrays[pData->iCurrentArr]->getHeight() * 5 / 12 + 3;


		if (pData->dir.isRight())
		{
			angle = 0.0f;
		}
		else
		{
			angle = M_PI;
		}
		createBullet(bulletX, bulletY, angle);
	}	 
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
