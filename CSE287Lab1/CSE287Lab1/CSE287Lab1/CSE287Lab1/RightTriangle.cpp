#include "RightTriangle.h"


RightTriangle::RightTriangle(int x, int y, int width, color c)
	:x(x), y(y), width(width), myColor(c)
{
}

RightTriangle::~RightTriangle()
{
}

void RightTriangle::draw(ColorBuffer& colorBuffer) {
	int yWidth = this->getWidth();

	for (int row = x; row < x + width; row++) {
		for (int col = y; col < y + yWidth; col++) {
			colorBuffer.setPixel(row, col, myColor);
		}
		yWidth--;
	}
}

int RightTriangle::getX() {
	return this->x;
}

int RightTriangle::getY() {
	return this->y;
}

int RightTriangle::getWidth() {
	return this->width;
}

color RightTriangle::getColor() {
	return this->myColor;
}

void RightTriangle::setX(int x) {
	this->x = x;
}

void RightTriangle::setY(int y) {
	this->y = y;
}

void RightTriangle::setColor(color c) {
	this->myColor = c;
}
