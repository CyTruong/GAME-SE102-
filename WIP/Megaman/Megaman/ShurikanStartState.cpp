#include "ShurikanStartState.h"
#include "ShurikanRunningAttackState.h"


ShurikanStartState::ShurikanStartState(EnemyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = ShurikanData::SurikenAniIndex::START;
}

void ShurikanStartState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		transition(new ShurikanRunningAttackState(this->pData));
	}
}

void ShurikanStartState::onCollision(RectF rect)
{
}

void ShurikanStartState::onCollision(CollisionRectF rect)
{
}


ShurikanStartState::~ShurikanStartState()
{
}
