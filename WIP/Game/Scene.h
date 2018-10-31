#pragma once
#include <d3dx9.h>
#include <d3d9.h>

class Scene
{
public:

	Scene(){}
	virtual ~Scene() {};
	virtual void  render() = 0; 
	virtual  void onUpdate() = 0;
	virtual void handlerInput() = 0; 

};


