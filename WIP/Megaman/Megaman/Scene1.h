#pragma once
#include "Scene.h"
#include "Camera.h"
#include"Viewport.h"
#include "MegamanSprite.h"
#include"MegamanState.h"
#include "KeyBoard.h" 
//


class Scene1 : public Scene
{
public:
	Scene1();
	virtual ~Scene1();

	virtual void OnCollision();
	virtual void handlerInput();
	virtual void render();
	virtual void onUpdate();
	virtual void Update();

};

