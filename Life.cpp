#include "Life.h"
#include "TSYGraphics.h"


Life::Life()
{
	_nowLifeNum = _startLifeNum;
}

void Life::Update(const Ball* ball)
{
	if (ball->isOut()) {
		_nowLifeNum--;
	}
}

void Life::Darw() const
{
	for (int i = 0; i < _startLifeNum; ++i)
	{
		TSYGraphics::DrawGraph(_lifeX, _lifeY - _lifeInterval * i, "emptyHeart(32x32).png");
	}	
	for (int i = 0; i < _nowLifeNum; ++i)
	{
		TSYGraphics::DrawGraph(_lifeX, _lifeY - _lifeInterval * i, "heart(32x32).png");
	}
}

bool Life::isLifeZeo() const
{
	return _nowLifeNum <= 0;
}