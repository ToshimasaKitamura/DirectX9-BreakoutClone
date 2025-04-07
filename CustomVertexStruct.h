#pragma once

#include <Windows.h>

struct CustomVertex1
{
	float x;
	float y;
	float z;

	float rhw;

	float texture_x;
	float texture_y;
};

struct CustomVertex2
{
	float x;
	float y;
	float z;

	float rhw;

	DWORD color;

	float texture_x;
	float texrure_y;
};