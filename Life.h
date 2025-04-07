#pragma once

#include "A_MainObject.h"
#include "Ball.h"

class Life final : public A_MainObject
{
public:
	explicit Life();
	~Life() = default;

	void Update(const Ball* ball);
	void Darw() const;
	bool isLifeZeo() const;
private:
	int _nowLifeNum;
};

