#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <fstream>
#include "define.h"
#include "rapidjson\document.h"
#include "rapidjson\filereadstream.h"
#include "rapidjson\istreamwrapper.h"

static class dxGraphic
{
public:
	static LPDIRECT3D9 d3d;
	static LPDIRECT3DDEVICE9 d3ddev;
	static	LPDIRECT3DSURFACE9 backbuffer;

public:
	static int InitDirect(HWND,int,int,int);
	static LPDIRECT3DSURFACE9 LoadSurface(char*, D3DCOLOR);
	static LPDIRECT3DTEXTURE9 LoadTexture(char*, D3DCOLOR);
	static rapidjson::Document LoadJSonDocument(char*);
	//Hàm chuẩn hóa đường dẫn đến file Resource
	static char* standardizedSourceName(char*);
};

