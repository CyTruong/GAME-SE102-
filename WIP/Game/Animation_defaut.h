#pragma once
#include "IAnimation.h"
class Animation_defaut :
	public IAnimation
{
public:
	LPD3DXSPRITE sprite_handler;
	LPDIRECT3DTEXTURE9 sprite_texture;
	SPRITE sprite_control;
	long start;


public:
	int Create(HWND,LPDIRECT3DDEVICE9 , char* ,int,int,int,int,int) override;
	void DrawCurframe(D3DXVECTOR3) override;
	int Clear() override;
};

