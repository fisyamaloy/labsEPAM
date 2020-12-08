#pragma once
#include "ShapesI.h"
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

/*
	1) Поддерживается принцип SOLID - SRP: экземпляры класса AreaCalculator не могут выводить данные пользователю,
	так как это нарушение принципа SRP. Для этого мы определили отдельный класс SumCalculatorOutputter.
	2) Поддерживается принцип SOLID - OCP: вместо того, чтобы вычислять площади фигур с помощью проверки по типу,
	вычисление площади производится внутри наших фигур. Мы избавляемся от кучи проверок, и делаем нашу систему 
	открытой для расширения. Теперь мы можем создать другой класс формы и передать его при вычислении суммы, не нарушая наш код.
	3)
*/

class AreaCalculator {
private:
	std::vector<ShapeI*> shapes;
public:
	AreaCalculator(std::vector<ShapeI*>&& shapes = {}) {
		this->shapes = shapes;
		shapes.clear();
	}

	double getAreasSum() const {
		auto sum = std::accumulate(shapes.cbegin(), shapes.cend(), 0, [](double accumulator, const ShapeI* shape) {
			return accumulator + shape->getArea();
		});

		return sum;
	}
};

class SumCalculatorOutputter {
private:
	AreaCalculator areas;
public:
	SumCalculatorOutputter(const AreaCalculator& _areas) : areas(_areas) { }

	void console() const {
		std::cout << areas.getAreasSum() << std::endl;
	}

	void file(std::string path) const {
		std::ofstream fout(path);
		assert(fout);
		fout << areas.getAreasSum() << std::endl;
		fout.close();
	}
};