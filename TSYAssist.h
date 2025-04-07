#pragma once

#include <random>
#include <string>

class TSYAssist final
{
public:
	explicit TSYAssist() = default;
	~TSYAssist() = default;

	static void GameEnd();
	static int GetRand(const int max);
	static int GetRand(const int min, const int max);
	static void DebugOut(const std::string& x);
	static void DebugOut(const std::string& name, const int x);
	static void DebugOut(const std::string& name, const float x);
	static void DebugOut(const std::string& name, const std::string& x);
};