#pragma once

#include <string>
#include "A_MainObject.h"
#include "Vector2.h"
#include "E_Stage.h"

class Ball final : public A_MainObject
{
public:
	explicit Ball();
	~Ball() = default;

	void Update(E_Stage stage, float deltaTime);
	void Draw() const;
	bool isOut() const;
	void Initialize();
private:
	void Convert();
	void WallsBounce();
	void BarBounce();
	void BlockBounce(const E_Stage& stage);
	void BallRevise(const Vector2& base, std::string& state);
	static Vector2 _position;
	Vector2 _oldPosition;
	float _angle;
	float _speed;
	Vector2 _directionVector;
};

