#include "MegamanDeathState.h"




MegamanDeathState::MegamanDeathState(MegamanData * data)
{
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::DEAD);
	this->pData->isUndying = false;
	nFrame = 60;
	counter = 0;
}

MegamanDeathState::~MegamanDeathState()
{
}

void MegamanDeathState::onUpdate()
{
	hittableCalculation();
	this->pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (counter++ > nFrame) {
		//kết thúc
	}
}
