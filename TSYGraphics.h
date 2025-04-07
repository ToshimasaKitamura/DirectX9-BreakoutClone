#pragma once

#include <string>
#include "Color.h"

class TSYGraphics final
{
public:
	explicit TSYGraphics() = default;
	~TSYGraphics() = default;

	static void LoadGraph();
	static void ReleaseGraph();
	static void DrawGraph(int x, int y, const std::string& image);
	static void DrawGraph(float x, float y, const std::string& image);
	static void DrawGraphAlpha(int x, int y, const std::string& image, int alpha);
	static void DrawGraphMaptip(int x, int y, const std::string& image, int target_id, int target_size);
	static void DrawGraphMaptipAlpha(int x, int y, const std::string& image, int target_id, int target_size, int alpha);
	static void DrawLine(int x1, int y1, int x2, int y2);
	static void DrawLineColor(int x1, int y1, int x2, int y2, ColorARGB color);
	static void DrawSquare(int x1, int y1, int x2, int y2);
	static void DrawSquareColor(int x1, int y1, int x2, int y2, ColorARGB color);
};

