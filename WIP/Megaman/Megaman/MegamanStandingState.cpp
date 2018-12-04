#pragma once
#include "MegamanStandingState.h"

StandingState::StandingState(MegamanData * data)
{
	//đứng thui chứ có làm cc gì nửa đâu
	pData->setiCurrentArray(MegamanData::STAND);
	pData->vx = 0;
}

void StandingState::onMovePressed(Direction d)
{
	pData->dir = d;
	pData->setiCurrentArray(MegamanData::RUN);
}

void StandingState::onJumpPressed()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();
}

void StandingState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	/*pData->x += (pData->cDynamicSupportRect) ? pData->cDynamicSupportRect->vx : 0.0f;
	pData->y += (pData->cDynamicSupportRect) ? pData->cDynamicSupportRect->vy : 0.0f;*/
	if (pData->isFiring)
	{
		pData->count++;
		pData->count %= pData->nFiringHoldFrames;
		if (pData->count == 0)
		{
			pData->isFiring = false;

			/*if (pData->verticalDir.isDown())
			{
				pData->setiCurrentArray(PlayerData::STANDDOWN);
			}

			else if (pData->verticalDir.isUp())
			{
				pData->setiCurrentArray(PlayerData::STANDUP);
			}
			else
				pData->setiCurrentArray(PlayerData::STAND);*/
			pData->setiCurrentArray(MegamanData::STAND);
		}
	}
}

void StandingState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void StandingState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	pData->setiCurrentArray(MegamanData::STAND);
}

void StandingState::onFirePressed()
{

}

void StandingState::onFall()
{
}

void StandingState::onDead()
{
}
