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
	m->tranform->position = new Position(20, 2980);
	
	camera = new Camera();
	camera->setTarget(m);

	map = new Map(hwnd, "Blast Hornet Stage 2.json");
	map->Creat();
	//long start = GetTickCount(); 
}

PlayScene ::~PlayScene () 
{

} 




void PlayScene ::onCollision () {

}

void PlayScene::handlerInput()
{

}
void PlayScene::onUpdate() {
	m->Update();
	camera->Update();
	//map->getObjList(camera);
}

void PlayScene::render() {
	if (camera->position->pX <= 0)
		camera->position->pX = 0;
	if (camera->position->pY <= 0)
		camera->position->pY = 0;
// get instance graphics 
//	dxgraphics::getInstance(); 
	dxgraphics::getInstance()->beginRender(); 
//	dxgraphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND); 
	map->DrawScene(camera);


	
	D3DXVECTOR3 position2(m->tranform->position->pX - camera->position->pX, m->tranform->position->pY - camera->position->pY, 0);
		
			//	start = GetTickCount();
			//   dxgraphics::getInstance()->getDevice()->ColorFill(dxgraphics::getInstance()->getBackbuffer(), NULL, D3DCOLOR_XRGB(0, 0, 0));
	m->animation_control->DrawCurrentFrame(position2);

//	dxgraphics::getInstance()->getSpriteHandler()->End();
	dxgraphics::getInstance()->endRender(); 

}