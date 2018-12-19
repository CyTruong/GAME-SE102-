#include "Map.h"
#include <algorithm> 
#include <typeinfo>


Map::Map(std::string mapName)
	:
	mapName(mapName)
{
	std::string convertFileName = std::string("Resource\\Map\\") + (mapName)+std::string(".tmx");
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(convertFileName);
	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot->Attribute("tilewidth", &tileSize);
	pRoot->Attribute("width", &width);
	pRoot->Attribute("height", &height);

	// load tile set
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("tileset"))
		{
			loadTileSet(e);
		}
	}


	// load Layer

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("layer"))
		{
			loadLayer(e);
		}
	}

	// create tileTmx in BackGroundLayer
	for (int i = 0; i < layers.size(); i++)
	{
		if (layers[i]->getName() == "BackgroundLayer")
			layers[i]->createTileTmx();
	}

	// Load CollisionLayer
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("objectgroup") && e->Attribute("name") == std::string("CollisionLayer"))
		{
			loadCollisionRect(e);
		}
	}

	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("objectgroup") && e->Attribute("name") == std::string("ObjLayer"))
		{
			loadObject(e);
		}
	}



	// create quadtree

	createMapCollsionTree();
	bIsFinish = false;

}


Map::~Map()
{
	for (int i = 0; i < tileSets.size(); i++)
	{
		if (tileSets[i])
			delete tileSets[i];
	}
	tileSets.clear();

	for (int i = 0; i < layers.size(); i++)
	{
		if (layers[i])
			delete layers[i];
	}
	layers.clear();

	collisionRectFs.clear();

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		if (bulletSprites[i])
			delete bulletSprites[i];
	}
	bulletSprites.clear();
	for (int i = 0; i < Objects.size(); i++)
	{
		if (Objects[i])
			delete Objects[i];
	}
	Objects.clear();

	for (auto it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		delete it->second;
	}

	for (auto it = objectMap.begin(); it != objectMap.end(); it++)
	{
		delete it->second;
	}

	delete mapCollisionTree;


}
#pragma region 


void Map::loadTileSet(TiXmlElement* e)
{
	TileSet* tileSet;
	tileSet = new TileSet();
	std::string s = std::string("Resource\\Map\\") + (e->FirstChildElement()->Attribute("source"));

	std::wstring tileSetSource(s.begin(), s.end());

	tileSet->name = e->Attribute("name");

	Graphics::getInstance()->loadTexture(s, e->Attribute("name"));
	tileSet->pTexture = Graphics::getInstance()->getTexture(tileSet->name)->pTexture;

	e->FirstChildElement()->Attribute("width", &tileSet->width);
	e->FirstChildElement()->Attribute("height", &tileSet->height);
	e->Attribute("firstgid", &tileSet->firstGridID);
	e->Attribute("tilewidth", &tileSet->tileWidth);
	e->Attribute("tileheight", &tileSet->tileHeight);
	e->Attribute("spacing", &tileSet->spacing);
	e->Attribute("margin", &tileSet->margin);



	int nCol = tileSet->width / (tileSet->tileWidth + tileSet->spacing);
	if (tileSet->width % (tileSet->tileWidth + tileSet->spacing) > tileSet->tileWidth)
	{
		nCol++;
	}
	int nRow = tileSet->height / (tileSet->tileHeight + tileSet->spacing);
	if (tileSet->tileHeight % (tileSet->tileHeight + tileSet->spacing) > tileSet->tileHeight)
	{
		nRow++;
	}

	tileSet->nColumns = nCol;
	tileSet->nRows = nRow;
	tileSet->lastGridID = nCol * nRow + tileSet->firstGridID - 1;

	for (TiXmlElement* ele = e->FirstChildElement(); ele != NULL; ele = ele->NextSiblingElement())
	{
		if (ele->Value() == std::string("tile"))
		{
			tileSet->loadAnimationTiled(ele);
		}
	}


	tileSets.push_back(tileSet);


}

