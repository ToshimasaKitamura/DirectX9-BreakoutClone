#include "Brack.h"
#include "TSYGraphics.h"
#include "Define.h"

Brack::Brack()
{
	_num = Define::_mainWinHeight / (_brackH - _brackTransparentH - 1) + 1;
	_y = _brackStartPosY + ((_num - 1) * (_brackH - _brackTransparentH - 1)) + _brackH;
}

bool Brack::FadeIn()
{
	if (_y > _brackStartPosY) {
		_y -= _brackSpeed;
	}
	else {
		_y = _brackStartPosY;
		return true;
	}
	return false;
}

bool Brack::FadeOut()
{
	if (_y < _brackStartPosY + ((_num - 1) * (_brackH - _brackTransparentH - 1)) + _brackH) _y += _brackSpeed;
	else {
		_y = _brackStartPosY + ((_num - 1) * (_brackH - _brackTransparentH - 1)) + _brackH;
		return true;
	}
	return false;
}

void Brack::Draw() const
{
	for (int i = 0; i < _num; ++i)
	{
		for (int j = 0; j < _num; ++j)
		{
			TSYGraphics::DrawGraph((float)(_brackW * j), _y + (_brackH - _brackTransparentH - 1) * i, "brack(128x128).png");
		}
	}
}