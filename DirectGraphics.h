#pragma once

#include <d3d9.h>

class DirectGraphics final
{
public:
	explicit DirectGraphics() = default;
	~DirectGraphics() = default;
	void NewGraphics(const bool isWindowMode) const;
	void ReleaseGraphics() const;
	void DrawStart() const;
	void DrawEnd() const;
private:
	void SetWinPP(D3DPRESENT_PARAMETERS* winPP) const;
	void SetFullPP(D3DPRESENT_PARAMETERS* fullPP) const;
	void CreateIDirect3D9() const;
	void CreateIDiret3DDevice9(const bool isWindowMode) const;
	void SetUpViewPort(const bool isWindowMode) const;
};

