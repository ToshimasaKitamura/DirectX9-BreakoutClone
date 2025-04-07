#include "TSYGraphics.h"
#include <vector>
#include <d3dx9.h>
#include "CustomVertexStruct.h"
#include "DirectParameter.h"
#include "Image.h"
#include "Error.h"
#include "Texture.h"
#include "TSYAssist.h"

//----------------------------------------------------------------------------------------------------

//　パブリックメソッド

//----------------------------------------------------------------------------------------------------


void TSYGraphics::LoadGraph()
{
	Texture texture;

	for (int i = 0; i < (int)Image::_image.size(); ++i)
	{		
		texture.CreateTexture(Image::_image[i]);
	}
}

void TSYGraphics::ReleaseGraph()
{
	Texture texture;

	for (int i = 0; i < (int)Image::_image.size(); ++i)
	{
		texture.ReleaseTexture(Image::_image[i]);
	}
}

void TSYGraphics::DrawGraph(int x, int y, const std::string& image)
{
	const float tmp_x = static_cast<float>(x);
	const float tmp_y = static_cast<float>(y);

	CustomVertex1 verticies[4] =
	{
		{ tmp_x, tmp_y, 0.0f, 1.0f, 0.0f, 0.0f},
		{ tmp_x + DirectParameter::_textureList.at(image)->_width, tmp_y, 0.0f, 1.0f, 1.0f, 0.0f},
		{ tmp_x + DirectParameter::_textureList.at(image)->_width, tmp_y + DirectParameter::_textureList.at(image)->_height, 0.0f, 1.0f, 1.0f, 1.0f},
		{ tmp_x, tmp_y + DirectParameter::_textureList.at(image)->_height, 0.0f, 1.0f, 0.0f, 1.0f},
	};

	DirectParameter::_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	DirectParameter::_D3DDevice->SetTexture(0, DirectParameter::_textureList.at(image)->_texutreData);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DirectParameter::_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, verticies, sizeof(CustomVertex1));
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void TSYGraphics::DrawGraph(float x, float y, const std::string& image)
{
	CustomVertex1 verticies[4] =
	{
		{ x, y, 0.0f, 1.0f, 0.0f, 0.0f},
		{ x + DirectParameter::_textureList.at(image)->_width, y, 0.0f, 1.0f, 1.0f, 0.0f},
		{ x + DirectParameter::_textureList.at(image)->_width, y + DirectParameter::_textureList.at(image)->_height, 0.0f, 1.0f, 1.0f, 1.0f},
		{ x, y + DirectParameter::_textureList.at(image)->_height, 0.0f, 1.0f, 0.0f, 1.0f},
	};

	DirectParameter::_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_TEX1);
	DirectParameter::_D3DDevice->SetTexture(0, DirectParameter::_textureList.at(image)->_texutreData);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DirectParameter::_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, verticies, sizeof(CustomVertex1));
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void TSYGraphics::DrawGraphAlpha(int x, int y, const std::string& image, int alpha)
{
	const float tmp_x = static_cast<float>(x);
	const float tmp_y = static_cast<float>(y);

	if (alpha > 0xff) alpha = 0xff;
	if (alpha < 0x00) alpha = 0x00;
	const DWORD tmp_color = D3DCOLOR_RGBA(0xff, 0xff, 0xff, alpha);

	CustomVertex2 verticies[4] =
	{
		{ tmp_x, tmp_y, 0.0f, 1.0f, tmp_color, 0.0f, 0.0f},
		{ tmp_x + DirectParameter::_textureList.at(image)->_width, tmp_y, 0.0f, 1.0f, tmp_color, 1.0f, 0.0f},
		{ tmp_x + DirectParameter::_textureList.at(image)->_width, tmp_y + DirectParameter::_textureList.at(image)->_height, 0.0f, 1.0f, tmp_color, 1.0f, 1.0f},
		{ tmp_x, tmp_y + DirectParameter::_textureList.at(image)->_height, 0.0f, 1.0f, tmp_color, 0.0f, 1.0f},
	};

	DirectParameter::_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	DirectParameter::_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	DirectParameter::_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DirectParameter::_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DirectParameter::_D3DDevice->SetTexture(0, DirectParameter::_textureList.at(image)->_texutreData);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DirectParameter::_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, verticies, sizeof(CustomVertex2));
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void TSYGraphics::DrawGraphMaptip(int x, int y, const std::string& image, int target_id, int target_size)
{
	const int texture_size = DirectParameter::_textureList.at(image)->_width;

	const float u = static_cast<float>(target_size * (target_id % (texture_size / target_size)));
	const float v = static_cast<float>(target_size * (target_id / (texture_size / target_size)));

	const float tmp_x = static_cast<float>(x);
	const float tmp_y = static_cast<float>(y);

	float u_left = u / DirectParameter::_textureList.at(image)->_width;
	float u_right = (u + target_size) / DirectParameter::_textureList.at(image)->_width;
	float v_top = v / DirectParameter::_textureList.at(image)->_height;
	float v_bottom = (v + target_size) / DirectParameter::_textureList.at(image)->_height;

	CustomVertex1 verticies[4] =
	{
		{ tmp_x, tmp_y, 0.0f, 1.0f, u_left, v_top },
		{ tmp_x + target_size, tmp_y, 0.0f, 1.0f, u_right, v_top },
		{ tmp_x + target_size, tmp_y + target_size, 0.0f, 1.0f, u_right, v_bottom },
		{ tmp_x, tmp_y + target_size, 0.0f, 1.0f, u_left, v_bottom },
	};

	DirectParameter::_D3DDevice->SetTexture(0, DirectParameter::_textureList.at(image)->_texutreData);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DirectParameter::_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, verticies, sizeof(CustomVertex1));
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void TSYGraphics::DrawGraphMaptipAlpha(int x, int y, const std::string& image, int target_id, int target_size, int alpha)
{
	const int texture_size = DirectParameter::_textureList.at(image)->_width;

	const float u = static_cast<float>(target_size * (target_id % (texture_size / target_size)));
	const float v = static_cast<float>(target_size * (target_id / (texture_size / target_size)));

	const float tmp_x = static_cast<float>(x);
	const float tmp_y = static_cast<float>(y);

	float u_left = u / DirectParameter::_textureList.at(image)->_width;
	float u_right = (u + target_size) / DirectParameter::_textureList.at(image)->_width;
	float v_top = v / DirectParameter::_textureList.at(image)->_height;
	float v_bottom = (v + target_size) / DirectParameter::_textureList.at(image)->_height;

	if (alpha > 0xff) alpha = 0xff;
	if (alpha < 0x00) alpha = 0x00;
	const DWORD tmp_color = D3DCOLOR_RGBA(0xff, 0xff, 0xff, alpha);

	CustomVertex2 verticies[4] =
	{
		{ tmp_x, tmp_y, 0.0f, 1.0f, tmp_color, u_left, v_top },
		{ tmp_x + target_size, tmp_y, 0.0f, 1.0f, tmp_color, u_right, v_top },
		{ tmp_x + target_size, tmp_y + target_size, 0.0f, 1.0f, tmp_color, u_right, v_bottom },
		{ tmp_x, tmp_y + target_size, 0.0f, 1.0f, tmp_color, u_left, v_bottom },
	};

	DirectParameter::_D3DDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	DirectParameter::_D3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	DirectParameter::_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DirectParameter::_D3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DirectParameter::_D3DDevice->SetTexture(0, DirectParameter::_textureList.at(image)->_texutreData);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DirectParameter::_D3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, verticies, sizeof(CustomVertex2));
	DirectParameter::_D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
}

