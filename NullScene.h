#pragma once

#include "A_Scene.h"

class NullScene final : public A_Scene
{
public:
	explicit NullScene() = default;
	~NullScene() = default;

	void InputUpdate() override {};
	void Update(float deltaTime) override {};
	void Draw() const override {};
	void TransitionUpdate() const override {};
};

