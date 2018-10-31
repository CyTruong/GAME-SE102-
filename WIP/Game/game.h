#pragma once
#include "define.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "dxgraphics.h" 
#include"SceneManager.h" 
#include"Scene.h" 

#include "PlayScene.h" 

//
//class game
//{
//public:
//	static int GameInit(HWND);
//	static void GameRun(HWND);
//	static int GameEnd(HWND);
//	game();
//	~game();
//};

class game
{
public:
	game(HWND);
	~game();

	void render();
	void update();
	void cleanup();



};

