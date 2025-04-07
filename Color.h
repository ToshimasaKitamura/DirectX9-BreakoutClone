#pragma once

struct ColorARGB
{
	ColorARGB(const int a, const int r, const int g, const int b) : _a(a), _r(r), _g(g), _b(b) {}
	int _a;
	int _r;
	int _g;
	int _b;
};