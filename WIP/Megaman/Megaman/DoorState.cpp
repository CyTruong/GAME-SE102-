

#include"DoorState.h"
#include"UI.h"

DoorState::DoorState(ObjectData * pdata)

{

	this->pData = pdata; 
	isMegamanPassing = false; 
	isMegamanCollision = false; 
	isClosed = false;

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

	

	if (isMegamanCollision&&UIComponents::getInstance()->getShurikanHp()==0)
	{
		// set đang mở -> sau bao nhieu fam ->set mở 
	    
		
		this->pData->iCurrentArr = DoorData::OPEN;
				
	}

	
	// if megaman pos x > set dang đóng .... (đóng xong 1 lần là đóng ->set đóng )
	  // set biến đã mở và đóng 


	if (!this->pData->ppTextureArrays[this->pData->iCurrentArr]->isLastTexture()) {
		pData->ppTextureArrays[pData->iCurrentArr]->update();
	}
	//this->pData->ppTextureArrays[this->pData->iCurrentArr]->update(); 


	pData->collisionRect = CollisionRectF(pData->getBody(), "door", pData->vx, pData->vy);



}

void DoorState::onCollision(RectF rect)
{


}

void DoorState::onCollision(CollisionRectF crect)
{

	// thay đổi vị trí x,y của mgm 
	// dịch chuyển cam theo với V chậm hơn 
	isMegamanCollision = 1; 



	}

void DoorState::onCollision(Object obj)
{


}



