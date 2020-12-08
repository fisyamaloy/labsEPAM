#pragma once
#include<cassert>

class ShapeI {
public:
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
};

class SolidShapeI {
	virtual double getVolume() const = 0;
};