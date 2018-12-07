#include "Scene1.h"


Scene1::Scene1()
{
	std::string mapName = "BlastHornetStage"  ;

	pMap = new Map(mapName);

	//Hcmt lifetexture -> HPTexture 

	/*lifeTexture = new Texture*[2];

	for (int i = 0; i < 2; i++)
	{
		lifeTexture[i] = NULL;
	}
*/

	// vpsize = tile size *15 o vuong  

	int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
	 viewPortSize = 17 * 15; 
	viewPort = new ViewPort(RectI(SCREEN_WIDTH / 2 - viewPortSize / 2, SCREEN_HEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));


	cam = new Camera(viewPort,10,760, viewPort->getPort(), RectF(5,760,205,205));

	pMegaman = new MegamanSprite*[1];

	pMegaman[0] = new MegamanSprite(0, 70,900, cam->getMoveDir());

	
	// Texture Hp 

	isPause = false;
	isFinish = false;
	isGameOver = false;
	nTransitionFrames = 5 * 60;
	count = 0;

	//  Hcmt éo care 

	//Sound::getInstance()->play("stage" + std::to_string(UIComponents::getInstance()->getCurrentStage()), true, 1);
}

Scene1 ::~Scene1()
{
	delete pMegaman;
	pMegaman = NULL;
	delete viewPort;
	viewPort = NULL;

	delete cam;
	cam = NULL;
	delete pMap;
	pMap = NULL;
	
	//del hp 

}

void Scene1::onCollision()
{
	
		pMap->onCollisionvsPlayer(pMegaman[0], cam);
	    pMap->onCollision(cam);
}

void Scene1::handlerInput()
{
	while (!KeyBoard::GetInstance()->isEmpty())
	{
		KeyEvent e = KeyBoard::GetInstance()->ReadPop_Key();
		
			if (e.getCode() == UIComponents::getInstance()->getKey(UIComponents::SELECT, 0))
			{
				if (e.isReleased())
				{
					isPause = !isPause;
				}
				break;
			}
			else if (e.getCode() == VK_F1)
			{
				if (e.isReleased())
				{
					//Sound::getInstance()->mute();
				}
			}
			else if (e.getCode() == VK_F2)
			{
				if (e.isReleased())
				{
					//Sound::getInstance()->unMute();
				   //	Sound::getInstance()->play("stage" + std::to_string(UIComponents::getInstance()->getCurrentStage()), true, 1);
				}
			}
			else if (!isPause)
			{
				char keyCode = e.getCode();
				//Nhớ sửa :d
				int i = 0;
				if (keyCode == UIComponents::getInstance()->getKey(UIComponents::RIGHT, i))
				{
					if (e.isPressed())
					{
						pMegaman[i]->getState()->onMovePressed(Direction::createRight());
					}
					else
					{
						pMegaman[i]->getState()->onMoveReleased(Direction::createRight());
					}
				}
				else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::LEFT, i))
				{
					if (e.isPressed())
					{
						pMegaman[i]->getState()->onMovePressed(Direction::createLeft());
					}
					else
					{
						pMegaman[i]->getState()->onMoveReleased(Direction::createLeft());
					}
				}
				else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::UP, i))
				{
					if (e.isPressed())
					{
						pMegaman[i]->getState()->onVeticalDirectionPressed(Direction::createUp());
					}
					else
					{
						pMegaman[i]->getState()->onVeticalDirectionReleased();
					}
				}
				else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::DOWN, i))
				{
					if (e.isPressed())
					{
						pMegaman[i]->getState()->onVeticalDirectionPressed(Direction::createDown());
					}
					else
					{
						pMegaman[i]->getState()->onVeticalDirectionReleased();
					}
				}
				else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::JUMP, i))
				{
					if (e.isPressed())
					{
						pMegaman[i]->getState()->onJumpPressed();
					}
					else
					{
						pMegaman[i]->getState()->onJumpRelease();
					}
				}
				else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::FIRE, i))
				{
					if (e.isPressed())
					{
						pMegaman[i]->getState()->onFirePressed();
					}
				}
			}
	}

	KeyBoard::GetInstance()->Clean();

}
void Scene1::onUpdate()
{
//	if (isGameOver)
//	{
//		count++;
//		if (count == nTransitionFrames)
//		{
//			//GameSaveLoad::getInstance()->checkAndSaveScore(UIComponents::getInstance()->getScore());
//			SceneManager::getInstance()->createSceneWithRandomTransition(new GameOverScene());
//			return;
//		}
//	}
//	else if (isFinish)
//	{
//		count++;
//		if (count == nTransitionFrames)
//		{
//			if (UIComponents::getInstance()->getCurrentStage() < 3)
//			{
//				UIComponents::getInstance()->setStage(UIComponents::getInstance()->getCurrentStage() + 1);
//				SceneManager::getInstance()->createScene(new LoadingScene());
//			}
//			else
//			{
//				SceneManager::getInstance()->createScene(new EndingScene());
//			}
//			return;
//		}
//	}

	this->handlerInput(); 

	// not nessc 

	if (!isPause)
	{
		Update();
		onCollision();

		isFinish = pMap->isFinish();
		/*int lifes = 0;
		for (int i = 0; i < nPlayers; i++)
		{
			lifes += UIComponents::getInstance()->getLifes(i);
		}
		if (lifes <= 0)
		{
			isGameOver = true;
		}*/
	}


}
void Scene1::render()
{
	
		Graphics::getInstance()->beginRender();
		Graphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		pMap->draw(cam);
		
				pMegaman[0]->draw(cam);

		//draw HP col 


		Graphics::getInstance()->getSpriteHandler()->End();
		Graphics::getInstance()->endRender();
	

}

void Scene1::Update()
{


	pMap->onUpdatePlayerProperties(pMegaman[0], cam);
	pMap->onUpdate(cam);
	
	
			pMap->onSupportPlayer(pMegaman[0]);

	
         	pMap->onSupportSprite();


			pMegaman[0]->update();

	

		cam->update(pMegaman[0]->getX(), pMegaman[0]->getY());
	


	for (int i = 0; i < nPlayers; i++)
	{
		if (!pMegaman[i]->isPlayerOver())
		{
			pMegaman[i]->setCameraRect(cam->getRect());
		}
	}

	//Hcmt ko can 


}