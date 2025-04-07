#include "TSYAssist.h"
#include <Windows.h>
#include <stdlib.h>

void TSYAssist::GameEnd()
{
	PostQuitMessage(0);
}

int TSYAssist::GetRand(const int max)
{
	std::random_device md;
	std::mt19937 mt(md());
	std::uniform_int_distribution<> func(0, max);
	return func(mt);
}

int TSYAssist::GetRand(const int min, const int max)
{
	std::random_device md;
	std::mt19937 mt(md());
	std::uniform_int_distribution<> func(min, max);
	return func(mt);
}

void TSYAssist::DebugOut(const std::string& x)
{
	const std::string tmp("\n");
	OutputDebugString((x + tmp).data());
}

void TSYAssist::DebugOut(const std::string& name, const int x)
{
	const std::string tmp("\n");
	OutputDebugString((name + std::to_string(x) + tmp).data());
}

void TSYAssist::DebugOut(const std::string& name, const float x)
{
	const std::string tmp("\n");
	OutputDebugString((name + std::to_string(x) + tmp).data());
}

void TSYAssist::DebugOut(const std::string& name, const std::string& x)
{
	const std::string tmp("\n");
	OutputDebugString((name + x + tmp).data());
}