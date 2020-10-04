
#include <iostream>
#define EPSILON 0.00001

using namespace std;

const int SIZE = 10;

template <class T> 
class Vector {
public:
	Vector(T* massive);
	Vector();
	~Vector();
	void sort();
	void showMassive();
	T getMinElem();
	T getAvarageElemsValue();
	T getMaxElem();
	T getSumAfterMinElem();

private:
	void permutation(T& elem1, T& elem2);
	T* A;
};

template <typename T> 
Vector<T>::Vector(T* massive) {
	A = massive;
}

template <typename T> 
Vector<T>::Vector() {
	A = nullptr;
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
	for (int i = 0; i < SIZE - 2; i++) {
		if (i % 2 == 0) {
			for (int j = i + 2; j < SIZE; j += 2) {
				permutation(A[i], A[j]);
			}
		} else {
			for (int j = i + 2; j < SIZE; j += 2) {
				permutation(A[j], A[i]);
			}
		}
	}
}

template <typename T> 
void Vector<T>::permutation(T& elem1, T& elem2) {
	if (elem1 - elem2 < EPSILON) {
		T temp = elem1;
		elem1 = elem2;
		elem2 = temp;
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
T Vector<T>::getMaxElem(){
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

int main()
{
	int* A;
	fillMassive(A);
	Vector<int> v(A);
	v.showMassive();
	v.sort();
	v.showMassive();
	cout << "Minimum elem is " << v.getMinElem() << endl;
	cout << "Average elem is " << v.getAvarageElemsValue() << endl;
	cout << "Maximum elem is " << v.getMaxElem() << endl;

	double* B;
	fillMassive(B);
	Vector<double> v1(B);
	v1.showMassive();
	cout << "sum after minimum elem is " << v1.getSumAfterMinElem() << endl;
}

template <typename T> void fillMassive(T*& A) {
	A = new T[SIZE];
	cout << "input " << SIZE << " elems" << endl;

	for (int i = 0; i < SIZE; i++) {
		cin >> A[i];
	}
}
