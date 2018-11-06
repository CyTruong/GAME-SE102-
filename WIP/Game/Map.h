#pragma once
#include "rapidjson\document.h"
#include "Camera.h"
#include "Gameobject.h"
#include <d3d9.h>
#include <d3dx9.h>
class Map
{
public:
	typedef struct
	{
		LPDIRECT3DTEXTURE9 mapTexture;
		int tileHeight, tileWidth;
		int width, height;
		char* name;
	}MapFile;

public:
	char* jsFileSource;
	HWND hWnd;
	Document jsMapDocument;
	MapFile mapFile;
	LPD3DXSPRITE sprite_handler;

public:
	Map(); 
	Map(HWND,char*);
	int	 Creat();
	vector<Gameobject*> getObjList(Camera* );
	void DrawScene(Camera *);
	~Map();

private:
	void LoadTexture(char*);
};

