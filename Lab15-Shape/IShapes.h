#pragma once
#include<cassert>

// Поддерживается 4 принцип SOLID - ISP : нтерфейс разделяется на более мелкие интерфейсы.

class IShape {
public:
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
};

class ISolidShape {
public:
	virtual double getVolume() const = 0;
};