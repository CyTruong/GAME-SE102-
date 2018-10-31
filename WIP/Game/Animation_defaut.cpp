//#include "Animation_defaut.h"
//#include "dxgraphics.h"
//
//
//
//int Animation_defaut::Create(HWND hWnd,LPDIRECT3DDEVICE9 d3ddev, char* name,int framewidth,int frameheight,int numberofcolumn,int numberofsprite,int animationdelay)
//{
//	char source[50];
//	HRESULT result;
//	result = D3DXCreateSprite(d3ddev, &sprite_handler);
//	if (result != D3D_OK)
//	{
//		MessageBox(hWnd,"Somthing wrong when creat sprite handler","error",MB_OK);
//		return 0;
//	}
//	strcpy_s(source, SPRITE_SOURCE);
//	strcat_s(source, name);
//
//	sprite_texture = dxgraphics::LoadTexture(source,D3DCOLOR_XRGB(0,0,0));
//	if (sprite_texture == NULL) 
//	{
//		MessageBox(hWnd, "Load Textture faild", "error", MB_OK);
//		return 0;
//	}
//
//	sprite_control.x = 0;
//	sprite_control.y = 0;
//	sprite_control.height = frameheight;
//	sprite_control.width = framewidth;
//	sprite_control.curframe = 0;
//	sprite_control.lastframe = numberofsprite;
//	sprite_control.column = numberofcolumn;
//	sprite_control.animationcount = 0;
//	sprite_control.animationdelay = animationdelay;
//	start = GetTickCount();
//}
//
//void Animation_defaut::DrawCurframe(D3DXVECTOR3 position)
//{
//
//	if (GetTickCount() - start > ANIMATIONUPDATEDELAY) {
//		start = GetTickCount();
//		sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);
//
//		//test
//		dxgraphics::getInstance()->getDevice()->ColorFill(dxgraphics::getInstance()->getBackbuffer(), NULL, D3DCOLOR_XRGB(0, 0, 0));
//
//		int left = (sprite_control.curframe % sprite_control.column) * sprite_control.width;
//		int top = (sprite_control.curframe / sprite_control.column) * sprite_control.height;
//		int right = left + sprite_control.width;
//		int bottm = top + sprite_control.height;
//		
//		RECT rect = { left,top,right,bottm };
//
//		sprite_handler->Draw
//		(
//			sprite_texture,
//			&rect,
//			NULL,
//			&position,
//			D3DCOLOR_XRGB(255, 255, 255)
//		);
//
//		if (++sprite_control.animationcount > sprite_control.animationdelay) {
//			sprite_control.animationcount = 0;
//			if (++sprite_control.curframe >= sprite_control.lastframe)
//			{
//				sprite_control.curframe = 0;
//			}
//		}
//		sprite_handler->End();
//	}
//}
//
//int Animation_defaut::Clear() {
//	return 1;
//}