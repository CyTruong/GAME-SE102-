#pragma once
#include "Scene.h"
#include "Camera.h"
#include"Viewport.h"
#include "MegamanSprite.h"
#include"MegamanState.h"
#include "KeyBoard.h" 

#include"Map.h"


class Scene1 : public Scene
{
public: 



	Scene1();
	virtual ~Scene1();

	virtual void onCollision();
	virtual void handlerInput();
	virtual void render();
	virtual void onUpdate();
	virtual void update();


private:
	MegamanSprite** pMegaman;
	ViewPort* viewPort;
	Camera* cam;
	Map* pMap;

	
	
	//->texture **hp 
	//Texture** lifeTexture;
	int nTransitionFrames;
	int count;
	int stageIndex;
	bool isGameOver;
	bool isFinish;
	bool isPause;
	int nPlayers;
// shader lightign 
};

