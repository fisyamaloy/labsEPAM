#pragma once

template<class T>
class Array {
public:
	Array(T*& A, const int length);
	~Array();
	double getAverageValue();

private:
	T* A;
	int length;
};

template<class T>
Array<T>::Array(T*& A, const int length) {
	this->A = A;
	this->length = length;
}

template<class T>
Array<T>::~Array() {
	delete[] A;
}

template<class T>
double Array<T>::getAverageValue() {
	double sum = 0;
	for (int i = 0; i < length; i++) {
		sum += A[i];
	}

	return sum / length;
}