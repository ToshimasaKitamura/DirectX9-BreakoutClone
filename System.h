#pragma once

#include <memory>
#include <Windows.h>
#include "Game.h"

class System final
{
public:
	explicit System();
	~System() = default;

	void Run();
private:
	void Loop();
	void Message(MSG msg);

	void Setting();
	void MainInit();
	void MainProc();
	void MainFinal();
	
	bool _loopEnd;
	bool _systemEnd;
	bool _isWindowMode;

	std::shared_ptr<Game> _game;
};

