#include "Scene1.h"


Scene1::Scene1()
{
	std::string mapName = "BlastHornetStage";

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


	cam = new Camera(viewPort, 70, 900, RectF(0, 760, 760, 250), RectF(7700, 760, 50, 500));



	pMegaman = new MegamanSprite(0, 70, 900, cam->getMoveDir());


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

	pMap->onCollisionvsPlayer(pMegaman, cam);
	 pMap->onCollision(cam);
}

void Scene1::handlerInput()
{
	while (!KeyBoard::GetInstance()->isEmpty())
	{
		KeyEvent e = KeyBoard::GetInstance()->ReadPop_Key();

		//xét is pause


		if (!isPause)
		{
			char keyCode = e.getCode();
			//Lưu ý lỗi michale jack
			if (keyCode == UIComponents::getInstance()->getKey(UIComponents::RIGHT))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onMovePressed(Direction::createRight());
				}
				else
				{
					pMegaman->getState()->onMoveReleased(Direction::createRight());
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::LEFT))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onMovePressed(Direction::createLeft());
				}
				else
				{
					pMegaman->getState()->onMoveReleased(Direction::createLeft());
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::UP))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onVeticalDirectionPressed(Direction::createUp());
				}
				else
				{
					pMegaman->getState()->onVeticalDirectionReleased();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::DOWN))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onVeticalDirectionPressed(Direction::createDown());
				}
				else
				{
					pMegaman->getState()->onVeticalDirectionReleased();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::JUMP))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onJumpPressed();
				}
				else
				{
					pMegaman->getState()->onJumpRelease();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::FIRE))
			{
				if (e.isPressed())
				{
					pMegaman->getState()->onFirePressed();
				}
				else
				{
					pMegaman->getState()->onFireRelease();
				}
			}
			else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::SLIDE)) {
				if (e.isPressed())
				{
					pMegaman->getState()->onSlidePressed();
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
	
	pMegaman->draw(cam);

	//draw HP col 


	Graphics::getInstance()->getSpriteHandler()->End();
	Graphics::getInstance()->endRender();


}

void Scene1::Update()
{

	//update vị trí của ng chơi cho enemy
	pMap->onUpdatePlayerProperties(pMegaman, cam);
	
	// update animation of tilesets in here
	pMap->onUpdate(cam);


	// check collision player and rect 

    
	//pMap->onSupportPlayer(pMegaman);

	// check collision enemy, boss, object vs Map 

	pMap->onSupportSprite();


	pMegaman->update();


	if (pMegaman->getMoveDir().isUp() )
	{
		int a = 0;

	}
	cam->update(pMegaman->getX(), pMegaman->getY(), pMegaman->getMoveDir());


	//update megaman theo cái cam
	pMegaman->setCameraRect(cam->getRect());




}