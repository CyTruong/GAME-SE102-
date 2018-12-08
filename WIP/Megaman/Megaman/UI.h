#pragma once
//#include "Sound.h"
#include "Windows.h"
#include<string> 

// Hp 

//class Hp
//{
//public: 
//	Hp();
//	~Hp();
//
//private:
//
//};
//
//Hp::Hp()
//{
//}
//
//Hp::~Hp()
//{
//}

class UIComponents
{
public:
	enum
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		FIRE,
		JUMP,
		SELECT,
		COUNT
	} KEY;
	~UIComponents();
	static UIComponents* getInstance();
	int getLifes();
	int getScore();
	void inscreaseLifes();
	void descreaseLifes();
	void addScore(int val);
	void setStage(int val);
	void gameOverReset();
	char getKey(int index);
	void setKey(int index, char keyCode);
	char getDefaultKey(int index);
	void setDefaultKeyBoard();
	void resetStage();
	bool isAllowedKey(char keyCode);
	void cleanUp();
private:
	static UIComponents* instance;
	UIComponents();
	int score;
	int currentStage;
	int lifes;
	unsigned int nPlayers;
	char configKeyBoard[COUNT];
	char defaultKeyBoard[COUNT];
};

