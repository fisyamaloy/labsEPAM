#include <iostream>
#include "Unique.h"
#include <string>
#include <memory>
#include "Shared.h"
#define DEBUG

using namespace std;

struct Car {
	string model;
	Car(string model = "kopeyka") {
		this->model = model;
	}

	friend std::ostream& operator << (std::ostream& out, const Car& car) {
		out << car.model;
		return out;
	}
};

int main() {
	Unique<Car> A{ new Car("Max") };
	cout << *A << ' ' << *(A.get()) << endl;
	Unique<Car> B{ std::move(A) };
	Unique<Car> C{ new Car("Audi") };

	B.release();
	C.reset();

	B.swap(C);
	cout << *B << ' ' << *B.get() << endl;

	/*Shared<int> A{ new int{3} };
	Shared<int> B(A);
	Shared<int> C{ A };*/
}