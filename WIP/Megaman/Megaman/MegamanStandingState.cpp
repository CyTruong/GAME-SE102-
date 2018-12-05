﻿#pragma once
#include "MegamanMegamanStandingState.h"

MegamanStandingState::MegamanStandingState(MegamanData * data)
{
	//đứng thui chứ có làm cc gì nửa đâu
	pData->setiCurrentArray(MegamanData::STAND);
	pData->vx = 0;
}

void MegamanStandingState::onMovePressed(Direction d)
{
	pData->dir = d;
	pData->setiCurrentArray(MegamanData::RUN);
}

void MegamanStandingState::onJumpPressed()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();
}

void MegamanStandingState::onUpdate()
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

void MegamanStandingState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void MegamanStandingState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	pData->setiCurrentArray(MegamanData::STAND);
}

void MegamanStandingState::onFirePressed()
{

}

void MegamanStandingState::onFall()
{
}

void MegamanStandingState::onDead()
{
}