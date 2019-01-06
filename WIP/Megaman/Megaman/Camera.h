#pragma once
#include "ViewPort.h"
#include "iostream"
#include "Direction.h"

#define ss 12
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
	int NumberOfcamPos; 

public:

	Camera(ViewPort* viewPort, float x, float y, RectF rect, RectF cameraTranslatePoint)
	{

		this->viewPort = viewPort;
		this->cameraTranslatePoint = cameraTranslatePoint;
		mapRect = rect;
		this->x =0;
		this->y = 16*48;
		NumberOfcamPos = 17;
		pCamPos = new CamPos[NumberOfcamPos];

		pCamPos[0] = CamPos(48,0 ,48,0);
		pCamPos[1] = CamPos(48 ,24,64, 1);
		pCamPos[2] = CamPos(24, 48, 63, 0);
	    pCamPos[3] = CamPos(16, 48, 63, 0);
		//pCamPos[4] = CamPos(24, 56, 63, 0); 
		
		pCamPos[4] = CamPos(16, 63, 74, 0);



		

		pCamPos[5] = CamPos(16, 74, 99, 0);



//pCamPos[10] = CamPos(96, 32, 70, 1); 
	  

		pCamPos[6] = CamPos(64,99 ,112 , 0);
		
		pCamPos[7] = CamPos(64, 112, 145, 0);
		//boss 1 
		pCamPos[8] = CamPos(64, 144.5, 0, 2); 

		pCamPos[9] = CamPos(64, 159, 185, 0);

		pCamPos[10] = CamPos(64, 185, 261, 0);
		pCamPos[11] = CamPos(64, 261, 368, 0);

		pCamPos[12] = CamPos(67, 261, 368, 0);
		pCamPos[13] = CamPos(64, 266, 368, 0);

		//pCamPos[11] = CamPos(48, 0, 48, 0);
		//pCamPos[12] = CamPos(46, 14, 59, 1);
		pCamPos[14] = CamPos(368, 64, 106, 1);

		pCamPos[15] = CamPos(106,368 ,480 , 0);

		pCamPos[16] = CamPos(108, 368, 480, 0);

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
	void setPosX(float x )
	{
		int a = x - viewPort->getWidth() / 2.0f;

		
		if (this->x < a && moveDir.isRight())
		{  
			//

			this->x = a;

		//	this->x = max(this->x, mapRect.x);
			//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());
		}


		else if (this->x > x - (float)viewPort->getWidth() / 2.0f && moveDir.isLeft())
		{
			this->x = a;
			//this->x = max(this->x, mapRect.x);
			//this->x = min(this->x, mapRect.width + mapRect.x - viewPort->getWidth());



		}


	
	}
	void setPosY ( float y )
	{
	
		int b = y - viewPort->getHeight() / 2.0f;

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
	void update(float x, float y, Direction d, int isCamStop )

	{
		

		// kiem tra nam trong trục x or y 
		// thì chỉ thay đổi trục ngược lại
		string xx = to_string(x); 


	

		int a = x - (float)viewPort->getWidth()/2; 
		int b = y - (float)viewPort->getHeight()/2;
		moveDir = d;



		// var xac dinh di qua boss1 chua va toi boss 2 chua 



		int f = 0; 
		int j = 0; 
		for (int  i = 0; i <NumberOfcamPos; i++)
		{  
			if (j < NumberOfcamPos - 1)
			{

				if (f == 1 && pCamPos[j].d == 0 && pCamPos[j + 1].d == 0)
				{
					if (pCamPos[j + 1].a - pCamPos[j].a < 120 / 16)
					{
						this->y = pCamPos[j + 1].a;
						f = 1;
						break;


					}


				}
				else
					if (f == 2 && pCamPos[j].d == 1 && pCamPos[j + 1].d == 1)
					{
						if (pCamPos[j + 1].a - pCamPos[j].a < 120 / 16)
						{
							this->x = pCamPos[j + 1].a;
							f = 2;
							break;

						}
					}

			}

			if (isCamStop==1)
			{
			if (pCamPos[i].d==2&&this->x==pCamPos[i].b&&this->y == pCamPos[i].a)
			{ 
	     		f = 3; 
				j = i; 
				break;
			}

			}


			if (f!=2&&pCamPos[i].d==0&&this->y==pCamPos[i].a&& a>=pCamPos[i].b-ss && a <=pCamPos[i].c+ ss)
			{  
				
			

				if (a<pCamPos[i].b)
				{
					x = 120 + pCamPos[i].b; 
				}
				if (a>pCamPos[i].c)
				{
					x = 120 + pCamPos[i].c;

				}

				j = i; 
				setPosX(x); 
				f = 1; 
				
				
			}
			
		
			if (f!=1 &&pCamPos[i].d == 1 && this->x==pCamPos[i].a && b>= pCamPos[i].b- ss && b<= pCamPos[i].c+ ss)
			{
				if (b < pCamPos[i].b)
				{
					y = 120 + pCamPos[i].b;
				}
				if (b > pCamPos[i].c)
				{
					y = 120 + pCamPos[i].c;

				}
				j = i;
				setPosY(y);
				f = 2;

			

			}
		
			
			
		/*	if (f == 1)
			{
				break;
			}*/


		}
		


		if (f==0)
		{    
			setPosX(x);
			setPosY(y);

		}
	


		
		//setPosition(x, y);
		LogWriter::getInstance()->write(this->x, this->y);
		LogWriter::getInstance()->write("xy cam ");
	}


	

	Direction getMoveDir() { return moveDir; }
	ViewPort* getViewport() { return viewPort; }

};