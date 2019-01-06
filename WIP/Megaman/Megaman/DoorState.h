#pragma once

#include"ObjectState.h"
#include"DoorSprite.h"
#include "DoorData.h"
#include "Object.h"
class DoorState : public ObjectState 

{
public:

	DoorState(ObjectData * pdata);
	~DoorState();
	void onUpdate();
	void onCollision(RectF rect) ;
	void onCollision(CollisionRectF rect);
	void onCollision(Object  obj);

	
	


private:
	bool isMegamanPassing; 

	int counting; 


};


