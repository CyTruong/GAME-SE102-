#include "Keyboard_Input.h"


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

	return 1;
}

void Keyboard_Input::Poll_input() {
	dikeyboard->GetDeviceState(sizeof(key), (LPVOID)&key);
	__raise Esource.TriggerEvent(key);
}

void Keyboard_Input::Clear_input() {
	//__unhook(&IControlEventSender::TriggerEvent, &Esource, &IControl::GetState);

}