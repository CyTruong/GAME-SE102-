#pragma once

#include "SpriteData.h"
//#include "SBullet.h"
#include "CollisionRect.h"
#include "Define.h"
class MegamanData : public SpriteData
{

public:
	RectF* bodyRects;
	
	//std::vector<BulletSprite *> Bullets;
	int nFiringHoldFrames;
	int count;
	RectF cameraRect;
	///BulletTypes bulletType;
	int hittableCounter;
	int nonHittableFrames;
	int nUndyingFrames;
	int undyingCounter;
	int index;
	bool isOver;
	bool isRapid;
	bool isRespawn;
	bool isUndying;
	Direction movedir;

	bool isCharging;
	int ChargingCount;
public:
	MegamanData()
	{
		hittableCounter = 0;
		nonHittableFrames = 150;
		nFiringHoldFrames = 15;
		nUndyingFrames = 600;
		undyingCounter = 0;
		isOver = false;
		isRapid = false;
		isRespawn = true;
		isDead = false;
		isUndying = false;
	}
	enum SpriteArrayIndex
	{
		STAND,
		STANDSHOOT,
		RUN,
		RUNSHOOT,	
		JUMP,
		JUMPSHOOT,
		FALL,
		FALLSHOOT,
		SLIDE,
		SLIDESHOOT,
		COUNT
	};
	virtual void setiCurrentArray(int index)
	{
		iCurrentArr = index;
		body = bodyRects[index];
	}
	void reset()
	{
		this->x = cameraRect.x + 20;
		if (movedir.isRight())
		{
			this->y = cameraRect.y + 20;
		}
		else
			this->y = cameraRect.y + cameraRect.height / 2;
		this->isRespawn = true;
		this->isUndying = false;
		//this->bulletType = BulletTypes::S;
		this->isDead = false;
	}
	
};