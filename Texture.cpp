#include "Texture.h"
#include <memory>
#include <d3dx9.h>
#include "TextureStruct.h"
#include "DirectParameter.h"
#include "Error.h"

void Texture::CreateTexture(const std::string& fileName) const
{
	std::shared_ptr<TextureStruct> dummyTexture = std::make_shared<TextureStruct>();
	DirectParameter::_textureList.insert(std::make_pair(fileName, dummyTexture));
	auto& targetTexture = DirectParameter::_textureList.at(fileName);

	Error error;
	const std::string path("image/" + fileName);

	HRESULT result = D3DXCreateTextureFromFileExA(
		DirectParameter::_D3DDevice,
		path.data(),
		0,
		0,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x0000ff00,
		nullptr,
		nullptr,
		&targetTexture->_texutreData);
	if (FAILED(result)) error.Issue("009");

	D3DSURFACE_DESC desc;

	if (FAILED(targetTexture->_texutreData->GetLevelDesc(0, &desc)))
	{
		targetTexture->_texutreData->Release();
		error.Issue("010");
	}
	targetTexture->_width = desc.Width;
	targetTexture->_height = desc.Height;
}

void Texture::ReleaseTexture(const std::string& fileName) const
{
	if (DirectParameter::_textureList.contains(fileName)) return;
	DirectParameter::_textureList.erase(fileName);
}