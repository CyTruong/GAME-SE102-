#include "Game.h"



Game::Game(HWND hWnd)
{
	/*Graphics::create(hWnd);
	Sound::create(hWnd);
	SceneManager::getInstance()->createScene(new StartingScene());*/
}
void Game::Update()
{
	/*if (!SceneManager::GetInstance()->isSceneTransitioning())
	{
		SceneManager::getInstance()->getCurrentScene()->onUpdate();
	}
	else
	{
		SceneTransition::getInstance()->update();
		SceneManager::getInstance()->updateWithEffect();
	}*/
	SceneManager::GetInstance()->GetCurScene()->Update();

}

void Game::Draw()
{
	SceneManager::GetInstance()->GetCurScene()->draw();
}


void Game::Clean()
{
	//UIComponents::getInstance()->cleanUp();
	//Sound::getInstance()->cleanUp();
	//Graphics::getInstance()->cleanUp();	
}



Game::~Game()
{
}
