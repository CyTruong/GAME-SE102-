#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <stdio.h>
#include "dxgraphics.h"
#include "game.h"


#define APPTITLE "AnImAtIoN"

int done = 0;

LRESULT WINAPI WinPro(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		// game::GameEnd(hWnd);
		if (dxgraphics::getInstance()->getDevice() != NULL)
		{
			dxgraphics::getInstance()->getDevice()->Release();
		}
		if (dxgraphics::getInstance()->getD3d() != NULL)
		{
			dxgraphics::getInstance()->getD3d()->Release();
		}
		
		PostQuitMessage(-3200);
		done = 1;
		return 0;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc; //wc = window class -> chứa tất cả thông tin của 1 window

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);	//kích thước trên bộ nhớ của window class này
	wc.style = 0;	//kiểu của Class, khác với kiểu của window (window style), thường có giá trị 0
	wc.lpfnWndProc = WinPro;	//thủ tục của window (window procedure) là con trỏ trỏ tới WinProc như ở trên (giải thích bên dưới, Bước 4)
	wc.cbClsExtra = 0;	//số lượng dữ liệu tối đa được cài đặt cho class này, thường có giá trị 0 (không cần quan tâm lắm, tìm hiểu sau)
	wc.cbWndExtra = 0;	//số lượng dữ liệu tối đa được cài đặt cho class này, thường có giá trị 0 (không cần quan tâm lắm, tìm hiểu sau)
	wc.hInstance = hInstance;	//Quản lý thông tin của cửa sổ, tương đương với giá trị ta khai báo ở WinMain() (tìm hiểu sau)
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//Icon lớn của class này, như đoạn code ở trên ta khai báo là icon có sẵn trong hệ thống, Icon này thẻ hiện ở (tìm hiểu sau)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	//tương tự như Icon nhưng ở đây là con trỏ
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	//tương tự như icon nhưng là background
	wc.lpszMenuName = NULL;	//con trỏ trỏ về dữ liệu của các thanh menu (tìm hiểu sau)
	wc.lpszClassName = APPTITLE;	//tên của class này, như trên là ta cài đặt tên có sẵn khai báo ở đầu bài
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);	//tương tự như icon nhưng là icon nhỏ, hiện ở bên trái cùng chương trình

	if (!RegisterClassEx(&wc)) // nên return về
	{
		MessageBox(NULL, "Cannot Register window", "Error", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreinstance, LPTSTR lpCmndLine, int nCmdShow)
{

	HWND hWnd;
	MyRegisterClass(hInstance);
	DWORD style;
	if (FULLSCREEN)
	{
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	}
	else
	{
		style = WS_OVERLAPPEDWINDOW;
	}
	hWnd = CreateWindow
	(
		APPTITLE,
		APPTITLE,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hWnd == NULL)
	{
		MessageBox(hWnd, "Something false when creat windown", "Error", MB_OK);
		return 0;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
/*
	if (!dxgraphics::Init_Direct3D(hWnd, SCREEN_WIDTH, SCREEN_HEIGHT, 0))
	{
		MessageBox(hWnd, "Somthing false when init directx ", "Error", MB_OK);
		return 0;
	}*/

	/*if (!dxInit_DirectXInput(hWnd))
	{
		MessageBox(hWnd, "Something false when init inout", "Error", MB_OK);
		return 0;
	}*/
	game game(hWnd);


	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);

	float secsPerCnt = 1.0f / (float)cntsPerSec;

	float delta = 0.0f;

	unsigned int nFrameCount = 0;

	float timeCount = 0;

	__int64 currTimeStamp = 0;

	__int64 prevTimeStamp = 0;

	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);
	MSG msg; // create the Message ( MSG) object the handle event
	ZeroMemory(&msg, sizeof(MSG));
	while (msg.message != WM_QUIT)
	{
		if (false &&PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {

			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);





		}
		else
		{

			bool render = false;

			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);

			double deltaTimeInMiliSecond = (double)(currTimeStamp - prevTimeStamp) * secsPerCnt * 1000.0f;
			prevTimeStamp = currTimeStamp;

			delta += deltaTimeInMiliSecond;
			timeCount += deltaTimeInMiliSecond;
			if (timeCount >= (double)1000.0f)
			{
				nFrameCount = 0;
				timeCount = 0;

			}

			while (delta >= 6000)
			{
				render = true;
				delta -= 6000;
				game.update();
			}

			if (render)
			{
				nFrameCount++;
				game.render();
			}

		}

	}
	return msg.wParam;
}