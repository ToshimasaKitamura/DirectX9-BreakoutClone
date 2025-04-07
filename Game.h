#pragma once

#include <array>
#include "Vector2.h"
#include <memory>
#include <stack>
#include "A_Scene.h"

#include "Fps.h"

class Game
{
public:
	explicit Game();
	~Game();
	void Play();
	static void NextScene(const E_Scene& scene, const bool _isStackClear);
	static void BackScene();
private:
	static std::stack<std::shared_ptr<A_Scene>> _sceneStack;
	static std::shared_ptr<A_Scene> _poseScene;
	float deltaTime;

	std::shared_ptr<Fps> _fps;
};

