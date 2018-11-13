/*
Đây là class nhằm lưu trữ 1 animation của 1 nhân vật nào đó 
1 Đồi tượng animation có thể chạy độc lậop nhưng tốt nhất là nên dc điều khiển bởi 1 Animation controler

*/

#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "rapidjson\document.h"
#include "dxgraphics.h"
#include "define.h"
using namespace rapidjson;

class State
{

public :
	typedef struct
	{
		D3DCOLOR trans_color;
		int titlesheet_colums;
		int titlesheet_height, titlesheet_width;
		char* source;
		int First_gid;
	}TITLESHEET;

	typedef struct
	{
		int* Arrdata;
		int Curframe_Id;
		int Animation_Numberofsprite;
		int Animation_Count;
		int Animation_Delay;
	}STATE_PROPERTIES
;

public:
	int ID;
	char* JsonFileName;
	long start;
	LPD3DXSPRITE sprite_handler;
	LPDIRECT3DTEXTURE9 sprite_texture;

	HWND hWnd;
	Document jsonDocument;
	TITLESHEET title_set;
	STATE_PROPERTIES state_properties;
public:
	
	State();
	//lần lượt là hWnd, tên file, trans color, AnimationDelay,AnimationID
	State(HWND, char*, D3DCOLOR,int,int);
	~State();
	int virtual Create();
	void virtual DrawCurframe(D3DXVECTOR3);
	void refresh();

	
	
};

