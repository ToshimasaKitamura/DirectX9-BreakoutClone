#pragma once

#include <unordered_map>
#include <array>
#include <memory>
#include <d3d9.h>
#include <dinput.h>
#include "TextureStruct.h"
#include "Define.h"

class DirectParameter final
{
public:
	explicit DirectParameter() = default;
	~DirectParameter() = default;

	static LPDIRECT3D9 _D3D;
	static LPDIRECT3DDEVICE9 _D3DDevice;
	static D3DPRESENT_PARAMETERS _winPP;
	static D3DPRESENT_PARAMETERS _fullPP;
	static std::unordered_map<std::string, std::shared_ptr<TextureStruct>> _textureList;
	static LPDIRECTINPUT8 _DI;
	static LPDIRECTINPUTDEVICE8 _DIDevice;
	static std::array<int, Define::_5bit> _keyPressingCounter;
	static std::array<int, Define::_5bit> _keyReleasingCounter;
};