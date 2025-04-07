#include "Error.h"
#include <Windows.h>
#include <string>
#include "Define.h"

void Error::Issue(const char* str) const
{
	std::string tmp((std::string)"�@Error Code�F" + (std::string)str + (std::string)"\n�@" + (std::string)Define::_mainWinTitle + (std::string)"���I�����܂��B");
	MessageBox(FindWindow(Define::_mainWinClass, Define::_mainWinTitle), str, "Main Error Message", MB_ICONSTOP);
	PostQuitMessage(0);
}