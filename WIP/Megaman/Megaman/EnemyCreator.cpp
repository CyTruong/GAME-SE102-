#include "EnemyCreator.h"
#include "SingleGunSprite.h"

EnemyCreator* EnemyCreator::instance = nullptr;


EnemyCreator::EnemyCreator()
{
	addAppearDirection("SingleGun", Direction::createLeft());
}

void EnemyCreator::addAppearDirection(std::string name, Direction dir)
{
	appearDirections[name] = dir;
}

EnemyCreator * EnemyCreator::getInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyCreator();
	}
	return instance;
}

EnemySprite * EnemyCreator::createEnemySprite(std::string enemyName, int respawnX, int respawnY, std::vector<BulletSprite*>& bulletSprites)
{
	if (enemyName == "SingleGun") {
		return new SingleGunSprite(respawnX, respawnY, getAppearDir(enemyName), true);
	}
}

ObjectSprite * EnemyCreator::createObjectSprite(std::string name, int respawnX, int respawnY)
{
	return nullptr;
}

Direction EnemyCreator::getAppearDir(std::string name)
{
	std::map < std::string, Direction >::iterator it = appearDirections.find(name);
	if (it != appearDirections.end())
	{
		return it->second;
	}
	return Direction::createNone();
}


EnemyCreator::~EnemyCreator()
{
}
