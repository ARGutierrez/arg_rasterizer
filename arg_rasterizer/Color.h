#ifndef COLOR_H
#define COLOR_H

#include "MathTypes.h"

class Color
{
public:
	float r, g, b, a;
	
	Color();
	~Color();
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);

	u32 ToInt() const;
};

#endif