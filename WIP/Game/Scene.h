#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include "Camera.h"
#include "Map.h"
class Scene
{

public:
	Camera* camera ;
	Map* map ;
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void  render() = 0; 
	virtual  void onUpdate() = 0;
	virtual void handlerInput() = 0; 

};


