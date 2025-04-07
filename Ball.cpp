#include "Ball.h"
#include <cmath>
#include "Define.h"
#include "TSYGraphics.h"
#include "TSYAssist.h"
#include "Collision.h"
#include "Bar.h"
#include "Block.h"

Vector2 Ball::_position = Vector2(_ballStartPosX, _ballStartPosY);

Ball::Ball()
{
	_position = Vector2(_ballStartPosX, _ballStartPosY);
	_oldPosition = _position;
	_angle = _ballStartAngle;
	_speed = _ballStartSpeed;
	_directionVector = Vector2::_zero;
	Convert();
}

void Ball::Update(E_Stage stage, float deltaTime)
{
	_position += _directionVector * deltaTime;

	Collision collision;
	const Vector2 diameterBuf(_ballDiameter, _ballDiameter);
	collision.Regist("ball", Vector2Tuple2(_position, _position + diameterBuf));

	WallsBounce();	
	BarBounce();
	BlockBounce(stage);

	float a = (_position - _oldPosition).Length();
	std::string g("\n");
	

	_oldPosition = _position;

	//Convert();
}

void Ball::Draw() const
{
	TSYAssist::DebugOut("yF", _position.GetY());
	TSYGraphics::DrawGraph(_position.GetX(), _position.GetY(), "ball.png");
}

bool Ball::isOut() const
{
	return _position.GetY() > (Define::_mainWinHeight + _ballDiameter);
}

void Ball::Initialize()
{
	_position = Vector2(_ballStartPosX, _ballStartPosY);
	_oldPosition = _position;
	_angle = _ballStartAngle;
	_speed = _ballStartSpeed;
	_directionVector = Vector2::_zero;
	Convert();
}

void Ball::Convert()
{
	_directionVector = Vector2(
		_speed * std::cosf(_angle * Define::_pi / 180.0f), 
		-_speed * std::sinf(_angle * Define::_pi / 180.0f));
}

void Ball::WallsBounce()
{
	if (_position.GetX() < _screenFrameSize) {
		_directionVector = _directionVector.ReverseRight();
		_position = Vector2(_screenFrameSize, _position.GetY());
	}
	if (_position.GetX() > Define::_mainWinWidth - _screenFrameSize - _ballDiameter) {
		_directionVector = _directionVector.ReverseLeft();
		_position = Vector2(Define::_mainWinWidth - _screenFrameSize - _ballDiameter, _position.GetY());
	}
	if (_position.GetY() < _screenFrameSize) {
		_directionVector = _directionVector.ReverseDown();
		_position = Vector2(_position.GetX(), _screenFrameSize);
	}
	_angle = _directionVector.GetTheta();
}

void Ball::BarBounce()
{
	Collision collision;

	if (collision.isHit("ball", "bar")) {
		const float ballCenterX = _position.GetX() - _ballDiameter / 2.0f;
		const float barX = Bar::GetX();
		float barTheta = 90.0f;

		if (ballCenterX < barX + (float)_barSlopeChangeInterval) barTheta += _barSlopeLarge;
		else if (ballCenterX < barX + (float)_barSlopeChangeInterval * 2.0f) barTheta += _barSlopeMedium;
		else if (ballCenterX < barX + (float)_barSlopeChangeInterval * 3.0f) barTheta += _barSlopeSmall;
		else if (ballCenterX < barX + (float)_barSlopeChangeInterval * 5.0f) barTheta += 0.0f;
		else if (ballCenterX < barX + (float)_barSlopeChangeInterval * 6.0f) barTheta -= _barSlopeSmall;
		else if (ballCenterX < barX + (float)_barSlopeChangeInterval * 7.0f) barTheta -= _barSlopeMedium;
		else barTheta -= _barSlopeLarge;

		_directionVector = _directionVector.Turn(barTheta);
		//_directionVector = _directionVector.Normalize();
		 
		_position = Vector2(_position.GetX(), _barY - _ballDiameter);
	}
	_angle = _directionVector.GetTheta();
}

void Ball::BlockBounce(const E_Stage& stage)
{
	Block block;
	std::array<bool, _blockHMax* _blockVMax> blockArray;
	block.GetActiveBlcok(stage, blockArray);

	std::string state = "null";
	for (int i = 0; i < _blockVMax * _blockHMax; ++i)
	{
		if (!blockArray[i]) continue;
		Collision collision;
		const std::string tmp("block" + std::to_string(i));
		if (collision.isHit("ball", tmp)) {
			const Vector2 base(_blockStartPosX + _blockW * (i % _blockHMax),
				_blockStartPosY + _blockH * (i / _blockHMax));
			BallRevise(base, state);
		}
	}
	if (state == "left") _directionVector = _directionVector.ReverseLeft();
	else if (state == "right") _directionVector = _directionVector.ReverseRight();
	else if (state == "up") _directionVector = _directionVector.ReverseUp();
	else if (state == "down") _directionVector = _directionVector.ReverseDown();
	else if (state == "LU") _directionVector = _directionVector.ReverseLU();
	else if (state == "RU") _directionVector = _directionVector.ReverseRU();
	else if (state == "RD") _directionVector = _directionVector.ReverseRD();
	else if (state == "LD") _directionVector = _directionVector.ReverseLD();

	_angle = _directionVector.GetTheta();
}

void Ball::BallRevise(const Vector2& base, std::string& state)
{
	for (int j = 0; ; ++j)
	{
		const Vector2 LU(base.GetX() - j, base.GetY() - j);
		const Vector2 RU(base.GetX() + _blockW + j, base.GetY() - j);
		const Vector2 RD(base.GetX() + _blockW + j, base.GetY() + _blockH + j);
		const Vector2 LD(base.GetX() - j, base.GetY() + _blockH + j);
		const int oldX = (int)_oldPosition.GetX();
		const int oldY = (int)_oldPosition.GetY();
		if (oldX < LU.GetX() && oldY >= LU.GetY() && oldY < LD.GetY()) state = "left";
		else if (oldX >= RU.GetX() && oldY >= RU.GetY() && oldY < RD.GetY()) state = "right";
		else if (oldY < LU.GetY() && oldX >= LU.GetX() && oldX < RU.GetX()) state = "up";
		else if (oldY >= LD.GetY() && oldX >= LD.GetX() && oldX < RD.GetX()) state = "down";
		else if (oldX == LU.GetX() && oldY == LU.GetY()) state = "LU";
		else if (oldX == RU.GetX() && oldY == RU.GetY() - 1.0f) state = "RU";
		else if (oldX == RD.GetX() && oldY == RD.GetY()) state = "RD";
		else if (oldX == LD.GetX() && oldY == LD.GetY() - 1.0f) state = "LD";
		if (state != "null") break;
	}
	if (state == "left") _position = Vector2(base.GetX() - _ballDiameter, _position.GetY());
	else if (state == "right") _position = Vector2(base.GetX() + _blockW, _position.GetY());
	else if (state == "up") _position = Vector2(_position.GetX(), base.GetY() - _ballDiameter);
	else if (state == "down") _position = Vector2(_position.GetX(), base.GetY() + _blockH);
	else if (state == "LU") _position = Vector2(base.GetX() - _ballDiameter, base.GetY() - _ballDiameter);
	else if (state == "RU")  _position = Vector2(base.GetX() + _blockW, base.GetY() - _ballDiameter);
	else if (state == "RD") _position = Vector2(base.GetX() + _blockW, base.GetY() + _blockH);
	else if (state == "LD") _position = Vector2(base.GetX() - _ballDiameter, base.GetY() + _blockH);
}