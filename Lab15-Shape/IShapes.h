#pragma once
#include<cassert>

// �������������� 4 ������� SOLID - ISP : �������� ����������� �� ����� ������ ����������.

class IShape {
public:
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
};

class ISolidShape {
public:
	virtual double getVolume() const = 0;
};