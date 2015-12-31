#pragma once

#include "BasicIncludesAndDefines.h"

class RightTriangle
{
public:
	RightTriangle(int x = 50, int y = 50,
				  int width = 50,
				  color c = color(1.0, 1.0, 1.0, 1.0));
	~RightTriangle();

	virtual void draw(ColorBuffer& colorBuffer);

	int getX();
	int getY();

	int getWidth();

	color getColor();

	void setX(int x);
	void setY(int y);

	void setWidth(int width);

	void setColor(color c);

protected:
	int x;
	int y;
	int width;

	color myColor;
};