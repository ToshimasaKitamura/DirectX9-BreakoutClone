#include "MainScene.h"
#include "TSYInput.h"
#include "Game.h"
#include "TSYAssist.h"

#include "Frame.h"
#include "Block.h"
#include "Life.h"

MainScene::MainScene() : 
	_bar(std::make_shared<Bar>()),
	_ball(std::make_shared<Ball>()),
	_brack(std::make_shared<Brack>()),
	_life(std::make_shared<Life>())
{
	_stage = E_Stage::First;
	_preventInput = false;
	_doFadeIn = true;
	_doFadeOut = false;
}

void MainScene::InputUpdate()
{
	if(_preventInput) _bar->InputUpdate();
}

void MainScene::Update(float deltaTime)
{
	if (_doFadeIn) {
		FadeIn();
		return;
	}
	if (_doFadeOut) {
		FadeOut();
		return;
	}

	Block block;

	block.CollisionRegist(_stage);
	_bar->Update(deltaTime);
	_ball->Update(_stage, deltaTime);
	block.Update(_stage);
	_life->Update(_ball.get());
	block.Destroy(_stage);

	if (_life->isLifeZeo()) {
		TSYAssist::GameEnd();
	}
	if (_ball->isOut()) {
		_bar = std::make_shared<Bar>();
		_ball = std::make_shared<Ball>();
	}
	if (block.isBlockZero(_stage)) {
		_preventInput = false;
		_doFadeOut = true;
	}
		
}

void MainScene::Draw() const
{	
	_bar->Draw();
	Frame frame;
	frame.Draw();
	_ball->Draw();
	Block block;
	block.Draw(_stage);
	_life->Darw();
	_brack->Draw();
}

void MainScene::TransitionUpdate() const
{
	if (TSYInput::GetKeyDown(E_Key::Return)) Game::NextScene(E_Scene::GameOver, false);
}

void MainScene::StageTransition()
{
	switch (_stage) {
	case E_Stage::First:
		_stage = E_Stage::Second;		
		break;
	case E_Stage::Second:

		break;
	case E_Stage::Third:

		break;
	case E_Stage::Fourth:

		break;
	case E_Stage::Fifth:

		break;
	default: break;
	}
}

void MainScene::FadeIn()
{
	if (_brack->FadeIn()) {
		_doFadeIn = false;
		_preventInput = true;
	}
}

void MainScene::FadeOut()
{
	if (_brack->FadeOut()) {
		_doFadeOut = false;
		_preventInput = false;
		StageTransition();
		_doFadeIn = true;
		_bar = std::make_shared<Bar>();
		_ball = std::make_shared<Ball>();
	}
}