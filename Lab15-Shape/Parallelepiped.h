#pragma once
#include "IShapes.h"
class Parallelepiped : public ISolidShape {
private:
	double length;
	double width;
	double height;
public:
	Parallelepiped(const double _length, const double _width, const double _height) : 
		length(_length), width(_width), height(_height) {};

	double getVolume() const {
		return length * width * height;
	}
};

