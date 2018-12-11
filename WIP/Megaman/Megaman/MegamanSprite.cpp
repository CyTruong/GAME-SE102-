#include "MegamanSprite.h"

MegamanSprite::MegamanSprite(int index, float respawnX, float respawnY, Direction movedir) 
{
	this->pData = new MegamanData();
	this->pData->index = index;
	this->pData->bodyRects = new RectF[MegamanData::COUNT];
	this->pData->x = respawnX;
	this->pData->y = respawnY;
	this->pData->movedir = movedir;
	this->pData->ppTextureArrays = new TextureArray*[MegamanData::COUNT];

	this->pData->ppTextureArrays[MegamanData::STAND] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Stand", 4, 12);
	this->pData->ppTextureArrays[MegamanData::STAND]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::STAND] = RectF(-15.0f , -30 , 35, 35 );

	this->pData->ppTextureArrays[MegamanData::STANDSHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Stand_Shoot", 2, 5);
	this->pData->ppTextureArrays[MegamanData::STANDSHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::STANDSHOOT] = RectF(-17.0f, -35.0f, 35, 35);

	this->pData->ppTextureArrays[MegamanData::RUN] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Run", 11, 5);
	this->pData->ppTextureArrays[MegamanData::RUN]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::RUN] = RectF(-16.0f, -34, 37, 37);
	
	this->pData->ppTextureArrays[MegamanData::RUNSHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Run_Shoot", 10, 5);
	this->pData->ppTextureArrays[MegamanData::RUNSHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::RUNSHOOT] = RectF(-14, -33, 39, 36);

	this->pData->ppTextureArrays[MegamanData::JUMP] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Jump", 7, 10);
	this->pData->ppTextureArrays[MegamanData::JUMP]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::JUMP] = RectF(-13, -41, 32, 47);

	this->pData->ppTextureArrays[MegamanData::JUMPSHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Jump_Shoot", 7, 10);
	this->pData->ppTextureArrays[MegamanData::JUMPSHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::JUMPSHOOT] = RectF(-17, -43, 41, 43);

	this->pData->ppTextureArrays[MegamanData::FALL] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Fall", 1, 10);
	this->pData->ppTextureArrays[MegamanData::FALL]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::FALL] = RectF(-13, -41, 32, 47);

	this->pData->ppTextureArrays[MegamanData::FALLSHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Fall_Shoot", 1, 10);
	this->pData->ppTextureArrays[MegamanData::FALLSHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::FALLSHOOT] = RectF(-17, -43, 41, 43);

	this->pData->ppTextureArrays[MegamanData::SLIDE] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Slide", 5,6);
	this->pData->ppTextureArrays[MegamanData::SLIDE]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::SLIDE] = RectF(-20, -25, 44, 35);

	this->pData->ppTextureArrays[MegamanData::SLIDESHOOT] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Slide_Shoot", 5, 10);
	this->pData->ppTextureArrays[MegamanData::SLIDESHOOT]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::SLIDESHOOT] = RectF(-26, -35, 48, 34);

	this->pData->ppTextureArrays[MegamanData::NOCHARGE] = new TextureArray(RESOURCE_SPRITE, "Megaman", "NoCharge", 1, 4);
	this->pData->ppTextureArrays[MegamanData::NOCHARGE]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::NOCHARGE] = RectF(-25, -55, 55, 55);

	this->pData->ppTextureArrays[MegamanData::CHARGING1] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Charge0", 10, 4);
	this->pData->ppTextureArrays[MegamanData::CHARGING1]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::CHARGING1] = RectF(-25, -55, 55, 55);

	this->pData->ppTextureArrays[MegamanData::CHARGING2] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Charge1", 10, 4);
	this->pData->ppTextureArrays[MegamanData::CHARGING2]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::CHARGING2] = RectF(-25, -55, 55, 55);

	this->pData->ppTextureArrays[MegamanData::CHARGING3] = new TextureArray(RESOURCE_SPRITE, "Megaman", "Charge2", 10, 4);
	this->pData->ppTextureArrays[MegamanData::CHARGING3]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::CHARGING3] = RectF(-25, -55, 55, 55);

	this->pData->dir = Direction::createRight();
	this->pData->verticalDir = Direction::createNone();
	this->pData->pState = new MegamanStandingState(pData);
}

MegamanSprite::~MegamanSprite()
{
	//cmt
}

void MegamanSprite::update()
{
	// update animation of cur state in pdata  

	this->pData->pState->onUpdate();

	// update bullet here 

}

void MegamanSprite::draw(Camera * cam)
{
	LogWriter::getInstance()->write(cam->getX(), cam->getY());


	int isDraw = 0;
	if (pData->isRespawn)
	{
		isDraw = rand() % 2;
	}
	if (isDraw == 0)
	{
		isDraw = rand() % 2;
		if (pData->isUndying && isDraw == 0)
		{

			if (pData->dir.isRight())
				pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam, 1.0f, 1.0f, D3DCOLOR_ARGB(255, 255, 0, 60));
			else if (pData->dir.isLeft())
				pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam, 1.0f, 1.0f, D3DCOLOR_ARGB(255, 255, 0, 60));
		}
		else
		{
			if (pData->dir.isRight())
				pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
			else if (pData->dir.isLeft())
				pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
			if (pData->isCharging) {
				pData->ppTextureArrays[pData->bulletType]->draw(pData->x, pData->y + pData->body.width/2, cam);
			}
		}

	}


}

void MegamanSprite::setCameraTo(Camera * cam)
{
	cam->setPosition(this->pData->x, this->pData->y);
}

void MegamanSprite::loadResources()
{



}

void MegamanSprite::updateThroughRect()
{
}

void MegamanSprite::die()
{
}

void MegamanSprite::onCameraCollision(RectF cameraRect)
{
}

int MegamanSprite::getDamage()
{
	return 0;
}

void MegamanSprite::setCameraRect(RectF r)
{
	pData->cameraRect = r;
}
