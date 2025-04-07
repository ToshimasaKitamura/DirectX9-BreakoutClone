#pragma once

#include "A_Scene.h"

class GameOverScene final : public A_Scene
{
public:
	explicit GameOverScene() = default;
	~GameOverScene() = default;

	void InputUpdate() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void TransitionUpdate() const override;
};

