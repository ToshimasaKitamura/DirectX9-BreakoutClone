#include "Frame.h"
#include "Define.h"
#include "TSYGraphics.h"

void Frame::Draw() const
{
	for (int i = 0; i < _outFrameVNum; ++i)
	{
		TSYGraphics::DrawGraph(0, i * _frameLength, "frameV(4x16).png");
		TSYGraphics::DrawGraph(Define::_mainWinWidth - _frameThickness, i * _frameLength, "frameV(4x16).png");
	}
	for (int i = 0; i < _outFrameHNum; ++i)
	{
		TSYGraphics::DrawGraph(i * _frameLength, 0, "frameH(16x4).png");
	}
	for (int i = 0; i < _inFrameVNum; ++i)
	{
		TSYGraphics::DrawGraph(_screenFrameSize - _frameThickness,
			_screenFrameSize - _frameThickness + i * _frameLength, "frameV(4x16).png");
		TSYGraphics::DrawGraph(Define::_mainWinWidth - _screenFrameSize,
			_screenFrameSize - _frameThickness + i * _frameLength, "frameV(4x16).png");
	}
	for (int i = 0; i < _inFrameHNum; ++i) 
	{
		TSYGraphics::DrawGraph(_screenFrameSize + i * _frameLength,
			_screenFrameSize - _frameThickness, "frameH(16x4).png");
	}		
}