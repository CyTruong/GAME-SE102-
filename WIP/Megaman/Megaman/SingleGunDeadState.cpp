#include "SingleGunDeadState.h"
#include "SingleGunData.h"


SingleGunDeadState::SingleGunDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = SingleGunData::SingleGunArrindex::DIE;

}


void SingleGunDeadState::onUpdate()
{
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

SingleGunDeadState::~SingleGunDeadState()
{
}
