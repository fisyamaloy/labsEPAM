#pragma once
#include "ShapesI.h"

class Circle : public ShapeI {
private:
	const double PI = 3.14;
	double radius;
public:
	Circle(const double _radius = 0) : radius(_radius) {
		assert(radius >= 0);
	}

	double getArea() const override {
		return PI * radius * radius;
	}

	double getPerimeter() const override {
		return 2 * PI * radius;
	}

	double getRadius() const {
		return radius;
	}
};