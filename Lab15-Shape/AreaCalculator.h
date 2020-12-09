#pragma once
#include "IShapes.h"
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
	3) Поддерживается принцип SOLID - LSP: для всех подтипов родительского класса будет выполняться один и тот же код без падений.
	4) Поддерживается принцип SOLID - DIP: Все классы сделаны через интерфейсы.
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