void TSYGraphics::DrawLine(int x1, int y1, int x2, int y2)
{
	LPD3DXLINE line;
	D3DXCreateLine(DirectParameter::_D3DDevice, &line);

	const float tmp_x1 = static_cast<float>(x1);
	const float tmp_y1 = static_cast<float>(y1);
	const float tmp_x2 = static_cast<float>(x2);
	const float tmp_y2 = static_cast<float>(y2);

	D3DXVECTOR2 vec[] = {
		D3DXVECTOR2(tmp_x1,tmp_y1),
		D3DXVECTOR2(tmp_x2,tmp_y2 + 1.0f),
	};
	line->Begin();
	line->Draw(vec, 2, D3DCOLOR_ARGB(255, 255, 255, 255));
	line->End();
	line->Release();
}

void TSYGraphics::DrawLineColor(int x1, int y1, int x2, int y2, ColorARGB color)
{
	LPD3DXLINE line;
	D3DXCreateLine(DirectParameter::_D3DDevice, &line);

	const float tmp_x1 = static_cast<float>(x1);
	const float tmp_y1 = static_cast<float>(y1);
	const float tmp_x2 = static_cast<float>(x2);
	const float tmp_y2 = static_cast<float>(y2);

	D3DXVECTOR2 vec[] = {
		D3DXVECTOR2(tmp_x1,tmp_y1),
		D3DXVECTOR2(tmp_x2,tmp_y2 + 1.0f),
	};
	line->Begin();
	line->Draw(vec, 2, D3DCOLOR_ARGB(color._a, color._r, color._g, color._b));
	line->End();
	line->Release();
}

void TSYGraphics::DrawSquare(int x1, int y1, int x2, int y2)
{
	LPD3DXLINE line;
	D3DXCreateLine(DirectParameter::_D3DDevice, &line);

	const float tmp_x1 = static_cast<float>(x1);
	const float tmp_y1 = static_cast<float>(y1);
	const float tmp_x2 = static_cast<float>(x2);
	const float tmp_y2 = static_cast<float>(y2);

	D3DXVECTOR2 vec[] = {
		D3DXVECTOR2(tmp_x1,tmp_y1),
		D3DXVECTOR2(tmp_x2,tmp_y1),
		D3DXVECTOR2(tmp_x2,tmp_y2),
		D3DXVECTOR2(tmp_x1,tmp_y2),
		D3DXVECTOR2(tmp_x1,tmp_y1)
	};
	line->Begin();
	line->Draw(vec, 5, D3DCOLOR_ARGB(255, 255, 255, 255));
	line->End();
	line->Release();
}

void TSYGraphics::DrawSquareColor(int x1, int y1, int x2, int y2, ColorARGB color)
{
	LPD3DXLINE line;
	D3DXCreateLine(DirectParameter::_D3DDevice, &line);

	const float tmp_x1 = static_cast<float>(x1);
	const float tmp_y1 = static_cast<float>(y1);
	const float tmp_x2 = static_cast<float>(x2);
	const float tmp_y2 = static_cast<float>(y2);

	D3DXVECTOR2 vec[] = {
		D3DXVECTOR2(tmp_x1,tmp_y1),
		D3DXVECTOR2(tmp_x2,tmp_y1),
		D3DXVECTOR2(tmp_x2,tmp_y2),
		D3DXVECTOR2(tmp_x1,tmp_y2),
		D3DXVECTOR2(tmp_x1,tmp_y1)
	};
	line->Begin();
	line->Draw(vec, 5, D3DCOLOR_ARGB(color._a, color._r, color._g, color._b));
	line->End();
	line->Release();
}
//----------------------------------------------------------------------------------------------------

//　プライベートメソッド

//----------------------------------------------------------------------------------------------------

