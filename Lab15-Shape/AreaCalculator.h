#pragma once
#include "IShapes.h"
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

/*
	1) �������������� ������� SOLID - SRP: ���������� ������ AreaCalculator �� ����� �������� ������ ������������,
	��� ��� ��� ��������� �������� SRP. ��� ����� �� ���������� ��������� ����� SumCalculatorOutputter.
	2) �������������� ������� SOLID - OCP: ������ ����, ����� ��������� ������� ����� � ������� �������� �� ����,
	���������� ������� ������������ ������ ����� �����. �� ����������� �� ���� ��������, � ������ ���� ������� 
	�������� ��� ����������. ������ �� ����� ������� ������ ����� ����� � �������� ��� ��� ���������� �����, �� ������� ��� ���.
	3) �������������� ������� SOLID - LSP: ��� ���� �������� ������������� ������ ����� ����������� ���� � ��� �� ��� ��� �������.
	4) �������������� ������� SOLID - DIP: ��� ������ ������� ����� ����������.
*/

class IAreaCalculator {
public:
	virtual double getAreasSum() const = 0;
};

class AreaCalculator : public IAreaCalculator {
private:
	std::vector<IShape*> shapes;
public:
	AreaCalculator(std::vector<IShape*>&& shapes = {}) {
		this->shapes = shapes;
		shapes.clear();
	}

	double getAreasSum() const {
		auto sum = std::accumulate(shapes.cbegin(), shapes.cend(), (double)0, [=](double accumulator, const IShape* shape) -> double {
			return accumulator + shape->getArea();
		});

		return sum;
	}
};


class ISumCalculatorOutputter {
public:
	virtual void console() const = 0;
	virtual void file(std::string path) const = 0;
};

class AreaCalculatorOutputter : public ISumCalculatorOutputter {
private:
	AreaCalculator areas;
public:
	AreaCalculatorOutputter(const AreaCalculator& _areas) : areas(_areas) { }

	void console() const override {
		std::cout << areas.getAreasSum() << std::endl;
	}

	void file(std::string path) const override {
		std::ofstream fout(path);
		assert(fout);
		fout << areas.getAreasSum() << '\n';
		fout.close();
	}
};