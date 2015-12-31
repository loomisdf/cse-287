#include "MyRectangle.h"

MyRectangle::MyRectangle(int x, int y, int width, int height, color c)
	:x(x), y(y), width(width), height(height), myColor(c)
{
}

MyRectangle::~MyRectangle()
{
}

void MyRectangle::draw(ColorBuffer& colorBuffer) {
	cout << "drawing rectangle" << endl;

	// x and y are the positions of the rectangle
	for (int row = x; row < x + width; row++){
		for (int col = y; col < y + height; col++){
			colorBuffer.setPixel(row, col, myColor);
		}
	}
}

int MyRectangle::getX() {
	return this->x;
}

int MyRectangle::getY() {
	return this->y;
}

int MyRectangle::getWidth() {
	return this->width;
}

int MyRectangle::getHeight() {
	return this->height;
}

color MyRectangle::getColor() {
	return this->myColor;
}

void MyRectangle::setX(int x) {
	this->x = x;
}

void MyRectangle::setY(int y) {
	this->y = y;
}

void MyRectangle::setColor(color c) {
	this->myColor = c;
}