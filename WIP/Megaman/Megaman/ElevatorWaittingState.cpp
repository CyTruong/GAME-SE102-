#include "ElevatorWaittingState.h"



ElevatorWaittingState::ElevatorWaittingState(ObjectData * pdata)
{
	this->pData = pdata;
	this->pData->iCurrentArr = ElevatorData::WAITTING;
	this->pData->vx = 0;
	this->pData->vy = -1;

}

void ElevatorWaittingState::onUpdate()
{
	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update();
	if (isMegamanStanding) {

		this->pData->y += this->pData->vy;
		isMegamanStanding = false;
	}
}

void ElevatorWaittingState::onCollision(RectF rect)
{

}

void ElevatorWaittingState::onCollision(CollisionRectF rect)
{
	LogWriter::getInstance()->write("Elevator collision");
	LogWriter::getInstance()->write(rect.type);
	LogWriter::getInstance()->write(rect.rect.x,rect.rect.y);
	if (rect.type == "Megaman") {
		isMegamanStanding = true;
	}
}
