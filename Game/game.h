#pragma once
#include "define.h"
#include <d3d9.h>
#include <d3dx9.h>

class game
{
public:
	static int GameInit(HWND);
	static void GameRun(HWND);
	static int GameEnd(HWND);
	game();
	~game();
};

