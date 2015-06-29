#include "Color.h"

Color::Color(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	a = 1.0f;
}

Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

u32 Color::ToInt() const
{
	u32 r = (u32)(this->r * 255.0f);
	u32 g = (u32)(this->g * 255.0f);
	u32 b = (u32)(this->b * 255.0f);
	u32 a = (u32)(this->a * 255.0f);
	return b | (g << 8) | (r << 16) | (a << 24);
}