void Map::loadLayer(TiXmlElement* pTileElement)
{

	TileLayer* pTileLayer = new TileLayer(tileSize, width, height, pTileElement->Attribute("name"), tileSets);

	std::vector<std::vector<int>> data;

	std::string decodedIDs;

	TiXmlElement* pDataNode = NULL;

	for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}

	for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	{
		TiXmlText* text = e->ToText();

		std::string t = text->Value();

		decodedIDs = base64_decode(t);
	}

	// uncompress zlib compression
	uLongf numGids = width * height * sizeof(int);

	std::vector< int > gids(width * height);

	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

	std::vector<int> layerRow(width);

	for (int j = 0; j < height; j++)
	{
		data.push_back(layerRow);
	}
	for (int rows = 0; rows < height; rows++)
	{
		for (int cols = 0; cols < width; cols++)
		{
			data[rows][cols] = gids[rows * width + cols];
		}
	}

	pTileLayer->setTileIDs(data);

	layers.push_back(pTileLayer);
}

void Map::loadCollisionRect(TiXmlElement* pElement)
{
	RectI r;
	std::string type;

	for (TiXmlElement* e = pElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		e->Attribute("x", &r.x);
		e->Attribute("y", &r.y);
		e->Attribute("width", &r.width);
		e->Attribute("height", &r.height);
		type = e->Attribute("type");
		//collisionRects.push_back(r);
		collisionRectFs.push_back(CollisionRectF(r, type));
	}
}

void Map::loadObject(TiXmlElement* pElement)
{
	//RectI r;

	int id;
	int x;
	int y;
	int rectX;
	int rectY;
	int width;
	int height;
	std::string name;
	std::string type;
	for (TiXmlElement* e = pElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		name = e->Attribute("name");
		type = e->Attribute("type");
		e->Attribute("id", &id);
		e->Attribute("x", &rectX);
		e->Attribute("y", &rectY);
		e->Attribute("width", &width);
		e->Attribute("height", &height);

		if (name == "cameratranslateposition")
		{
			cameraTranslatePosition = RectF(rectX, rectY, width, height);
		}
		else if (name == "respawnposition")
		{
			respawnX = rectX + width / 2;
			respawnY = rectY + height;
		}
		else
		{
			if (std::find(spriteNames.begin(), spriteNames.end(), name) == spriteNames.end())
				spriteNames.push_back(name);
			x = rectX;
			y = rectY;

			if (type != "object")
			{
				x = rectX + width / 2;
				y = rectY + height;
			}
			Object* object = new Object(name, type, x, y, id, width, height, RectF(rectX, rectY, width, height));
			Objects.push_back(object);
		}

	}

}

void Map::createMapCollsionTree()
{
	mapCollisionTree = new QuadTree(0, RectF(0.0f, 0.0f, tileSize * width, tileSize * height));
}

void Map::cleanMap(Camera* cam)
{
	//// clean Enemy
	//RectF camRect(cam->getX(), cam->getY(), cam->getWidth(), cam->getHeight());
	//for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); )
	//{
	//	EnemySprite* temp = it->second;
	//	RectF SpriteRect(temp->getBody());
	//	if (temp->isDesTroyed())
	//	{
	//		if (temp->isDead())
	//		{
	//			UIComponents::getInstance()->addScore(temp->getScore(), temp->getKillByIndex());
	//		}
	//		if (temp->getName().find("final") != std::string::npos)
	//		{
	//			Sound::getInstance()->stop();
	//			Sound::getInstance()->play("explode.wav", false, 1);

	//			bIsFinish = true;
	//		}
	//		delete temp;
	//		it = EnemyMap.erase(it);
	//	}
	//	else
	//		it++;
	//}

	//for (int i = 0; i < bulletSprites.size(); i++)
	//{
	//	Sprite* temp = bulletSprites[i];
	//	if (!camRect.checkCollision(temp->getBody()) || temp->isDesTroyed())
	//	{
	//		delete temp;
	//		bulletSprites.erase(bulletSprites.begin() + i);
	//	}
	//}


	//// clean ObjectSprite

	//for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); )
	//{
	//	ObjectSprite* temp = it->second;
	//	RectF SpriteRect(temp->getBody());

	//	if (it->second->isDesTroyed())
	//	{
	//		delete temp;
	//		it = objectMap.erase(it);
	//	}
	//	else
	//		it++;
	//}




	//if (bIsFinish)
	//{
	//	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	//	{
	//		it->second->die();
	//	}

	//	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	//	{
	//		it->second->die();
	//	}

	//	for (int i = 0; i < bulletSprites.size(); i++)
	//	{
	//		bulletSprites[i]->die();
	//	}

	//}


}


