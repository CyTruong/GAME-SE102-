#pragma once
#include "ObjectSprite.h"
#include "HPSprite.h"


class HPBarSprite :
	public ObjectSprite
{
private:
	float posX, posY;
	vector<HPSprite*> hpSprites;
	int hubType; 
public:
	HPBarSprite(Camera * & cam,float posX, float posY,int hubType );
	void onUpdate();
	void draw(Camera *cam) override;
	~HPBarSprite();
};

