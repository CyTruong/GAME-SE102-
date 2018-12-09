#include "UI.h"
//#include "Sound.h"
#include <time.h>
UIComponents* UIComponents::instance = nullptr;

UIComponents* UIComponents::getInstance()
{
	if (instance == nullptr)
	{
		instance = new UIComponents();
	}
	return instance;
}

UIComponents::UIComponents()
{
	score = 0;
	lifes = 10;
	currentStage = 1;
	nPlayers = 1;

	configKeyBoard[LEFT] = defaultKeyBoard[LEFT] = VK_LEFT;
	configKeyBoard[RIGHT] = defaultKeyBoard[RIGHT] = VK_RIGHT;
	configKeyBoard[UP] = defaultKeyBoard[UP] = VK_UP;
	configKeyBoard[DOWN] = defaultKeyBoard[DOWN] = VK_DOWN;
	configKeyBoard[FIRE] = defaultKeyBoard[FIRE] = 0x43;  //C
	configKeyBoard[JUMP] = defaultKeyBoard[JUMP] = 0x58;  //X
	configKeyBoard[SLIDE] = defaultKeyBoard[SLIDE] = 0x5A; //Z	
	configKeyBoard[SELECT] = defaultKeyBoard[SELECT] = VK_RETURN;
}


UIComponents::~UIComponents()
{
}


int UIComponents::getLifes()
{
	return lifes;
}
int UIComponents::getScore()
{
	return score;
}


// Inscrease Hp 
void UIComponents::inscreaseLifes()
{
	//play sound nếu có
	lifes++;
}
// descrease Hp 
void UIComponents::descreaseLifes()
{
	lifes--;
		
		//Sound::getInstance()->stop();

}

// add Hp 
void UIComponents::addScore(int val)
{

	score += val;
}
void UIComponents::setStage(int val)
{
	currentStage = val;
}
void UIComponents::resetStage()
{
	currentStage = 1;
}
void UIComponents::gameOverReset()
{
	score = 0;

}

// chua can thiet 

char UIComponents::getKey(int index)
{
	return configKeyBoard[index];
}

char UIComponents::getDefaultKey(int index)
{
	return defaultKeyBoard[index];
}

void UIComponents::setKey(int index, char keyCode)
{
	//kiểm tra xe nếu key đó đã set
	configKeyBoard[index] = keyCode;
}

void UIComponents::setDefaultKeyBoard()
{
	_memccpy(configKeyBoard, defaultKeyBoard, NULL, sizeof(configKeyBoard));
}
	
bool UIComponents::isAllowedKey(char keyCode)
{
	if (keyCode >= 65 && keyCode <= 90 || (keyCode >= VK_NUMPAD0 && keyCode <= VK_NUMPAD9) || keyCode == VK_SPACE)
	{
		return true;
	}
	for (int i = 0; i < COUNT; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (defaultKeyBoard[i] == keyCode)
				return true;
		}
	}

	return false;
}


void UIComponents::cleanUp()
{
	delete this;
}