void Map::cleanPlayerBullet(Camera* cam, MegamanSprite* sprite)
{
	/*RectF camRect(cam->getX(), cam->getY(), cam->getWidth(), cam->getHeight());
	std::vector<BulletSprite* >& playerBullets = sprite->getBullets();

	for (int i = 0; i < playerBullets.size(); i++)
	{
		Sprite* temp = playerBullets[i];
		if (!camRect.checkCollision(temp->getBody()) || temp->isDesTroyed())
		{
			delete temp;
			playerBullets.erase(playerBullets.begin() + i);
		}
	}*/
}

void Map::addEToMap(Camera* cam)
{
	RectF camRect = cam->getRect();
	mapCollisionTree->clear();
	for (int i = 0; i < Objects.size(); i++)
	{

		if (EnemyMap.find(Objects[i]->id) == EnemyMap.end() && objectMap.find(Objects[i]->id) == objectMap.end())
			mapCollisionTree->insert(Objects[i]);

	}
	std::vector < Object * > returnList;
	mapCollisionTree->getObjectlist(returnList, camRect);

	for (int i = 0; i < returnList.size(); i++)
	{
		RectF body = returnList[i]->body;
		std::string type = returnList[i]->type;
		if (camRect.checkCollision(body))
		{
			Direction appearDir = EnemyCreator::getInstance()->getAppearDir(returnList[i]->name);
			if (1)
			{
				if (type == "enemy")
				{
					EnemySprite* EnemySprite = EnemyCreator::getInstance()->createEnemySprite(returnList[i]->name, returnList[i]->x, returnList[i]->y, bulletSprites);
					if (EnemySprite != nullptr)
						EnemyMap[returnList[i]->id] = EnemySprite;
				}
				else
				if(type == "object")
				{
					ObjectSprite* objectSprite = EnemyCreator::getInstance()->createObjectSprite(returnList[i]->name, returnList[i]->x, returnList[i]->y);
					if (objectSprite != nullptr)
						objectMap[returnList[i]->id] = objectSprite;
				}
				continue;
			}
			

		}
	}
}






void Map::draw(Camera* cam)
{
	for (int i = 0; i < layers.size(); i++)
	{
		if (layers[i]->getName() == "BackgroundLayer")
			layers[i]->draw(cam);
	}

	for (std::map < int, EnemySprite* > ::reverse_iterator it = EnemyMap.rbegin(); it != EnemyMap.rend(); ++it)
	{
		it->second->draw(cam);
	}

	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); ++it)
	{
		it->second->draw(cam);
	}

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		bulletSprites[i]->draw(cam);
	}


}



void Map::onCollision(Camera* cam)
{
	// map collision vs Player
	mapCollisionTree->clear();

	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree->insert(collisionRectFs[i]);
	}

