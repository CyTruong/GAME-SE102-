


// its mine 
#pragma once 

#include"game.h"




game::game(HWND hwnd)
{
	dxgraphics::create(hwnd);

	SceneManager::GetInstance()->createScene(new PlayScene(hwnd ));
	//maybe sound here    


}

game::~game()
{}


void game::render() {

	SceneManager::GetInstance()->GetCurScene()->render();



}
void game::update() {
	SceneManager::GetInstance()->GetCurScene()->onUpdate();

}

void game::cleanup() {
	dxgraphics::getInstance()->cleanUp();

}

