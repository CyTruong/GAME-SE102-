#include "game.h"
#include "Cat.h"
#include "Zero.h"
#include "dxGraphic.h"
#include "Animation.h"
game::game()
{
}


game::~game()
{
}

Zero* z;
LPDIRECT3DSURFACE9 back;// test nên xóa khi code ccái khác

Animation *ani;
int game::GameInit(HWND hWnd) {

	z = new Zero(hWnd);
	z->Start();

	return 1;
}

void game::GameRun(HWND hWnd) {
	if (dxGraphic::d3ddev->BeginScene())
	{


		D3DXVECTOR3 position(122,122, 0);

	
		z->Update();
		z->animation_control->DrawCurrentFrame(position);

		dxGraphic::d3ddev->EndScene();
	}
	dxGraphic::d3ddev->Present(NULL, NULL, NULL, NULL);

}

int game::GameEnd(HWND hWnd) {

	return 1;
}