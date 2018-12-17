#include "EnemyCreator.h"
#include "SingleGunSprite.h"
#include "ElevatorSprite.h"
EnemyCreator* EnemyCreator::instance = nullptr;


EnemyCreator::EnemyCreator()
{
	addAppearDirection("SingleGun", Direction::createRight());
	addAppearDirection("Elevator", Direction::createRight());
	addAppearDirection("DoubleGun", Direction::createRight());
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
	if (enemyName == "DoubleGun") {
		return new SingleGunSprite(respawnX, respawnY, getAppearDir(enemyName), true);
	}

}

ObjectSprite * EnemyCreator::createObjectSprite(std::string name, int respawnX, int respawnY)
{
	if (name == "Elevator") {
		return new ElevatorSprite(respawnX, respawnY);
	}
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
