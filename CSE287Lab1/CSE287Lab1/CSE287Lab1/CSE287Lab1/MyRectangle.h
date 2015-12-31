#pragma once

#include "BasicIncludesAndDefines.h"

class MyRectangle
{
public:
	MyRectangle(int x = 50, int y = 50,
				int width = 100, int height = 50,
				color c = color(1.0, 1.0, 1.0, 1.0));
	~MyRectangle();

	virtual void draw(ColorBuffer& colorBuffer);

	int getX();
	int getY();

	int getWidth();
	int getHeight();

	color getColor();

	void setX(int x);
	void setY(int y);

	void setWidth(int width);
	void setHeight(int height);

	void setColor(color c);

protected:
	int x;
	int y;
	int width;
	int height;

	color myColor;
};