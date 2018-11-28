#pragma once
#include <queue>
//Lớp lưu trữ các trạng thái của 1 Key, khi dc thêm vào hàng đợi

using namespace std;

class KeyEvent 
{
public:
	enum KeyType
	{
		PRESS,
		RELEASE,
		NULLKEY
	};
private:
	KeyType type;
	int keycode;

public:
	KeyEvent(KeyType, int keycode);
	int getCode();
	bool isPressed();
	bool isReleased();


};

//Lớp lưu trữ thông tin các key dc bấm , trình tự và trạng thái các key
class KeyBoard
{

private:

	static KeyBoard* Instance;

private:
	bool keyState[256];
	queue <KeyEvent> keyEventQueue; // hàng đợi lưu trữ các event

private:
	KeyBoard();

public:
	static KeyBoard* GetInstance();
	void onKeyPressed(int code);
	void onKeyReleased(int code);

	KeyEvent Read_Key(); //đọc sự kiện phím 
	KeyEvent ReadPop_Key(); //đọc và pop

	bool isPressed(int key);
	void Clean();
	bool isEmpty();

};

