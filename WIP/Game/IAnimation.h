//#pragma once
//#include <d3d9.h>
//#include <d3dx9.h>
//#include "define.h"
//class IAnimation
//{
//public:
//	
//	/*khởi tạo animation
//	Create(HWND hWnd,LPDIRECT3DDEVICE9 d3ddev, char* name,int framewidth,int frameheight,int numberofcolumn,int numberofsprite,int animationdelay)
//		hWnd 
//		d3ddev
//		name : tên file
//		framewidth : chiều rộng ảnh nhỏ
//		frameheight : chiều cao ảnh nhỏ
//		numberofcolumn : số animation trong 1 hàng
//		numberofsprite : số sprite trong file
//		animationdelay : độ trễ từng animation ( đơn vị tính frame )
//
//	*/
//	virtual int Create(HWND, LPDIRECT3DDEVICE9, char*, int, int, int, int,int) = 0;
//	virtual void DrawCurframe(D3DXVECTOR3) = 0;
//	virtual int Clear() = 0;
//
//
//	typedef struct
//	{
//		int x, y;
//		int width, height;
//		int curframe, lastframe;
//		int animationcount, animationdelay;
//		int column;
//	} SPRITE;
//};
//
//
