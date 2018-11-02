#include"PlayScene.h"
//#include "Animation_Default.h" 

PlayScene::PlayScene(HWND hwnd )
{  
	// int map 
	// init viewport 
	// camara 
	// player 
	// ...   
	m = new  Megaman(hwnd); 

	//long start = GetTickCount(); 




}

PlayScene ::~PlayScene () 
{ } 




void PlayScene ::onCollision () {}
void PlayScene::handlerInput()
{
}
void PlayScene::onUpdate() { m->Update(); }
void PlayScene::update() {}
void PlayScene::render() {

	// get instance graphics 

//	dxgraphics::getInstance(); 


	dxgraphics::getInstance()->beginRender(); 
//	dxgraphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND); 

	    D3DXVECTOR3 position(122, 122, 0);
		D3DXVECTOR3 position2(488, 122, 0);
	
	
			
			
			
		
			//	start = GetTickCount();
			   dxgraphics::getInstance()->getDevice()->ColorFill(dxgraphics::getInstance()->getBackbuffer(), NULL, D3DCOLOR_XRGB(0, 0, 0));
				m->animation_control->DrawCurrentFrame(position2);

			


//	dxgraphics::getInstance()->getSpriteHandler()->End();
	dxgraphics::getInstance()->endRender(); 
	




}