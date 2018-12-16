#include "SingleGunData.h"




SingleGunData::SingleGunData(std::vector<BulletSprite*> bullet)
{
	this->botName = "SingleGun";
	this->isHittable = true;
	this->isDesTroyed = false;
	this->isThrougable = false;
	this->bulletsVector = bullet;

}

SingleGunData::~SingleGunData()
{
}
