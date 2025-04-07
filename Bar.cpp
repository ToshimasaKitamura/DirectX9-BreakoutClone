#include "Bar.h"
#include "Define.h"
#include "TSYGraphics.h"
#include "TSYInput.h"
#include "Collision.h"

float Bar::_x = (float)((Define::_mainWinWidth / 2) - (_barLength / 2));

Bar::Bar()
{
	_moveLeft = false;
	_moveRight = false;
	_x = _barStartPosX;
}

void Bar::InputUpdate()
{
	if (TSYInput::GetKey(E_Key::Left)) _moveLeft = true;
	if (TSYInput::GetKey(E_Key::Right)) _moveRight = true;
}

void Bar::Update(float deltaTime)
{
	if (_moveLeft) {
		_x -= _barSpeed * deltaTime;
		_moveLeft = false;
	}
	if (_moveRight) {
		_x += _barSpeed * deltaTime;
		_moveRight = false;
	}
	const float _barMinLimit = (float)(_screenFrameSize + 1);
	const float _barMaxLimit = (float)(Define::_mainWinWidth - _screenFrameSize - _barLength - 1);
	if (_x < _barMinLimit) _x = _barMinLimit;
	if (_x > _barMaxLimit) _x = _barMaxLimit;

	Collision collision;
	const Vector2 vecLU(_x, _barY);
	const Vector2 vecRD(_x + _barLength, _barY + _barThickness);
	collision.Regist("bar", Vector2Tuple2(vecLU, vecRD));
}

void Bar::Draw() const
{
	TSYGraphics::DrawGraph(_x, _barY, "bar.png");
}