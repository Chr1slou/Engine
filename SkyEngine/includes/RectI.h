#pragma once

/// <summary>
/// rect of ints
/// </summary>
struct RectI
{
	RectI() : RectI(0, 0, 0, 0) {};
	RectI(int _x, int _y, int _w, int _h)
		{ x = _x; y = _y; w = _w; h = _h; }
	int x;
	int y;
	int w;
	int h;
};