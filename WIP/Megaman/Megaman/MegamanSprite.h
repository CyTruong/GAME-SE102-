#pragma once
#include "Sprite.h"
#include "MegamanState.h"
#include "define.h"
#include "MegamanRunningState.h"
#include "MegamanStandingState.h"
#include "MegamanStartState.h"

class MegamanSprite : public Sprite
{
public:
	MegamanSprite(int index, float respawnX, float respawnY, Direction movedir);
	~MegamanSprite();
	virtual void update();
	virtual void draw(Camera* cam);
	void setCameraTo(Camera* cam);
	virtual SpriteState* getState()
	{
		return pData->pState;
	}
	virtual RectF getBody() { return pData->getBody(); }
	virtual void setBody(RectF r) { pData->body = r; }
	virtual float getVx() { return pData->vx; }
	virtual float getVy() { return pData->vy; }
	virtual float getX() { return pData->x; }
	virtual float getY() { return pData->y; }
	//hcmt 
	virtual Direction getMoveDir() { return pData->movedir; }


	virtual float getCenterX() { return pData->x; }
	virtual float getCenterY() { return pData->y - pData->ppTextureArrays[pData->iCurrentArr]->getHeight() / 2; }
	virtual void onUnsupported() { pData->pState->onFall(); }
	
	virtual void onCollision(RectF r) { pData->pState->onCollision(r); }
	virtual void onCollision(CollisionRectF r) { pData->pState->onCollision(r); }
	virtual void onDynamicObjectCollision(CollisionRectF* r) { pData->pState->onDynamicObjectCollision(r); }
	virtual void setSupportCollisionRect(CollisionRectF rect)
	{
		pData->cSupportRect = rect;
	}
	virtual void setSupportCollisionRect(CollisionRectF* rect)
	{
		pData->cDynamicSupportRect = rect;
	}
	
	virtual void updateThroughRect();

	std::vector<BulletSprite* >& getBullets() {
		return this->pData->Bullets;
	};

	virtual void die();
	virtual void onCameraCollision(RectF cameraRect);
	virtual bool isDesTroyed() { return pData->isDesTroyed; }
	virtual bool isHittable() { return pData->isHittable; }
	virtual int getDamage();
	void setCameraRect(RectF r);
	
	

	int getIndex()
	{
		return pData->index;
	}
	bool isPlayerOver()
	{
		return pData->isOver;
	}
	static void loadResources();

	bool isDead()
	{
		return pData->isDead;
	}
	bool isUndying()
	{
		return pData->isUndying;
	}

private:
	MegamanData* pData;
};