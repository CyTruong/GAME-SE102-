#pragma once
#include "ViewPort.h"
#include "iostream"
#include "Direction.h"
class CamPos
{
public:
	// a b  c 
	// x y1 y2
	// y x1 x2 
    float a, b, c; 

	// x , y, xy ; 
	int d; 
	CamPos() {}; 

	CamPos(float A, float  B, float C, int D) {

		a = A*16; 
		b = B * 16;
		c = C * 16;
		d = D; 

	}
	

private:

};


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
	CamPos * pCamPos; 

public:

	Camera(ViewPort* viewPort, float x, float y, RectF rect, RectF cameraTranslatePoint)
	{

		this->viewPort = viewPort;
		this->cameraTranslatePoint = cameraTranslatePoint;
		mapRect = rect;
		this->x =0;
		this->y = 16*44;
		pCamPos = new CamPos[2]; 

		pCamPos[0] = CamPos(44,0 ,45,0);
		pCamPos[1] = CamPos(46 ,14,59 , 1);


		/*this->x = x - (float)viewPort->getWidth() / 2.0f;
		this->y = y - (float)viewPort->getHeight() / 2.0f*/;

		//this->x = max(this->x, mapRect.x);
		//this->y = max(this->y, mapRect.y);

		//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

		moveDir = Direction::createRight();
		/*
				if (this->y == cameraTranslatePoint.y)
				{
					moveDir = Direction::createRight();
				}
				else if (this->x == cameraTranslatePoint.x)
				{
					moveDir = Direction::createUp();
				}*/
		vx = vy = 1.0f;

	}
	void setPosX(float x)
	{
		if (this->x < x - (float)viewPort->getWidth() / 2.0f && moveDir.isRight())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
		//	this->x = max(this->x, mapRect.x);
			//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		}


		else if (this->x > x - (float)viewPort->getWidth() / 2.0f && moveDir.isLeft())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
			//this->x = max(this->x, mapRect.x);
			//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());



		}


	
	}
	void setPosY ( float y)
	{
	


		if (this->y > y - (float)viewPort->getHeight() / 2.0f && moveDir.isUp())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());
		}

		else if (this->y < y - (float)viewPort->getHeight() / 2.0f && moveDir.isDown())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

		}
	}

	void setPosition(float x, float y)
	{
		if (this->x < x - (float)viewPort->getWidth() / 2.0f && moveDir.isRight())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		}


		else if (this->x > x - (float)viewPort->getWidth() / 2.0f && moveDir.isLeft())
		{
			this->x = x - (float)viewPort->getWidth() / 2.0f;
			this->x = max(this->x, mapRect.x);
			this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());



		}
			

		 if (this->y > y - (float)viewPort->getHeight() / 2.0f && moveDir.isUp())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());
		}
   
		else if (this->y < y - (float)viewPort->getHeight() / 2.0f && moveDir.isDown())
		{
			this->y = y - (float)viewPort->getHeight() / 2.0f;
			//this->y = max(this->y, mapRect.y);
			//this->y = min(this->y, mapRect.height + mapRect.y - viewPort->getHeight());

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
	void update(float x, float y, Direction d)

	{
		// kiem tra nam trong trục x or y 
		// thì chỉ thay đổi trục ngược lại
		string xx = to_string(x); 


	

		int a = x - (float)viewPort->getWidth()/2; 
		int b = y - (float)viewPort->getHeight()/2;
		moveDir = d;



		// 
		int f = 0; 

		for (int  i = 0; i < 2; i++)
		{
			if (pCamPos[i].d==0&&this->y==pCamPos[i].a&& this->x>=pCamPos[i].b && this->x <=pCamPos[i].c)
			{  
				setPosX(x); 
				f = 1; 
				LogWriter::getInstance()->write("xxxxxxxxx" + to_string(x) );
				LogWriter::getInstance()->write("yyyyyy" + to_string(y));
			}
			else
			if (pCamPos[i].d == 1 && this->x>= pCamPos[i].a-20 && this->x <= pCamPos[i].a + 20 && this->y>= pCamPos[i].b && this->y<= pCamPos[i].c)
			{
				setPosY(y);
				f = 1;
				LogWriter::getInstance()->write("yyyyyy" + to_string(y));
			}
			
			if (f == 1)
			{
				break;
			}


		}
		if (f==0)
		{
			setPosX(x);
			setPosY(y);
		}
	


		
		//setPosition(x, y);

	}


	Direction getMoveDir() { return moveDir; }
	ViewPort* getViewport() { return viewPort; }

};