#pragma region EnemyvsMap

	for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
	{
		std::vector < CollisionRectF > returnLists;
		mapCollisionTree->getObjectlist(returnLists, EnemyIt->second->getBody());

		for (int i = 0; i < returnLists.size(); i++)
		{
			//hcmt thourng ? ?? 

			std::vector < CollisionRectF > throughRectVector = EnemyIt->second->getThroughRect();
			if (std::find(throughRectVector.begin(), throughRectVector.end(), returnLists[i]) == throughRectVector.end())
			{
				if (EnemyIt->second->getBody().checkCollision(returnLists[i].rect))
				{
					EnemyIt->second->onCollision(returnLists[i]);
				}
			}

		}


		for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
		{
			if (objectIt->second->isEnemyCollisionable())
			{
				CollisionRectF r = objectIt->second->getCollisionRect();
				if (EnemyIt->second->getBody().checkCollision(r.rect))
				{
						EnemyIt->second->onCollision(r);
				}
			}

		}



	}
#pragma endregion 

#pragma region EnemyBulletvsMap


	for (int i = 0; i < bulletSprites.size(); i++)
	{
		std::vector < CollisionRectF > returnLists;
		mapCollisionTree->getObjectlist(returnLists, bulletSprites[i]->getBody());
		for (int j = 0; j < returnLists.size(); j++)
		{
			std::vector < CollisionRectF > throughRectVector = bulletSprites[i]->getThroughRect();
			if (std::find(throughRectVector.begin(), throughRectVector.end(), returnLists[j]) == throughRectVector.end())
			{
				if (bulletSprites[i]->getBody().checkCollision(returnLists[j].rect))
				{
					bulletSprites[i]->onCollision(returnLists[j]);
				}
			}
		}
	}
#pragma endregion 

#pragma region ObjectvsMap

	//obj vs obj
	//có 4tree
	
	for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
	{
		std::vector < CollisionRectF > objectCollisionReturnList;

		mapCollisionTree->getObjectlist(objectCollisionReturnList, objectIt->second->getBody());

		for (int i = 0; i < objectCollisionReturnList.size(); i++)
		{
			CollisionRectF cRect = objectCollisionReturnList[i];
			if (objectIt->second->getBody().checkCollision(cRect.rect))
			{
				objectIt->second->onCollision(cRect);
			}
		}

	}


#pragma endregion 

	RectF cameraRect = cam->getRect();

#pragma region EnemyObjectvsCamera

	/*for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		it->second->onCameraCollision(cameraRect);
	}
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it->second->onCameraCollision(cameraRect);
	}
*/
#pragma endregion 

	// update through rect list of Enemy
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		it->second->updateThroughRect();
	}
	// update through rect list of object
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it->second->updateThroughRect();
	}
}

void Map::onCollisionvsPlayer(MegamanSprite* sprite, Camera* cam)
{
	mapCollisionTree->clear();

	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree->insert(collisionRectFs[i]);
	}
#pragma region mapvsPlayer


	// player vs Collision Rect
	std::vector < CollisionRectF > returnList;
	mapCollisionTree->getObjectlist(returnList, sprite->getBody());


	for (int i = 0; i < returnList.size(); i++)
	{
		std::vector < CollisionRectF > throughRectVector = sprite->getThroughRect();
		if (std::find(throughRectVector.begin(), throughRectVector.end(), returnList[i]) == throughRectVector.end())
		{
			if (sprite->getBody().checkCollision(returnList[i].rect))
			{  
				sprite->onCollision(returnList[i]);
			}
			
		}

	}



	for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
	{
		if (objectIt->second->isPlayerCollisionable())
		{
			CollisionRectF* r = objectIt->second->getRefCollisionRect();
			std::vector < CollisionRectF* > throughRectVector = sprite->getDynamicThroughRect();
			int size = 0;
			size = throughRectVector.size();
			if (std::find(throughRectVector.begin(), throughRectVector.end(), r) == throughRectVector.end())
			{
				if (sprite->getBody().checkCollision(r->rect))
				{
					sprite->onDynamicObjectCollision(r);
					CollisionRectF cRect = CollisionRectF(sprite->getBody(), "Megaman");
					objectIt->second->onCollision(cRect);
				/*	if (objectIt->second->getName().find("weapon") != std::string::npos)
					{
						ObjectStaticWeapon * weapon = dynamic_cast<ObjectStaticWeapon *> (objectIt->second);
						if (weapon)
						{
							sprite->setBulletType(weapon->getBulletType());
							objectIt->second->die();
						}
						else
						{
							ObjectCapsuleWeapon * weaponAnother = dynamic_cast<ObjectCapsuleWeapon *> (objectIt->second);
							if (weaponAnother->getBulletType() == BulletTypes::D)
							{
								Sound::getInstance()->play("weaponD", false, 1);
								for (int i = 0; i < bulletSprites.size(); i++)
								{
										bulletSprites[i]->die();
								}

								for (auto it = EnemyMap.begin(); it != EnemyMap.end(); it++)
								{
										it->second->die();
								}

								for (auto it = objectMap.begin(); it != objectMap.end(); it++)
								{
										it->second->die();
								}
							}
							else
							{
									sprite->setBulletType(weaponAnother->getBulletType());
							}

							objectIt->second->die();
						}
					}
					*/
				}
			}
		}

	}



