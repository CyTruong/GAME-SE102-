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

	this->pData->ppTextureArrays[MegamanData::STAND] = new TextureArray("Resource\\Sprite\\", "Megaman", "Run", 4, 20);
	this->pData->ppTextureArrays[MegamanData::STAND]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::STAND] = RectF(-15.0f , 30 , -35, 35 );

	this->pData->ppTextureArrays[MegamanData::RUN] = new TextureArray("Resource\\Sprite\\", "Megaman", "Run", 4, 60);
	this->pData->ppTextureArrays[MegamanData::RUN]->setAnchorPoint(0.5f, 1.0f);
	this->pData->bodyRects[MegamanData::RUN] = RectF(-15.0f, 30, -35, 35);

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
	this->pData->pState->onUpdate();
}

void MegamanSprite::draw(Camera * cam)
{
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
		}

	}


}

void MegamanSprite::setCameraTo(Camera * cam)
{
	cam->setPosition(this->pData->x, this->pData->y);
}

void MegamanSprite::loadResources()
{

	TextureArray* temp = new TextureArray("Resources\\Sprites", "Megaman", "stand", 1, 60);

	delete temp;

	// add more 

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
