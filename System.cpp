#include "System.h"
#include "Error.h"
#include "Window.h"
#include "DirectGraphics.h"
#include "DirectInput.h"
#include "Game.h"

System::System() : _loopEnd(false), _systemEnd(false), _isWindowMode(true){}

void System::Run()
{
	//Setting();
	MainInit();
	Loop();
	MainFinal();
}

void System::Loop()
{
	if (_systemEnd) return;
	MSG msg;

	while (true)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) Message(msg);
		else if (_loopEnd) break;
		else MainProc();

	}
	
}

void System::Message(MSG msg)
{
	if (msg.message == WM_QUIT) _loopEnd = true;
	else {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void System::Setting()
{
	Window window;
	Window::Mode mode;
	window.MakeSettingWindow(mode);
	switch (mode) {
	case Window::Mode::Window: _isWindowMode = true; break;
	case Window::Mode::FullScreen: _isWindowMode = false; break;
	case Window::Mode::End: _systemEnd = true; break;
	default:_systemEnd = true; break;
	}
}

void System::MainInit()
{
	if (_systemEnd) return;
	Window window;
	DirectGraphics graphics;
	DirectInput input;
	window.MakeMainWindow();
	graphics.NewGraphics(_isWindowMode);
	input.Initialize();
	_game = std::make_shared<Game>();
}

void System::MainProc()
{
	
	DirectGraphics graphics;
	DirectInput input;
	graphics.DrawStart();
	input.KeyUpdate();
	_game->Play();
	graphics.DrawEnd();
}

void System::MainFinal()
{
	if (_systemEnd) return;
	_game.reset();
	DirectGraphics graphics;
	DirectInput input;
	input.Release();
	graphics.ReleaseGraphics();
}