#include <iostream>
#include <iostream>
#include <string>
#include <assert.h>
#include <ctime>

using namespace std;

class Array {
public:
	Array(const int rowsAmount, const int columnsAmount) {
		assert(rowsAmount > 0 && columnsAmount > 0);
		this->rowsAmount = rowsAmount;
		this->columnsAmount = columnsAmount;
		fillArray();
		showArray();
	}

	~Array() {
		for (int i = 0; i < rowsAmount; i++) {
			delete[] A[i];
		}

		delete[] A;
	}

	void showArray() {
		for (int i = 0; i < rowsAmount; i++) {
			for (int j = 0; j < columnsAmount; j++) {
				cout << A[i][j] << '\t';
			}
			cout << endl;
		}
	}
	
	friend int getNumberOfFirstNegativeRow(Array& arr);

private:
	int** A;
	unsigned int rowsAmount;
	unsigned int columnsAmount;

	void fillArray() {
		srand(time(0));
		A = new int*[rowsAmount];
		for (int i = 0; i < rowsAmount; i++) {
			A[i] = new int[columnsAmount];
			for (int j = 0; j < columnsAmount; j++) {
				A[i][j] = rand() % 30 - 20;
			}
		}
	}
};


/*
* Функция возвращает индекс первой строки двумерного массива, которая не имеет положительных элементов.
* Функция возвращает -1, если в каждой строке массива существует положительный элемент.
*/
int getNumberOfFirstNegativeRow(Array& arr) {
	for (int i = 0; i < arr.rowsAmount; i++) {
		bool rowHasPositiveElem = false;
		for (int j = 0; j < arr.columnsAmount; j++) {
			if (arr.A[i][j] > 0) {
				rowHasPositiveElem = true;
				break;
			}
		}

		if (!rowHasPositiveElem) {
			return i;
		}
	}

	return -1;
}

int main() {
	Array array(3, 4);
	
	int index = getNumberOfFirstNegativeRow(array);
	if (index != -1) {
		cout << "index of first row, in which all numbers are negative is " << index << endl;
	} else {
		cout << "All rows of arrays contain positive number" << endl;
	}
}