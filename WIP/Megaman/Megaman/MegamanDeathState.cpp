#include "MegamanDeathState.h"




MegamanDeathState::MegamanDeathState(MegamanData * data)
{
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::DEAD);
	this->pData->isUndying = false;
	
}

MegamanDeathState::~MegamanDeathState()
{
}

void MegamanDeathState::onUpdate()
{
	if (this->pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture()) {
		// chết cmn đi
	}
	else
	{
		hittableCalculation();
		this->pData->ppTextureArrays[pData->iCurrentArr]->update();
	}
	
	
}
