#pragma once

#include "A_MainObject.h"

class Frame final : public A_MainObject
{
public:
	explicit Frame() = default;
	~Frame() = default;
	void Draw() const;
};

