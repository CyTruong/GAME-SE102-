#pragma once
#include "rapidjson\document.h"
#include <d3d9.h>
#include <d3dx9.h>
class Map
{
public:
	char* JsonFileName;
	HWND hWnd;
public:
	Map(); 

	Map(HWND,char*);
	void Creat();
	~Map();
};