#pragma endregion 


#pragma region EnemyvsPlayer
	/*for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		RectF r = it->second->getBody();
		if (sprite->isHittable() && r.checkCollision(sprite->getBody()) && !it->second->isThroughable())
		{
			if (sprite->isUndying())
			{
				if (it->second->isHittable())
					it->second->die();
			}
			else
				sprite->die();
		}

	}*/
#pragma endregion 


#pragma region EnemyBulletvsPlayer
	/*for (int i = 0; i < bulletSprites.size(); i++)
	{
		Sprite* bulletE = bulletSprites[i];
		if (sprite->isHittable() && bulletE->getBody().checkCollision(sprite->getBody()))
		{
			bulletE->die();
			if (!sprite->isUndying())
				sprite->die();

			break;
		}
	}*/
#pragma endregion 

#pragma region playerBulletvsEnemy

	/*std::vector < BulletSprite* >& bullets = sprite->getBullets();
	for (int bulletIt = 0; bulletIt < bullets.size(); bulletIt++)
	{
		for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			EnemySprite* tempE = EnemyIt->second;
			RectF rB = tempB->getBody();
			RectF rE = tempE->getBody();
			if (rE.checkCollision(rB) && EnemyIt->second->isHittable())
			{
				tempE->beShooted(sprite->getDamage(), sprite->getIndex());
				tempB->die();
				break;
			}
		}
	}

	for (int bulletIt = 0; bulletIt < bullets.size(); bulletIt++)
	{
		for (int enemyBullet = 0; enemyBullet < bulletSprites.size(); enemyBullet++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			BulletSprite* tempE = bulletSprites[enemyBullet];
			RectF rB = tempB->getBody();
			RectF rE = tempE->getBody();
			if (rE.checkCollision(rB) && bulletSprites[enemyBullet]->isHittable())
			{
				tempE->die();
				tempB->die();
				break;
			}
		}

	}*/

#pragma endregion 

#pragma region playerBulletvsObjetSprite

	/*for (int bulletIt = 0; bulletIt < bullets.size(); bulletIt++)
	{
		for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			ObjectSprite* tempE = objectIt->second;
			RectF rB = tempB->getBody();
			RectF rE = tempE->getBody();
			if (rE.checkCollision(rB) && objectIt->second->isHittable())
			{
				tempE->beShooted(sprite->getDamage());
				tempB->die();
				break;
			}
		}
	}*/

#pragma endregion  

	RectF cameraRect = cam->getRect();

#pragma region playervsCamera
	//sprite->onCameraCollision(cameraRect);
#pragma endregion 


	// update through rect list of player
	sprite->updateThroughRect();
}



void Map::onSupportPlayer(MegamanSprite* sprite)
{
	mapCollisionTree->clear();
	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree->insert(collisionRectFs[i]);
	}


