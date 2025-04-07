#pragma once

#include "Vector2.h"

struct Vector2Tuple2
{
	Vector2Tuple2(Vector2 a, Vector2 b) : _a(a), _b(b) {}
	Vector2 _a;
	Vector2 _b;
};