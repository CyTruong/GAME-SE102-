#include "IAnimation.h"

class Defaut_Animation : IAnimation
{
private:
	LPD3DXSPRITE sprite_handler;
	LPDIRECT3DTEXTURE9 sprite_texture;
	SPRITE sprite_control;

public:
	int Create(LPDIRECT3DDEVICE9 d3ddev,char* spritename) 
	{

	}

};