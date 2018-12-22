#pragma once
#include "Sound.h"
#include "Windows.h"
#include<string> 

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
		SLIDE,
		SELECT,
		COUNT
	} KEY;
	~UIComponents();
	static UIComponents* getInstance();
	int getMegamanHp();
	int getScore();
	void inscreaseMegamanHp();
	void descreaseMegamanHp();
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
	int Megamanhp;
	char configKeyBoard[COUNT];
	char defaultKeyBoard[COUNT];
};

