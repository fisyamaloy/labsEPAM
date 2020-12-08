#pragma once
#include "ShapesI.h"
class Parallelepiped : public SolidShapeI {
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

