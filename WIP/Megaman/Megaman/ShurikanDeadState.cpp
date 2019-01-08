#include "ShurikanDeadState.h"
#include"ShurikanData.h"


ShurikanDeadState::ShurikanDeadState(EnemyData *pData)
{


	this->pData = pData;
	this->pData->iCurrentArr = ShurikanData::SurikenAniIndex::DIE;

}


void ShurikanDeadState::onUpdate()
{
	UIComponents::getInstance()->setShurikanHp(0);


	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		this->pData->isDesTroyed = true;
	}
	else
	{
		this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	}
}

ShurikanDeadState::~ShurikanDeadState()
{
}
