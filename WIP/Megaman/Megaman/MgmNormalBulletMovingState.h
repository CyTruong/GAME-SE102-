#pragma once
#include "BulletState.h"
#include "MgmNormalBulletData.h"
class MgmNormalBulletMovingState : public BulletState
{
private:
	float speed;
public:
	MgmNormalBulletMovingState(MgmNormalBulletData * pdata, float speed, float angle, int icurent = 0) {

		this->pData = pdata;
		pData->iCurrentArr = icurent;
		this->speed = speed;

		pData->vy = sin(angle) * speed;
		pData->vx = cos(angle) * speed;
	}

	virtual void onUpdate() override
	{
		pData->ppTextureArrays[pData->iCurrentArr]->update();

		pData->x += pData->vx;

		pData->y += pData->vy;
	}
	
};

