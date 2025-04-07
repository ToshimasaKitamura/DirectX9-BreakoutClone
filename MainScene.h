#pragma once

#include <memory>
#include "E_Stage.h"
#include "A_Scene.h"
#include "Bar.h"
#include "Ball.h"
#include "Brack.h"
#include "Life.h"

class MainScene final : public A_Scene
{
public:
	explicit MainScene();
	~MainScene() = default;

	void InputUpdate() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void TransitionUpdate() const override;
private:
	void StageTransition();
	void FadeIn();
	void FadeOut();

	std::shared_ptr<Bar> _bar;
	std::shared_ptr<Ball> _ball;
	E_Stage _stage;
	std::shared_ptr<Brack> _brack;
	std::shared_ptr<Life> _life;

	bool _preventInput;
	bool _doFadeIn;
	bool _doFadeOut;
};

