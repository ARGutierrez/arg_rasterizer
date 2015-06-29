#ifndef RENDERER_H
#define RENDERER_H

#include "MathTypes.h"
#include "Color.h"
#include <cstring>
#include <math.h>

class Renderer
{
public:
	void SetFrameBuffer(u32*, unsigned int, unsigned int);
	void SetPixel(unsigned int, unsigned int, const Color& color);
	void Clear();

	// Both functions utilize Bresenham's Line Algorithm
	void DrawLine(const Color& c1, const Color& c2, int x0, int y0, int x1, int y1);
	void DrawLine(const Color& c, float x0, float y0, float x1, float y1);

private:
	u32* m_frameBuffer;
	unsigned int m_width;
	unsigned int m_height;
};

#endif