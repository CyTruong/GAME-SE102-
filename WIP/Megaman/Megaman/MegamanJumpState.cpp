#include "MegamanJumpState.h"
// Note ; thêm sate là climpling, súng đạm, check collision
#include "MegamanSlideState.h"
#include"MegamanRunningState.h"
#include"MegamanStandingState.h"
#include"MegamanStandShootState.h"
#include "MegamanWallClimping.h"
MegamanJumpState::MegamanJumpState(MegamanData* data, bool ismove , float vy)
{

	this->pData = data;
	speedX = 1;
	pData->vy = vy;
	acceleration = 0.2f;

	this->isMoving = ismove;
	if (pData->vy < 0) {
		LogWriter::getInstance()->write("Start Jumpping");

		pData->setiCurrentArray(MegamanData::JUMP);
		isJumpingPress = true;
	}
	else
	{
		LogWriter::getInstance()->write("Start Falling");

		pData->setiCurrentArray(MegamanData::FALL);
		isJumpingPress = false;
	}
	tempDir = pData->dir;
}


MegamanJumpState::~MegamanJumpState()
{
}

void MegamanJumpState::onMovePressed(Direction dir)
{
	pData->dir = dir;
	tempDir = dir;
	isMoving = true;
}

void MegamanJumpState::onMoveReleased(Direction dir)
{
	tempDir = tempDir ^ dir;
	if (!tempDir.isNone())
	{
		pData->dir = tempDir;
	}
	else
		isMoving = false;
}

void MegamanJumpState::onJumpRelease()
{
	//shott here
}

void MegamanJumpState::onSlidePressed()
{
	transition(new MegamanSlideState(pData));
}

void MegamanJumpState::onCollision(RectF rect)
{
	// có 4 trường hợp va chạm
	float vx = pData->vx;
	float vy = pData->vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = rect.y;
	float leftR = rect.x;
	float rightR = leftR + rect.width;
	float bottomR = topR + rect.height;

	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->vy = 0.0f;
				pData->y -= py;

		

				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// va chạm bên phải
				pData->x -= px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				//va chạm bên trái
				pData->x -= px;
				pData->vx = 0.0f;
			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;
				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
	}
}

void MegamanJumpState::onCollision(CollisionRectF rect)
{
	LogWriter::getInstance()->write("Jump collision "+ rect.type );
	// có 4 trường hợp va chạm
	float vx = pData->vx;
	float vy = pData->vy;
	float top = pData->getBody().y;
	float left = pData->getBody().x;
	float right = left + pData->getBody().width;
	float bottom = top + pData->getBody().height;


	float topR = rect.rect.y;
	float leftR = rect.rect.x;
	float rightR = leftR + rect.rect.width;
	float bottomR = topR + rect.rect.height;

	if (vx > 0.0f)
	{
		if (vy > 0.0f)
		{
			float px = right - leftR;
			float py = bottom - topR;
			if (vy * px > vx * py)
			{
				// va chạm phía trên 
				pData->vy = 0.0f;
				pData->y -= py;

					if (isMoving)
					{
						transition(new MegamanRunningState(pData));
					}
					else
					{
						transition(new MegamanStandingState(pData));
					}
			}
			else
			{
				// va chạm bên phải
				pData->x -= px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = right - leftR;
			float py = bottomR - top;
			if ((-vy * px) > vx * py)
			{
				//va chạm trên
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				//va chạm bên trái
				pData->x -= px;
				pData->vx = 0.0f;
			}
		}
	}
	else // vx <= 0.0f
	{
		if (vy > 0.0f)
		{
			float px = rightR - left;
			float py = bottom - topR;
			if (vy * px > (-vx * py))
			{
				// top collision

				pData->y -= py;
				pData->vy = 0.0f;

				if (isMoving)
				{
					transition(new MegamanRunningState(pData));
				}
				else
				{
					transition(new MegamanStandingState(pData));
				}
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
		else // vy <= 0.0f
		{
			float px = rightR - left;
			float py = bottomR - top;
			if ((-vy * px) > (-vx * py))
			{
				// top collision
				pData->y += py;
				pData->vy = 0.0f;
			}
			else
			{
				// side collision
				pData->x += px;
				pData->vx = 0.0f;
			}
		}
	}
}

void MegamanJumpState::onDynamicObjectCollision(CollisionRectF * cRect)
{
	// va chạm vs đám obj

}

void MegamanJumpState::onUpdate()
{
	hittableCalculation();
	undyingCalculation();
	pData->ppTextureArrays[pData->iCurrentArr]->update();


	if (pData->isCharging) {
		pData->ChargingCount++;
		pData->bulletSize = getSizeofBullet(pData->ChargingCount);
		pData->ppTextureArrays[pData->bulletSize]->update();
	}

	

	if (isMoving)
	{
		pData->vx = pData->transform(speedX);
	}
	else
	{
		pData->vx = 0.0f;
	}
	pData->vy += acceleration;

	if (pData->vy>= 0 && !pData->isFrire) {
		pData->setiCurrentArray(MegamanData::FALL);
		isJumpingPress = false;
	}
	
	if (pData->isFrire && pData->iCurrentArr == MegamanData::FALL) {
		pData->setiCurrentArray(MegamanData::FALLSHOOT);
	}else
	if (!pData->isFrire && pData->iCurrentArr == MegamanData::FALLSHOOT) {
		pData->setiCurrentArray(MegamanData::FALL);
	}

	if (pData->isFrire) {
		pData->FireCountFrames++;
		if (pData->FireCountFrames > FIRE_COUNTING_FRAME) {
			pData->FireCountFrames = 0;
			pData->isFrire = false;
		}
	}


	pData->x += pData->vx ;
	pData->y += pData->vy ;


}

void MegamanJumpState::onFirePressed()
{
	pData->isCharging = true;

}

void MegamanJumpState::onFireRelease()
{
	if (!this->pData->isFrire) {
		pData->isCharging = false;
		pData->isFrire = true;
		pData->ChargingCount = 0;


		float bulletX;
		float bulletY;
		float angle;

		if (pData->dir.isRight())
		{
			bulletX = pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}
		else
		{
			bulletX = -pData->ppTextureArrays[pData->iCurrentArr]->getWidth() / 2 + pData->x;
		}

		bulletY = pData->y - pData->ppTextureArrays[pData->iCurrentArr]->getHeight() * 5 / 12 + 3;


		if (pData->dir.isRight())
		{
			angle = 0.0f;
		}
		else
		{
			angle = M_PI;
		}
		createBullet(bulletX, bulletY, angle);
	}
}

void MegamanJumpState::onVeticalDirectionPressed(Direction d)
{
	pData->verticalDir = d;
}

void MegamanJumpState::onVeticalDirectionReleased()
{
	pData->verticalDir = Direction::createNone();
	pData->setiCurrentArray(MegamanData::RUN);

}

void MegamanJumpState::onDead()
{
}
