#include "HPBarSprite.h"
#include "ObjectState.h"
#include "UI.h"

HPBarSprite::HPBarSprite(Camera * & cam, float posX, float posY, int hubType)
{
	this->hubType = hubType; 

	this->posX = posX;
	this->posY = posY;

	this->pData = new ObjectData();
	this->pData->ppTextureArrays = new TextureArray*[1];

	int MaxHp; 
	
	if (hubType)
	{
		this->pData->ppTextureArrays[0] = new TextureArray(RESOURCE_SPRITE, "UI", "HpHub", 1, 60);
		this->pData->ppTextureArrays[0]->setAnchorPoint(0.5f,1 );

		MaxHp = UIComponents::getInstance()->getMegamanHp(); 
	}
	else
	{
		MaxHp = 30; 

	this->pData->ppTextureArrays[0] = new TextureArray(RESOURCE_SPRITE, "UI", "HpHubBoss", 1, 60);
	this->pData->ppTextureArrays[0]->setAnchorPoint(0.5f,1);
	}
	// if mau toi da cua boss hay megaman  

	for (int i = 0; i <MaxHp ; i++) //với 10 là max hp
	{
		HPSprite* hp = new HPSprite();
		hpSprites.push_back(hp);
	}

	
	this->pData->pState = new ObjectState();
}

void HPBarSprite::onUpdate()
{

	
}

void HPBarSprite::draw(Camera * cam)
{
	this->pData->x = cam->getX() + posX;
	this->pData->y = cam->getY() + posY;

	pData->ppTextureArrays[0]->draw(pData->x, pData->y, cam);

	int remainHp= UIComponents::getInstance()->getMegamanHp();

	if (!hubType)
	{
	 remainHp= UIComponents::getInstance()->getBossHp();
	 //remainHp = 10; 

	} 



	for (int i = 0; i < remainHp; i++) {
		this->hpSprites[i]->getobjData()->x = this->pData->x;
		this->hpSprites[i]->getobjData()->y = this->pData->y - 15 - i * 2	;
		this->hpSprites[i]->draw(cam);

	}

}

HPBarSprite::~HPBarSprite()
{
}
