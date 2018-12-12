#include "MegamanStartState.h"
#include "MegamanStandingState.h"


MegamanStartState::MegamanStartState(MegamanData* data)
{
	this->pData = data;
	this->pData->setiCurrentArray(MegamanData::START);
	this->pData->isUndying = false;
	nFrame = 60;
}


MegamanStartState::~MegamanStartState()
{
}

void MegamanStartState::onUpdate()
{
	hittableCalculation();
	this->pData->ppTextureArrays[pData->iCurrentArr]->update();
	if (counter++ > nFrame) {
		transition(new MegamanStandingState(this->pData));
	}
}
