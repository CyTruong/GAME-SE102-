

#include"DoorState.h"

DoorState::DoorState(ObjectData * pdata)

{

	this->pData = pdata; 
	isMegamanPassing = false; 
	this->pData->iCurrentArr = 0; 
	this->counting = 0; 

	this->pData->vx = 0;
	this->pData->vx = 0;
}

DoorState::~DoorState()
{
}

void DoorState::onUpdate(){
	// 32 == Witgh mgm or door 

	this->pData->ppTextureArrays[this->pData->iCurrentArr]->update(); 
	
	if (pData->playerX +48 < pData->x )
	{

		this->pData->iCurrentArr = DoorData::PRESENT;


	}
	
	if (this->pData->x - 32 <this->pData->playerX &&this->pData->playerX< this->pData->x) {
	
		

		if (counting<141)
		{
			this->pData->iCurrentArr = DoorData::OPEN;
			
			counting += 1;
		}
		
		}
	
	

if (pData->playerX > pData->x  )
	{	
		if (counting == 141)
		{
			this->pData->iCurrentArr = DoorData::OPENED;

			if (isMegamanPassing)
			{

				if (counting < 280)
				{


					this->pData->iCurrentArr = DoorData::CLOSE;
					counting += 1;
				}
				else
				{
					this->pData->iCurrentArr = DoorData::PRESENT;

				}
			}
		}


		isMegamanPassing = 1; 

	}
	
//        this->pData->iCurrentArr = DoorData::PRESENT; 
		

	

	pData->collisionRect = CollisionRectF(pData->getBody(), "door", pData->vx, pData->vy);



}

void DoorState::onCollision(RectF rect)
{


}

void DoorState::onCollision(CollisionRectF crect)
{

	// thay đổi vị trí x,y của mgm 
	// dịch chuyển cam theo với V chậm hơn 



	}

void DoorState::onCollision(Object obj)
{


}



