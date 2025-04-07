#pragma once

#include "A_MainObject.h"

class Brack final : public A_MainObject
{
public:
	explicit Brack();
	~Brack() = default;

	bool FadeIn();
	bool FadeOut();
	void Draw() const;
private:
	float _y;
	int _num;
};

