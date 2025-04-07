#include "TSYInput.h"
#include "DirectParameter.h"

bool TSYInput::GetKey(E_Key key_code)
{	
	return DirectParameter::_keyPressingCounter[(int)key_code] > 0;
}

bool TSYInput::GetKeyDown(E_Key key_code)
{
	return DirectParameter::_keyPressingCounter[(int)key_code] == 1;
}

bool TSYInput::GetKeyUp(E_Key key_code)
{
	return DirectParameter::_keyReleasingCounter[(int)key_code] == 1;
}

int TSYInput::GetKeyPressingCount(E_Key key_code)
{
	return DirectParameter::_keyPressingCounter[(int)key_code];
}

int TSYInput::GetKeyReleasingCount(E_Key key_code)
{
	return DirectParameter::_keyReleasingCounter[(int)key_code];
}