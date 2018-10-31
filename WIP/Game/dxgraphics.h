#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <fstream>
#include "define.h"
#include "rapidjson\document.h"
#include "rapidjson\filereadstream.h"
#include "rapidjson\istreamwrapper.h"



  class dxgraphics
{
public   :

	dxgraphics(HWND);
	static dxgraphics * instance;
	 LPDIRECT3D9 d3d;
	 LPDIRECT3DDEVICE9 d3ddev;
	 LPDIRECT3DSURFACE9 backbuffer;
	  LPD3DXSPRITE	pSpriteHandler;



public:
	~dxgraphics();
	static void create(HWND hwnd)
	{
		//if (instance = nullptr)
			instance = new dxgraphics(hwnd);

	}


	static dxgraphics * getInstance();
	void beginRender();
	void endRender();
	// ??? 
	LPDIRECT3D9 getD3d(); 
	LPDIRECT3DDEVICE9 getDevice(); 

	//??? 
	LPDIRECT3DSURFACE9 getBackbuffer();
	LPD3DXSPRITE getSpriteHandler();

	void cleanUp()
	{
		delete this;
	}


	//static int Init_Direct3D(HWND, int, int, int);
	static LPDIRECT3DSURFACE9 LoadSurface(const char*, D3DCOLOR);
	static LPDIRECT3DTEXTURE9 LoadTexture(const char*, D3DCOLOR);


	static rapidjson::Document LoadJSonDocument(char*);
	//Hàm chuẩn hóa đường dẫn đến file Resource
	static char* standardizedSourceName(char*);



};

