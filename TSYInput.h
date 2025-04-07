#pragma once

#include "E_Key.h"

class TSYInput final
{
public:
	explicit TSYInput() = default;
	~TSYInput() = default;

	static bool GetKey(E_Key key_code);
	static bool GetKeyDown(E_Key key_code);
	static bool GetKeyUp(E_Key key_code);
	static int GetKeyPressingCount(E_Key key_code);
	static int GetKeyReleasingCount(E_Key key_code);
};

