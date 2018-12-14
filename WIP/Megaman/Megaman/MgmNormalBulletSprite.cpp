#include "MgmNormalBulletSprite.h"
#include "MgmNormalBulletMovingState.h"

MgmNormalBulletSprite::MgmNormalBulletSprite(int size, float x, float y, float speed, float angle)
{
	this->bulletSize = size;

	this->pData = new MgmNormalBulletData();
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[MgmNormalBulletData::COUNT ];
	this->pData->bodyRects = new RectF[MegamanData::COUNT];



	this->pData->ppTextureArrays[MgmNormalBulletData::SMALL] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalS", 1, 500);
	this->pData->ppTextureArrays[MgmNormalBulletData::SMALL]->setAnchorPoint(0.5f, 0.5f);
	this->pData->bodyRects[MgmNormalBulletData::SMALL] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::SMALL]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::SMALL]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::SMALL]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::SMALL]->getHeight());


	pData->x = x;
	pData->y = y;

	size = this->ConvertSizeIndex(size);

	pData->pState = new MgmNormalBulletMovingState(pData, speed, angle, size);

}

void MgmNormalBulletSprite::draw(Camera * cam)
{
	pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);

}

void MgmNormalBulletSprite::update()
{
	pData->pState->onUpdate();

}

MgmNormalBulletSprite::~MgmNormalBulletSprite()
{
}
