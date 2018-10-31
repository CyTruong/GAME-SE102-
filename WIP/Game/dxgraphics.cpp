#pragma once 
#include "dxgraphics.h"
#include "define.h"
//LPDIRECT3D9 dxgraphics::d3d = NULL;
//LPDIRECT3DDEVICE9 dxgraphics::d3ddev = NULL;
//LPDIRECT3DSURFACE9 dxgraphics::backbuffer = NULL;

dxgraphics::dxgraphics(HWND hWnd)
{


	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d == NULL) {
		MessageBox(hWnd, "Error when creat 3d3", "Error", MB_OK);
	}
	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
							  //d3dpp.Windowed = FALSE; // program fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D

	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;

	// create a device class using this information and the info from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev); 

	int x = GetLastError();
	if (d3ddev == NULL) {
		MessageBox(hWnd, "Something false the creat d3d device", "Error", MB_OK);
	}

	// create pointer sprite handler 
   	D3DXCreateSprite(d3ddev, &pSpriteHandler);

}

dxgraphics::~dxgraphics()
{
	/*
		if (!backbuffer)
		{
			backbuffer->Release();

		}

		if (!d3ddev)
		{
			d3ddev->Release();

		}

		if (!d3d)
		{
			d3d->Release();

		}*/



}
dxgraphics * dxgraphics::instance = nullptr; 

dxgraphics*  dxgraphics::getInstance()
{

	return instance;
}


LPDIRECT3DDEVICE9 dxgraphics::getDevice() {
	return d3ddev;
}
LPDIRECT3DSURFACE9 dxgraphics::getBackbuffer()
{
	return backbuffer;
}
LPD3DXSPRITE dxgraphics::getSpriteHandler() {
	return pSpriteHandler;

}

void dxgraphics::beginRender()
{
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 0.0f, 0);
	d3ddev->BeginScene();
}
void dxgraphics::endRender() {

	d3ddev->EndScene();
	// check 
	d3ddev->Present(NULL, NULL, NULL, NULL);

}

LPDIRECT3D9 dxgraphics::getD3d()
{
	return d3d;
}

//
//int dxgraphics::Init_Direct3D(HWND hWnd, int screen_width, int screen_height, int fullscreen)
//{
//
//     d3d = Direct3DCreate9(D3D_SDK_VERSION);
//	if (d3d == NULL) {
//		MessageBox(hWnd, "Error when creat 3d3", "Error", MB_OK);
//		return 0;
//	}
//	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information
//
//	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
//	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
//							  //d3dpp.Windowed = FALSE; // program fullscreen
//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
//	d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D
//
//	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
//	d3dpp.BackBufferHeight = screen_height;
//	d3dpp.BackBufferWidth = screen_width;
//
//	// create a device class using this information and the info from the d3dpp stuct
//	d3d->CreateDevice(D3DADAPTER_DEFAULT,
//		D3DDEVTYPE_HAL,
//		hWnd,
//		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
//		&d3dpp,
//		&d3ddev);
//
//	int x = GetLastError();
//	if (d3ddev == NULL) {
//		MessageBox(hWnd, "Something false the creat d3d device", "Error", MB_OK);
//	}
//	//srand(time(NULL));
//
//	//clear backbuffer
//	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
//
//	//Create pointer to backbuffer
//	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
//
//	return 1;
//}

LPDIRECT3DSURFACE9 dxgraphics::LoadSurface(const char* name, D3DCOLOR trancolor) {
	LPDIRECT3DSURFACE9 image = NULL;
	D3DXIMAGE_INFO info;
	HRESULT result;

	result = D3DXGetImageInfoFromFile(name, &info);
	if (result != D3D_OK) {
		return NULL;
	}

	result = dxgraphics::getInstance()->getDevice()->CreateOffscreenPlainSurface
	(
		info.Width,
		info.Height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&image,
		NULL
	);

	if (result != D3D_OK) {
		return NULL;
	}

	result = D3DXLoadSurfaceFromFile
	(
		image,
		NULL,
		NULL,
		name,
		NULL,
		D3DX_DEFAULT,
		trancolor,
		NULL
	);

	if (result != D3D_OK)
	{
		return NULL;
	}

	return image;
}

LPDIRECT3DTEXTURE9 dxgraphics::LoadTexture(const char* name, D3DCOLOR trancolor) {
	//tạo 1 pointer to texture
	LPDIRECT3DTEXTURE9 texture = NULL;

	//reading info of image
	D3DXIMAGE_INFO info;

	HRESULT result;

	result = D3DXGetImageInfoFromFile(name, &info);

	if (result != D3D_OK) {
		return NULL;
	}

	D3DXCreateTextureFromFileEx
	(
		dxgraphics::getInstance()->getDevice() ,
		name,
		info.Width,
		info.Height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		trancolor,
		&info,
		NULL,
		&texture
	);
	// ??? check texture ! 

	/*if (result != D3D_OK)
	{
		return NULL;
	}*/

	return texture;
}


rapidjson::Document dxgraphics::LoadJSonDocument(char* name) {
	std::ifstream filedir(name);
	rapidjson::Document document;
	rapidjson::IStreamWrapper isw(filedir);
	document.ParseStream(isw);
	return document;
}

char* dxgraphics::standardizedSourceName(char* name) {
	char source[50];
	strcpy_s(source, SPRITE_SOURCE);
	strcat_s(source, name);
	return _strdup(source);
}
