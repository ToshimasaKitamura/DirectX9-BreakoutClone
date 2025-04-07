#include "DirectInput.h"
#include "DirectParameter.h"
#include "Define.h"
#include "E_Key.h"
#include "Error.h"

void DirectInput::Initialize() const
{
	Error error;

	HRESULT hr = DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&DirectParameter::_DI, NULL);
	if (FAILED(hr)) error.Issue("011");

	hr = DirectParameter::_DI->CreateDevice(GUID_SysKeyboard, &DirectParameter::_DIDevice, NULL);
	if (FAILED(hr)) error.Issue("012");

	hr = DirectParameter::_DIDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr)) error.Issue("013");

	hr = DirectParameter::_DIDevice->SetCooperativeLevel(FindWindow(Define::_mainWinClass, nullptr), DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hr)) error.Issue("014");

	DirectParameter::_DIDevice->Acquire();
}

void DirectInput::Release() const
{
	DirectParameter::_DIDevice->Unacquire();
	DirectParameter::_DIDevice->Release();
	DirectParameter::_DI->Release();
}

void DirectInput::KeyUpdate() const
{
	const int keyNumber = Define::_8bitMax + 1;
	BYTE KeyState[keyNumber];
	HRESULT hr;

	hr = DirectParameter::_DIDevice->GetDeviceState(keyNumber, KeyState);

	if (SUCCEEDED(hr)) CheckKeyCounter(KeyState);
	else if (hr == DIERR_INPUTLOST) DirectParameter::_DIDevice->Acquire();
}

void DirectInput::CheckKeyCounter(const BYTE* keyState) const
{
	const int checkValue = Define::_8bit;
	std::array<int, Define::_5bit>& tmp_p = DirectParameter::_keyPressingCounter;
	std::array<int, Define::_5bit>& tmp_r = DirectParameter::_keyReleasingCounter;

	if (keyState[DIK_ESCAPE] & checkValue) {
		tmp_p[(int)E_Key::Escape]++;
		tmp_r[(int)E_Key::Escape] = 0;
	}
	else {
		tmp_r[(int)E_Key::Escape]++;
		tmp_p[(int)E_Key::Escape] = 0;
	}

	if (keyState[DIK_A] & checkValue) {
		tmp_p[(int)E_Key::A]++;
		tmp_r[(int)E_Key::A] = 0;
	}
	else {
		tmp_r[(int)E_Key::A]++;
		tmp_p[(int)E_Key::A] = 0;
	}

	if (keyState[DIK_C] & checkValue) {
		tmp_p[(int)E_Key::C]++;
		tmp_r[(int)E_Key::C] = 0;
	}
	else {
		tmp_r[(int)E_Key::C]++;
		tmp_p[(int)E_Key::C] = 0;
	}

	if (keyState[DIK_D] & checkValue) {
		tmp_p[(int)E_Key::D]++;
		tmp_r[(int)E_Key::D] = 0;
	}
	else {
		tmp_r[(int)E_Key::D]++;
		tmp_p[(int)E_Key::D] = 0;
	}

	if (keyState[DIK_P] & checkValue) {
		tmp_p[(int)E_Key::P]++;
		tmp_r[(int)E_Key::P] = 0;
	}
	else {
		tmp_r[(int)E_Key::P]++;
		tmp_p[(int)E_Key::P] = 0;
	}

	if (keyState[DIK_R] & checkValue) {
		tmp_p[(int)E_Key::R]++;
		tmp_r[(int)E_Key::R] = 0;
	}
	else {
		tmp_r[(int)E_Key::R]++;
		tmp_p[(int)E_Key::R] = 0;
	}

	if (keyState[DIK_S] & checkValue) {
		tmp_p[(int)E_Key::S]++;
		tmp_r[(int)E_Key::S] = 0;
	}
	else {
		tmp_r[(int)E_Key::S]++;
		tmp_p[(int)E_Key::S] = 0;
	}

	if (keyState[DIK_W] & checkValue) {
		tmp_p[(int)E_Key::W]++;
		tmp_r[(int)E_Key::W] = 0;
	}
	else {
		tmp_r[(int)E_Key::W]++;
		tmp_p[(int)E_Key::W] = 0;
	}

	if (keyState[DIK_X] & checkValue) {
		tmp_p[(int)E_Key::X]++;
		tmp_r[(int)E_Key::X] = 0;
	}
	else {
		tmp_r[(int)E_Key::X]++;
		tmp_p[(int)E_Key::X] = 0;
	}

	if (keyState[DIK_Z] & checkValue) {
		tmp_p[(int)E_Key::Z]++;
		tmp_r[(int)E_Key::Z] = 0;
	}
	else {
		tmp_r[(int)E_Key::Z]++;
		tmp_p[(int)E_Key::Z] = 0;
	}

	if (keyState[DIK_RETURN] & checkValue) {
		tmp_p[(int)E_Key::Return]++;
		tmp_r[(int)E_Key::Return] = 0;
	}
	else {
		tmp_r[(int)E_Key::Return]++;
		tmp_p[(int)E_Key::Return] = 0;
	}

	if (keyState[DIK_LSHIFT] & checkValue) {
		tmp_p[(int)E_Key::LShift]++;
		tmp_r[(int)E_Key::LShift] = 0;
	}
	else {
		tmp_r[(int)E_Key::LShift]++;
		tmp_p[(int)E_Key::LShift] = 0;
	}

	if (keyState[DIK_UP] & checkValue) {
		tmp_p[(int)E_Key::Up]++;
		tmp_r[(int)E_Key::Up] = 0;
	}
	else {
		tmp_r[(int)E_Key::Up]++;
		tmp_p[(int)E_Key::Up] = 0;
	}

	if (keyState[DIK_DOWN] & checkValue) {
		tmp_p[(int)E_Key::Down]++;
		tmp_r[(int)E_Key::Down] = 0;
	}
	else {
		tmp_r[(int)E_Key::Down]++;
		tmp_p[(int)E_Key::Down] = 0;
	}

	if (keyState[DIK_LEFT] & checkValue) {
		tmp_p[(int)E_Key::Left]++;
		tmp_r[(int)E_Key::Left] = 0;
	}
	else {
		tmp_r[(int)E_Key::Left]++;
		tmp_p[(int)E_Key::Left] = 0;
	}

	if (keyState[DIK_RIGHT] & checkValue) {
		tmp_p[(int)E_Key::Right]++;
		tmp_r[(int)E_Key::Right] = 0;
	}
	else {
		tmp_r[(int)E_Key::Right]++;
		tmp_p[(int)E_Key::Right] = 0;
	}
}