#pragma once
#include "BulletSprite.h"
#include "MgmNormalBulletData.h"
#include "MegamanData.h"

	class MgmNormalBulletSprite :
	public BulletSprite
{
public:
	int bulletSize;
private:
	MgmNormalBulletData *pData;
public:
	MgmNormalBulletSprite(int size, float x, float y ,float speed, float angle);
	virtual void draw(Camera * cam);
	virtual void update();
	virtual SpriteState* getState()
	{
		return pData->pState;
	}

	int ConvertSizeIndex(int size) override {
		if ((MegamanData::SpriteArrayIndex)size == MegamanData::CHARGING1 ) {
			return MgmNormalBulletData::SMALL;
		}
		return 0;
		//... tiếp tục convert
	}
	~MgmNormalBulletSprite();
};

