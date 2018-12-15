#pragma once
#include "EnemyData.h"

class SingleGunData :
	public EnemyData
{
public:
	enum SingleGunArrindex
	{
		STAND,
		JUMP,
		FIRE,
		DIE,
		COUNT
	};
public:
	SingleGunData(std::vector<BulletSprite*> bullet = std::vector<BulletSprite*>());
	

	~SingleGunData();
};

