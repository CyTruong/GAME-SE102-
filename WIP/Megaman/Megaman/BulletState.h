#pragma once
#include "SpriteState.h"
#include "MgmNormalBulletData.h"

class BulletState : public SpriteState 
{
protected:
	MgmNormalBulletData *pData;

public:
	BulletState() {}
};