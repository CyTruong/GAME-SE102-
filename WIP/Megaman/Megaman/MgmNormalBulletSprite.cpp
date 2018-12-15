#include "MgmNormalBulletSprite.h"
#include "MgmNormalBulletMovingState.h"

MgmNormalBulletSprite::MgmNormalBulletSprite(int size, float x, float y, float speed, float angle)
{

	this->bulletSize = this->ConvertSizeIndex(size);

	this->pData = new MgmNormalBulletData();
	this->pData->isDesTroyed = false;
	this->pData->ppTextureArrays = new TextureArray*[MgmNormalBulletData::COUNT ];
	this->pData->bodyRects = new RectF[MegamanData::COUNT];

	if (bulletSize == BulletSize::SMALL) {
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalS_fly", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::FLY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalS_des", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::DESTROY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight());
	}
	if (bulletSize == BulletSize::MEDIUM) {
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalM_fly", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::FLY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalM_des", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::DESTROY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight());
	}
	if (bulletSize == BulletSize::LARGE) {
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalL_fly", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::FLY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::FLY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::FLY]->getHeight());

		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY] = new TextureArray(RESOURCE_SPRITE, "Bullet", "MgmNormalL_des", 1, 500);
		this->pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->setAnchorPoint(0.5f, 0.5f);
		this->pData->bodyRects[MgmNormalBulletData::DESTROY] = RectF(-pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth() / 2, -pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getWidth(), pData->ppTextureArrays[MgmNormalBulletData::DESTROY]->getHeight());
	}

	
	


	pData->x = x;
	pData->y = y;


	pData->pState = new MgmNormalBulletMovingState(pData, speed, angle, MgmNormalBulletData::FLY);

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
