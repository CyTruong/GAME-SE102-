#pragma once
#include "EnemySprite.h"
#include "BulletSprite.h"
#include "SingleGunData.h"

#define SINGLEGUN_TURN_RANGE 30

class SingleGunSprite :
	public EnemySprite
{
public:
	SingleGunSprite(float x, float y, Direction dir, bool isShoter = false, std::vector<BulletSprite*> bullet = std::vector<BulletSprite*>());
	void setCollisionRect(CollisionRectF rect);
	void onCameraCollision(RectF cameraRect);
	void die();
	~SingleGunSprite();
};

