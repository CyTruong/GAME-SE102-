#include "game.h"
#include "Cat.h"
#include "Zero.h"
#include "Megaman.h"
#include "dxGraphic.h"
#include "Animation.h"
game::game()
{
}


game::~game()
{
}

Zero* z;
Megaman* m;
long start;
LPDIRECT3DSURFACE9 back;// test nên xóa khi code ccái khác

Animation *ani;
int game::GameInit(HWND hWnd) {

	z = new Zero(hWnd);
	z->Start();

	m = new Megaman(hWnd);
	m->Start();

	start = GetTickCount();
	return 1;
}

void game::GameRun(HWND hWnd) {
	D3DXVECTOR3 position(122, 122, 0);
	D3DXVECTOR3 position2(488, 122, 0);

	if (dxGraphic::d3ddev->BeginScene())
	{
		D3DXVECTOR3 position(122,122, 0);
		D3DXVECTOR3 position2(488,122, 0);
	
		z->Update();
		m->Update();
		
		if (GetTickCount() - start > ANIMATIONUPDATEDELAY) {
			start = GetTickCount();
			dxGraphic::d3ddev->ColorFill(dxGraphic::backbuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
			z->animation_control->DrawCurrentFrame(position);
			m->animation_control->DrawCurrentFrame(position2);

		}
		
		dxGraphic::d3ddev->EndScene();
	}
	dxGraphic::d3ddev->Present(NULL, NULL, NULL, NULL);

}

int game::GameEnd(HWND hWnd) {

	return 1;
}