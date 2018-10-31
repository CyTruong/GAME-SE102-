#pragma once

#include "Scene.h"
#include "dxgraphics.h" 

#include"Megaman.h"

class PlayScene : public Scene 
{
public:
	PlayScene(HWND );
	virtual ~PlayScene();
	virtual void onCollision();
	virtual void handlerInput();
	virtual void render();
	virtual void onUpdate();
	virtual void update();
private:
		// map 
	    // view port 
	    //camara  
	Megaman * m; 


};