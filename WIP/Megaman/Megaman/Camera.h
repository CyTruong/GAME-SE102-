#pragma once
#include "ViewPort.h"
#include "iostream"
#include "Direction.h"
class Camera
{
private:
	ViewPort* viewPort;
	RectF mapRect;
	float x;
	float y;
	float vx;
	float vy;
	RectF cameraTranslatePoint;
	Direction moveDir;

public:

	Camera(ViewPort* viewPort, float x, float y, RectF rect, RectF cameraTranslatePoint)
	{
		this->viewPort = viewPort;
		this->cameraTranslatePoint = cameraTranslatePoint;
		mapRect = rect;
		this->x = x;
		this->y = y;
		this->x = x - (float)viewPort->getWidth() / 2.0f;
		this->y = y - (float)viewPort->getHeight() / 2.0f;

		this->x = max(this->x, mapRect.x);
		this->y = max(this->y, mapRect.y);

		this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

		moveDir = Direction::createRight();


		/*if (this->y == cameraTranslatePoint.y)
		{
			moveDir = Direction::createRight();
		}
		else if (this->x == cameraTranslatePoint.x)
		{
			moveDir = Direction::createUp();
		}*/
		vx = vy = 1.0f;

	}
	void setPosition(float x, float y)
	{ 
		if (x>100)
		{
			
		}
		if (this->x < x - (float)viewPort->getWidth() / 2.0f && moveDir.isRight())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		}
		else if (this->y > y - (float)viewPort->getHeight() / 2.0f && moveDir.isUp())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			this->y = max(this->y, mapRect.y);
			this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());
		}
	}



	int getWidth()
	{
		return viewPort->getWidth();
	}
	int getHeight()
	{
		return viewPort->getHeight();
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	RectF getRect()
	{
		return RectF(x, y, getWidth(), getHeight());
	}
	void update(float x, float y)
	{
		
		if (moveDir.isRight())
		{
			//if (this->x + getWidth() >= cameraTranslatePoint.x)
			//{
			//	setPosition(this->x + getWidth() / 2 + vx, y);
			//}
			//else
			//{
			//	setPosition(x, y);
			//}
			//hCmt 
			setPosition(x, y);
		}
		else
		{/*
			if (this->y <= cameraTranslatePoint.y + cameraTranslatePoint.height)
			{

				setPosition(x, this->y + getHeight() / 2 - vy);
			}
			else
			{
				setPosition(x, y);
			}*/
			setPosition(x, y); 

		}
	}


	Direction getMoveDir() { return moveDir; }
	ViewPort* getViewport() { return viewPort; }

};