#pragma region mapvsPlayer

	// player vs CollisionRects
	RectF r = sprite->getBody();
	//r.height += 1;
	r.y += r.height;
	r.height = 1;
	std::vector < CollisionRectF > returnList;
	mapCollisionTree->getObjectlist(returnList, r);

	bool isSupported = false;
	for (int i = 0; i < returnList.size(); i++)
	{
		if (r.checkCollision(returnList[i].rect))
		{
			sprite->setSupportCollisionRect(returnList[i]);
			isSupported = true;
			break;
		}

	}
	// player vs object Map
	if (!isSupported)
	{
		/*for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
		{
			if (objectIt->second->isPlayerCollisionable())
			{
				CollisionRectF* collisionRect = objectIt->second->getRefCollisionRect();
				if (r.checkCollision(collisionRect->rect))
				{

					if (objectIt->second->isAffectble())
						sprite->setSupportCollisionRect(collisionRect);
					isSupported = true;
					break;
				}
			}

		}*/
	}


	if (!isSupported)
	{
		sprite->onUnsupported();
		sprite->setSupportCollisionRect(CollisionRectF());
		sprite->setSupportCollisionRect(NULL);
	}

#pragma endregion 



}

void Map::onSupportSprite()
{
	mapCollisionTree->clear();
	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree->insert(collisionRectFs[i]);
	}

#pragma region EnemyvsMap


	/*for (std::map < int, EnemySprite* > ::iterator EnemyIt = EnemyMap.begin(); EnemyIt != EnemyMap.end(); EnemyIt++)
	{
		RectF r = EnemyIt->second->getBody();
		r.y += r.height;
		r.height = 1;
		std::vector < CollisionRectF > returnLists;
		mapCollisionTree->getObjectlist(returnLists, EnemyIt->second->getBody());

		bool isSupported = false;

		for (int i = 0; i < returnLists.size(); i++)
		{

			if (r.checkCollision(returnLists[i].rect))
			{
				EnemyIt->second->setSupportCollisionRect(returnLists[i]);
				isSupported = true;
				break;
			}

		}

		if (!isSupported)
		{
			for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end(); objectIt++)
			{
				if (objectIt->second->isEnemyCollisionable())
				{
					CollisionRectF collisionRect = objectIt->second->getCollisionRect();
					if (r.checkCollision(collisionRect.rect))
					{

						if (objectIt->second->isAffectble())
						{
							EnemyIt->second->setSupportCollisionRect(collisionRect);
							isSupported = true;
							break;
						}
					}
				}

			}
		}



		if (!isSupported)
		{
			EnemyIt->second->onUnsupported();
			EnemyIt->second->setSupportCollisionRect(CollisionRectF());
		}


	}
*/
#pragma endregion 
}


void Map::onUpdatePlayerProperties(MegamanSprite* sprite, Camera* cam)
{
	cleanPlayerBullet(cam, sprite);

	// update Enemy
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		it->second->setPlayerProperties(sprite->getCenterX(), sprite->getCenterY(), sprite->isDead());

	}
	// update obj
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it->second->setPlayerProperties(sprite->getCenterX(), sprite->getCenterY());
	}
}

void Map::onUpdate(Camera* cam)
{

	for (int i = 0; i < tileSets.size(); i++)
	{
		tileSets[i]->update();
	}



	cleanMap(cam);
	addEToMap(cam);



	// update Enemy
	for (std::map < int, EnemySprite* > ::iterator it = EnemyMap.begin(); it != EnemyMap.end(); it++)
	{
		it->second->update();
	}


	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		
		it->second->update();
	}


	for (std::vector < BulletSprite* > ::iterator it = bulletSprites.begin(); it != bulletSprites.end(); it++)
	{
		(*it)->update();
	}
}

float Map::getResX()
{
	return respawnX;
}
float Map::getResY()
{
	return respawnY;
}

RectF Map::getCameraTranslatePoint()
{
	return cameraTranslatePosition;
}

std::vector < std::string>&  Map::getSpriteNames()
{
	return spriteNames;
}

bool Map::isFinish()
{
	return bIsFinish;
}
#pragma endregion publicFunction


