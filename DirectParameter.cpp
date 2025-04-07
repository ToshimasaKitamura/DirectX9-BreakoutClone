#include "DirectParameter.h"
#include "Define.h"

LPDIRECT3D9 DirectParameter::_D3D = NULL;

LPDIRECT3DDEVICE9 DirectParameter::_D3DDevice = NULL;

D3DPRESENT_PARAMETERS DirectParameter::_winPP;

D3DPRESENT_PARAMETERS DirectParameter::_fullPP;

std::unordered_map<std::string, std::shared_ptr<TextureStruct>> DirectParameter::_textureList;

LPDIRECTINPUT8 DirectParameter::_DI = NULL;

LPDIRECTINPUTDEVICE8 DirectParameter::_DIDevice = NULL;

std::array<int, Define::_5bit> DirectParameter::_keyPressingCounter;

std::array<int, Define::_5bit> DirectParameter::_keyReleasingCounter;