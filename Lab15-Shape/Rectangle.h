#pragma once
#include "ShapesI.h"

class Rectangle : public ShapeI {
private:
	double height;
	double width;
public:
	Rectangle(const double _height = 0, const double _width = 0) : height(_height), width(_width) {
		assert(height >= 0 && width >= 0);
	}

	double getArea() const override {
		return height * width;
	}

	double getPerimeter() const override {
		return 2 * (height + width);
	}
};