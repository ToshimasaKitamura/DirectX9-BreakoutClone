#include "DirectGraphics.h"
#include "Define.h"
#include "Error.h"
#include "DirectParameter.h"

void DirectGraphics::NewGraphics(const bool isWindowMode) const
{
	CreateIDirect3D9();
	SetWinPP(&DirectParameter::_winPP);
	SetFullPP(&DirectParameter::_fullPP);
	CreateIDiret3DDevice9(isWindowMode);
	SetUpViewPort(isWindowMode);
}

void DirectGraphics::ReleaseGraphics() const
{
	DirectParameter::_D3DDevice->Release();
	DirectParameter::_D3D->Release();
}

void DirectGraphics::DrawStart() const
{
	Error error;
	DirectParameter::_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(40, 0, 60), 0.0f, 0);
	if (D3D_OK != DirectParameter::_D3DDevice->BeginScene()) error.Issue("005");
}

void DirectGraphics::DrawEnd() const
{
	DirectParameter::_D3DDevice->EndScene();
	DirectParameter::_D3DDevice->Present(NULL, NULL, NULL, NULL);
}

void DirectGraphics::SetWinPP(D3DPRESENT_PARAMETERS* winPP) const
{
	winPP->BackBufferWidth = 0;
	winPP->BackBufferHeight = 0;
	winPP->BackBufferFormat = D3DFMT_UNKNOWN;
	winPP->BackBufferCount = 1;
	winPP->MultiSampleType = D3DMULTISAMPLE_NONE;
	winPP->MultiSampleQuality = 0;
	winPP->SwapEffect = D3DSWAPEFFECT_DISCARD;
	winPP->hDeviceWindow = FindWindow(Define::_mainWinClass, Define::_mainWinTitle);
	winPP->Windowed = TRUE;
	winPP->EnableAutoDepthStencil = FALSE;
	winPP->AutoDepthStencilFormat = D3DFMT_D16;
	winPP->Flags = 0;
	winPP->FullScreen_RefreshRateInHz = 0;
	winPP->PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}

void DirectGraphics::SetFullPP(D3DPRESENT_PARAMETERS* fullPP) const
{
	fullPP->BackBufferWidth = Define::_mainWinWidth;
	fullPP->BackBufferHeight = Define::_mainWinHeight;
	fullPP->BackBufferFormat = D3DFMT_A8R8G8B8;
	fullPP->BackBufferCount = 1;
	fullPP->MultiSampleType = D3DMULTISAMPLE_NONE;
	fullPP->MultiSampleQuality = 0;
	fullPP->SwapEffect = D3DSWAPEFFECT_DISCARD;
	fullPP->hDeviceWindow = FindWindow(Define::_mainWinClass, Define::_mainWinTitle);
	fullPP->Windowed = FALSE;
	fullPP->EnableAutoDepthStencil = FALSE;
	fullPP->AutoDepthStencilFormat = D3DFMT_D16;
	fullPP->Flags = 0;
	fullPP->FullScreen_RefreshRateInHz = 60;
	fullPP->PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}

void DirectGraphics::CreateIDirect3D9() const 
{
	Error error;
	DirectParameter::_D3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (DirectParameter::_D3D == nullptr) error.Issue("006");
}

void DirectGraphics::CreateIDiret3DDevice9(const bool isWindowMode) const
{
	Error error;
	D3DPRESENT_PARAMETERS* tmp;
	if (isWindowMode) tmp = &DirectParameter::_winPP;
	else tmp = &DirectParameter::_fullPP;

	HRESULT result = DirectParameter::_D3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		FindWindow(Define::_mainWinClass, Define::_mainWinTitle),
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
		tmp,
		&DirectParameter::_D3DDevice);
	if (FAILED(result)) error.Issue("007");
}

void DirectGraphics::SetUpViewPort(const bool isWindowMode) const
{
	D3DVIEWPORT9 view_port;
	D3DPRESENT_PARAMETERS* tmp;
	if (isWindowMode) tmp = &DirectParameter::_winPP;
	else tmp = &DirectParameter::_fullPP;

	view_port.X = 0;
	view_port.Y = 0;
	view_port.Width = tmp->BackBufferWidth;
	view_port.Height = tmp->BackBufferHeight;
	view_port.MinZ = 0.0f;
	view_port.MaxZ = 1.0f;

	Error error;

	HRESULT result = DirectParameter::_D3DDevice->SetViewport(&view_port);
	if (FAILED(result)) error.Issue("008");
}