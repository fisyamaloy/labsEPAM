#pragma once
#include "IShapes.h"
#include <cmath>

class Circle : public IShape {
private:
	const double PI = acos(-1);
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