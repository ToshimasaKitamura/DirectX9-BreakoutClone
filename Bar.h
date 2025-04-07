#pragma once

#include "A_MainObject.h"

class Bar final : public A_MainObject
{
public:
	explicit Bar();
	~Bar() = default;
	void InputUpdate();
	void Update(float deltaTime);
	void Draw() const;
	inline static float GetX() { return _x; };
private:
	static float _x;
	bool _moveRight;
	bool _moveLeft;
};

