
#include <iostream>
#include <ctime>
#define EPSILON 0.00001

using namespace std;

const int SIZE = 10;

template <class T>
class Vector {
public:
	Vector(T*& massive);
	Vector();
	~Vector();
	void sort();
	void showMassive();
	T getMinElem();
	T getAvarageElemsValue();
	T getMaxElem();
	T getSumAfterMinElem();

private:
	T* A;
};

template <typename T>
Vector<T>::Vector(T*& massive) {
	A = massive;
}

template <typename T>
Vector<T>::Vector() {
	A = new int[10];
	for (int i = 9; i >= 0; i--) {
		A[i] = i;
	}
}

template <typename T>
Vector<T>::~Vector() {
	delete[] A;
}

template <typename T>
void Vector<T>::showMassive() {
	for (int i = 0; i < SIZE; i++) {
		cout << "A[" << i << "] = " << A[i] << " " << endl;
	}
	cout << endl;
}

template <typename T>
void Vector<T>::sort() {
	cout << "sort: " << endl;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (A[j] - A[i] < EPSILON) {
				T temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}
		}
	}
}

template <typename T>
T Vector<T>::getMinElem() {
	T minElem = A[0];
	for (int i = 1; i < SIZE; i++) {
		if (minElem - A[i] > EPSILON) {
			minElem = A[i];
		}
	}

	return minElem;
}

template <typename T>
T Vector<T>::getAvarageElemsValue() {
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += A[i];
	}

	return sum / SIZE;
}

template <typename T>
T Vector<T>::getMaxElem() {
	T maxElem = A[0];
	for (int i = 1; i < SIZE; i++) {
		if (maxElem < A[i]) {
			maxElem = A[i];
		}
	}

	return maxElem;
}

template <typename T>
T Vector<T>::getSumAfterMinElem() {
	int minElemIndex = 0;
	for (int i = 0; i < SIZE; i++) {
		if (A[minElemIndex] - A[i] > EPSILON) {
			minElemIndex = i;
		}
	}

	T sum = 0;
	for (int i = minElemIndex + 1; i < SIZE; i++) {
		sum += A[i];
	}

	return sum;
}

template <typename T>
void fillMassive(T*& T1);

template <typename T>
void fillMassiveBtRandomValues(T*& A);

int main()
{
	int* A;
	fillMassiveBtRandomValues(A);
	Vector<int> v(A);
	v.showMassive();
	v.sort();
	v.showMassive();
	cout << "Minimum elem is " << v.getMinElem() << endl;
	cout << "Average elem is " << v.getAvarageElemsValue() << endl;
	cout << "Maximum elem is " << v.getMaxElem() << endl;

	double* B;
	fillMassiveBtRandomValues(B);
	Vector<double> v1(B);
	v1.showMassive();
	cout << "sum after minimum elem is " << v1.getSumAfterMinElem() << endl;
}

template <typename T> 
void fillMassive(T*& A) {
	A = new T[SIZE];
	cout << "input " << SIZE << " elems" << endl;

	for (int i = 0; i < SIZE; i++) {
		cin >> A[i];
	}
}

template <typename T>
void fillMassiveBtRandomValues(T*& A) {
	A = new T[SIZE];

	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		A[i] = 0.1 * (rand() % 200 - 100); // -20 до 19
	}
}