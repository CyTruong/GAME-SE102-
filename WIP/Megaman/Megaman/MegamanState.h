#pragma once

#include "SpriteState.h"
#include "MegamanData.h"
//#include "Sound.h"

class MegamanState : public SpriteState
{
public:
	MegamanState() {}
	virtual void transition(MegamanState* state)
	{
		pData->pState = state;
		delete this;
	}
	virtual void onCameraCollision(RectF cameraRect)
	{
		pData->x = max(pData->x, cameraRect.x + 20);
		pData->x = min(pData->x, cameraRect.x + cameraRect.width - 20);
		if (pData->y > cameraRect.y + cameraRect.height)
		{
			pData->y = cameraRect.y + cameraRect.height;
			onDead();
		}
	}
	virtual void createBullet(float x, float y, float angle)
	{
		float speed = 0.0f;
		
		
	}
	virtual void hittableCalculation()
	{
		if (pData->isRespawn)
		{
			pData->hittableCounter++;
			if ((pData->hittableCounter >= pData->nonHittableFrames))
			{
				pData->isHittable = true;
				pData->isRespawn = false;
			}
		}
	}

	virtual void undyingCalculation()
	{
		if (pData->isUndying)
		{
			pData->undyingCounter++;
			if ((pData->undyingCounter >= pData->nUndyingFrames))
			{
				pData->isUndying = false;

			}
		}
	}




protected:
	MegamanData* pData;
};