#pragma once

#include "E_Scene.h"

class A_Scene
{
public:
	explicit A_Scene() = default;
	virtual ~A_Scene() = default;

	virtual void InputUpdate() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() const = 0;
	virtual void TransitionUpdate() const = 0;
};