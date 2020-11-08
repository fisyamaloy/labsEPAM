#include <iostream>
#include "Vector.h"

int main() {
	Vector<int> v(5);
	std::cout << v;
	for (int i = 0; i < v.getSize(); ++i) {
		v[i] = i + 1;
	}
	std::cout << v;
	v.insert(3, 12312);
	std::cout << v;

	try {
		v.pop_back();
		v.pop_front();
	} catch (const VectorException& e) {
		std::cerr << e.what();
	}
	std::cout << v;

	try {
		v.erase(1, 2);
	} catch (const std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << v;
	
	try {
		v.pop_back();
	} catch (const std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << v;

	v.push_back(10);
	v.push_back(-5);
	v.push_back(8);
	std::cout << v;

	v.resize(30);
	std::cout << v;
	v.push_back(1232153);
	v.push_front(-2324);
	std::cout << v;

	v.insert(2, 40);
	std::cout << v;

	v.erase(0, 4);
	std::cout << v;
}