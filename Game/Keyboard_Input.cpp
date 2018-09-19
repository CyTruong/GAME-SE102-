#include "Keyboard_Input.h"
#include <iostream>

int Keyboard_Input::Creat_Input(HWND hWnd) {
	HRESULT result;
	result = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dinput,
		NULL);
	if (result != DI_OK) {
		return 0;
	}

	result = dinput->CreateDevice
	(
		GUID_SysKeyboard,
		&dikeyboard,
		NULL
	);
	if (result != DI_OK) {
		return 0;
	}

	result = dikeyboard->SetDataFormat(&c_dfDIKeyboard);
	if (result != DI_OK) {
		return 0;
	}

	result = dikeyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (result != DI_OK) {
		return 0;
	}

	result = dikeyboard->Acquire();
	if (result != DI_OK) {
		return 0;
	}


	return 1;
}

void Keyboard_Input::Poll_input() {
	dikeyboard->GetDeviceState(sizeof(key), (LPVOID)&key);
}

int Keyboard_Input::Get_State(int ikey) {
	/*for (int i = 0; i < 255; i ++) {
		if ((key[i] & 0x80)) {
			 return key[ikey] & 0x80;
		}
	}*/
	if ((key[ikey] & 0x80)!= 0) {

	}
	return (key[ikey] & 0x80);
}

void Keyboard_Input::Clear_input() {
	//__unhook(&IControlEventSender::TriggerEvent, &Esource, &IControl::GetState);

}