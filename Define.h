#pragma once

#include <Windows.h>

struct Define
{
	static constexpr int _1bit = 0b1;
	static constexpr int _2bit = 0b10;
	static constexpr int _3bit = 0b100;
	static constexpr int _4bit = 0b1000;
	static constexpr int _5bit = 0b10000;
	static constexpr int _6bit = 0b100000;
	static constexpr int _7bit = 0b1000000;
	static constexpr int _8bit = 0b10000000;
	static constexpr int _8bitMax = 0b11111111;
	static constexpr char const* _mainWinClass = "MainClass";
	static constexpr char const* _mainWinTitle = "Main";
	static constexpr int _mainWinWidth = 640;
	static constexpr int _mainWinHeight = 480;
	static constexpr int _settingWinWidth = 480;
	static constexpr int _settingWinHeight = 480;
	static constexpr DWORD _settingWinStyle = WS_OVERLAPPED | WS_CAPTION;
	static constexpr DWORD _mainWinStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
	static constexpr float _pi = 3.14159;
	static constexpr int _FPSUpdateInterval = 600;
	static constexpr float _targetFPS = 60.0f;
}; 