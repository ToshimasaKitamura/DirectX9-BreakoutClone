#pragma once

#include <unordered_map>
#include <Windows.h>

class DirectInput final
{
public:
	explicit DirectInput() = default;
	~DirectInput() = default;
	void Initialize() const;
	void Release() const;
	void KeyUpdate() const;
private:
	void CheckKeyCounter(const BYTE* keyState) const;
};
