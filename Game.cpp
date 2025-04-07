#include "Game.h"
#include <stdio.h>
#include "TSYGraphics.h"
#include "TSYInput.h"
#include "TSYAssist.h"
#include "Collision.h"

#include "MainScene.h"
#include "GameOverScene.h"
#include "NullScene.h"

std::stack<std::shared_ptr<A_Scene>> Game::_sceneStack;
std::shared_ptr<A_Scene> Game::_poseScene;

Game::Game()
{
	TSYGraphics::LoadGraph();
	_sceneStack.push(std::make_shared<MainScene>());
	_poseScene = std::make_shared<NullScene>();
	deltaTime = 1.0f;

	_fps = std::make_shared<Fps>();
}

Game::~Game()
{
	
	TSYGraphics::ReleaseGraph();
}

void Game::Play()
{
	Collision collision;
	collision.Declare();
	_sceneStack.top()->InputUpdate();
	_sceneStack.top()->Update(deltaTime);
	_sceneStack.top()->Draw();
	_sceneStack.top()->TransitionUpdate();
	if (TSYInput::GetKeyDown(E_Key::Escape)) TSYAssist::GameEnd();

	_fps->Wait();
	/*
	
	int a = 40;
	TSYGraphics::DrawGraphMaptip(a, 4, "fontex.png", 28, 32);
	TSYGraphics::DrawGraphMaptip(a + 25, 4, "fontex.png", 12, 32);
	TSYGraphics::DrawGraphMaptip(a + 50, 4, "fontex.png", 24, 32);
	TSYGraphics::DrawGraphMaptip(a + 75, 4, "fontex.png", 27, 32);
	TSYGraphics::DrawGraphMaptip(a + 100, 4, "fontex.png", 14, 32);
	int s1 = _score / 100;
	TSYGraphics::DrawGraphMaptip(a + 150, 4, "fontex.png", s1, 32);
	int s2 = (_score - s1 * 100) / 10;
	TSYGraphics::DrawGraphMaptip(a + 175, 4, "fontex.png", s2, 32);
	int s3 = (_score - s1 * 100 - s2 * 10);
	TSYGraphics::DrawGraphMaptip(a + 200, 4, "fontex.png", s3, 32);

	int b = 325;
	TSYGraphics::DrawGraphMaptip(b, 4, "fontex.png", 17, 32);
	TSYGraphics::DrawGraphMaptip(b + 20, 4, "fontex.png", 18, 32);
	TSYGraphics::DrawGraphMaptip(b + 45, 4, "fontex.png", 28, 32);
	TSYGraphics::DrawGraphMaptip(b + 70, 4, "fontex.png", 12, 32);
	TSYGraphics::DrawGraphMaptip(b + 95, 4, "fontex.png", 24, 32);
	TSYGraphics::DrawGraphMaptip(b + 120, 4, "fontex.png", 27, 32);
	TSYGraphics::DrawGraphMaptip(b + 145, 4, "fontex.png", 14, 32);
	TSYGraphics::DrawGraphMaptip(b + 195, 4, "fontex.png", 4, 32);
	TSYGraphics::DrawGraphMaptip(b + 220, 4, "fontex.png", 5, 32);
	TSYGraphics::DrawGraphMaptip(b + 245, 4, "fontex.png", 7, 32);

	if (_isHit) {
		TSYGraphics::DrawGraphMaptip(272, 224, "fontex.png", 12, 32);
		int c1 = _combo / 10;
		TSYGraphics::DrawGraphMaptip(304, 224, "fontex.png", c1, 32);
		TSYGraphics::DrawGraphMaptip(336, 224, "fontex.png", (_combo - c1 * 10), 32);
	}
	collision.Release();
	*/
}

void Game::NextScene(const E_Scene& scene, const bool _isStackClear)
{
	if (_isStackClear) {
		while (!_sceneStack.empty())
		{
			_sceneStack.pop();
		}
	}

	switch (scene) {
	case E_Scene::Title:

		break;
	case E_Scene::Ranking:

		break;
	case E_Scene::Setting:

		break;
	case E_Scene::Main:
		_sceneStack.push(std::make_shared<MainScene>());
		break;
	case E_Scene::Pose:

		break;
	case E_Scene::GameOver:
		_sceneStack.push(std::make_shared<GameOverScene>());
		break;
	case E_Scene::Ending:

		break;
	default: break;
	}
}

void Game::BackScene()
{
	if(!_sceneStack.empty()) _sceneStack.pop();
}