#include "Renderer.h"

void Renderer::SetFrameBuffer(u32* frameBuffer, unsigned int width, unsigned int height)
{
	m_frameBuffer = frameBuffer;
	m_width = width;
	m_height = height;
}

void Renderer::SetPixel(unsigned int x, unsigned int y, const Color& color)
{
	if (x < 0 || x >= m_width || y < 0 || y >= m_height)
		return;


	m_frameBuffer[y * m_width + x] = color.ToInt();
}

void Renderer::Clear()
{
	memset(m_frameBuffer, 0, sizeof(u32) * m_height * m_width);
}

void Renderer::DrawLine(const Color& c1, const Color& c2, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	int D = 2 * dy - dx;
	SetPixel(x0, y0, c1);

	int y = y0;

	for (int x = x0 + 1; x <= x1; x++)
	{
		if (D > 0)
		{
			y++;
			SetPixel(x, y, c1);
			D += (2 * dy - 2 * dx);
		}
		else
		{
			SetPixel(x, y, c1);
			D += 2 * dy;
		}
	}
}

void Renderer::DrawLine(const Color& c, float x0, float y0, float x1, float y1)
{
	float dx = (x1 - x0);
	float dy = (y1 - y0);

	if (dx == 0.0f && dy == 0.0f) 
	{
		SetPixel(x1, y1, c);
		return;
	}

	if (fabs(dx) > fabs(dy)) 
	{
		float xmin, xmax;

		if (x0 < x1) 
		{
			xmin = x0;
			xmax = x1;
		}
		else 
		{
			xmin = x1;
			xmax = x0;
		}

		float slope = dy / dx;
		for (float x = xmin; x <= xmax; x += 1.0f) 
		{
			float y = y1 + ((x - x1) * slope);
			SetPixel(x, y, c);
		}
	}
	else {
		float ymin, ymax;

		if (y0 < y1) 
		{
			ymin = y0;
			ymax = y1;
		}
		else 
		{
			ymin = y1;
			ymax = y0;
		}

		float slope = dx / dy;
		for (float y = ymin; y <= ymax; y += 1.0f) 
		{
			float x = x1 + ((y - y1) * slope);
			SetPixel(x, y, c);
		}
	}
}