#include <iostream>
#include <string>
#include "VectException.h"

using namespace std;

class Vect {
private:
	int* A;
	size_t length;

public:
	Vect(const int* A, const size_t length) {
		this->length = length;
		this->A = new int[length];
		for (int i = 0; i < length; ++i) {
			this->A[i] = A[i];
		}
	}

	~Vect() {
		delete[] A;
	}

	int operator[](const int i) {
		if (i < 0 || i >= length)
			throw VectException("Выход за границы массива", VectException::OUT_OF_RANGE);

		return A[i];
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	size_t length = 4;
	int* A = new int[length];
	for (int i = 0; i < length; ++i) {
		A[i] = 10 * i + 20 - i * 3;
	}

	Vect v(A, 4);
	try {
		cout << v[4] << endl;
	} catch (VectException& ex) {
		cerr << ex.what() << " " << ex.getDataState() << endl;
	}

	return 0;
}