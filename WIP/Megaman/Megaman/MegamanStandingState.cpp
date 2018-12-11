#pragma once
#include "MegamanStandingState.h"
#include "MegamanRunningState.h"
#include "MegamanJumpState.h"
#include "MegamanSlideState.h"

MegamanStandingState::MegamanStandingState(MegamanData * data)
{
	//đứng thui chứ có làm cc gì nửa đâu
	// má đéo gán đối số :v 
	pData = data; 
	pData->setiCurrentArray(MegamanData::STAND);
	pData->vx = 0;
}

void MegamanStandingState::onMovePressed(Direction d)
{
	pData->dir = d;
	transition(new MegamanRunningState(pData));
}

void MegamanStandingState::onJumpPressed()
{
	transition(new MegamanJumpState(this->pData, true, -4.5f));
}

void MegamanStandingState::onSlidePressed()
{
	transition(new MegamanSlideState(this->pData));
}

void MegamanStandingState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	if (pData->isFrire && pData->iCurrentArr == MegamanData::STAND) {
		pData->setiCurrentArray(MegamanData::STANDSHOOT);
	}
	if (!pData->isFrire && pData->iCurrentArr == MegamanData::STANDSHOOT) {
		pData->setiCurrentArray(MegamanData::STAND);
	}

	pData->ppTextureArrays[pData->iCurrentArr]->update();

	if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletType = getTypeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletType]->update();
	}

	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
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
	pData->isCharging = true;
}

void MegamanStandingState::onFireRelease()
{
	pData->isCharging = false;
	pData->isFrire = true;
	pData->ChargingCount = 0;
}

void MegamanStandingState::onFall()
{
}

void MegamanStandingState::onDead()
{
}
