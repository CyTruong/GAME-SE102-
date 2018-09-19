#include "game.h"
#include "Cat.h"
#include "dxGraphic.h"

game::game()
{
}


game::~game()
{
}

Cat *cat; 
LPDIRECT3DSURFACE9 back;// test nên xóa khi code ccái khác

int game::GameInit(HWND hWnd) {
//	back = dxGraphic::LoadSurface("E:\\Sprite\\game\\back.png", D3DCOLOR_XRGB(255, 255, 255));
	cat = new Cat(hWnd,dxGraphic::d3ddev );
	return 1;
}

void game::GameRun(HWND hWnd) {
	if (dxGraphic::d3ddev->BeginScene())
	{
//		dxGraphic::d3ddev->StretchRect(back, NULL, dxGraphic::backbuffer, NULL, D3DTEXF_NONE);

		D3DXVECTOR3 position(122,122, 0);

		cat->Update();
		cat->animation->DrawCurframe(position);

		dxGraphic::d3ddev->EndScene();
	}
	dxGraphic::d3ddev->Present(NULL, NULL, NULL, NULL);

}

int game::GameEnd(HWND hWnd) {
	cat->animation->Clear();
	delete cat;
	return 1;
}