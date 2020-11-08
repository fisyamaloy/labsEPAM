#pragma once
#include "VectorException.h"

template<class T>
class Vector : VectorException {
private:
	T* A;
	size_t vSize;
	size_t maxSize;
	void alloc_new();
public:
	Vector();
	Vector(const size_t maxSize);
	Vector(const T*& arr);
	~Vector() {
		delete[] A;
	}

	constexpr size_t getSize() const noexcept {
		return vSize;
	}
	constexpr size_t getCapacity() const noexcept {
		return maxSize;
	}
	const T& back() const {
		return vSize > 0 ? A[vSize - 1] : throw VectorException(ErrorsCodes::OUT_OF_RANGE);
	}
	const T& front() const {
		return vSize > 0 ? A[0] : throw VectorException(ErrorsCodes::OUT_OF_RANGE);
	}
	T& at(const int index) const {
		return index < vSize ? A[index] : throw VectorException(ErrorsCodes::OUT_OF_RANGE);
	}

	void pop_front() {
		vSize > 0 ? erase(0, 0) : throw VectorException(ErrorsCodes::VECTOR_IS_EMPTY);
	}
	void pop_back() {
		vSize > 0 ? erase(vSize - 1, vSize - 1) : throw VectorException(ErrorsCodes::VECTOR_IS_EMPTY);
	}
	void push_front(const T& elem);
	void push_back(const T& elem);
	void resize(const size_t vSize) noexcept;
	void insert(const unsigned position, const T& elem);
	void erase(const unsigned firstPosition, const unsigned secondPosition);
	void clear();

	T& operator[](const int index) const {
		return A[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
		for (int i = 0; i < v.vSize; ++i) {
			os << v[i] << " ";
		}
		os << std::endl;
		os << "vSize: " << v.vSize << " " << "maxSize: " << v.maxSize << std::endl;
		os << "===============================" << std::endl;

		return os;
	}
};

template<class T>
Vector<T>::Vector() {
	maxSize = 30;
	A = new T[maxSize];
	vSize = 0;
}

template<class T>
Vector<T>::Vector(const size_t vSize) {
	this->maxSize = vSize * 2;
	this->vSize = vSize;
	A = new T[vSize];
	for (int i = 0; i < vSize; ++i) {
		A[i] = 0;
	}
}

template<class T>
void Vector<T>::alloc_new() {
	maxSize = vSize * 2;
	T* tempArr = new T[maxSize];
	for (int i = 0; i < vSize; ++i) {
		tempArr[i] = A[i];
	}

	delete[] A;
	A = tempArr;
}

template<class T>
Vector<T>::Vector(const T*& A) {
	T* tempArr = new T[maxSize];
	for (int i = 0; i < vSize; ++i) {
		tempArr[i] = A[i];
	}

	delete[] A;
	A = tempArr;
}

template<class T>
void Vector<T>::push_back(const T& elem) {
	if (vSize + 1 > maxSize) {
		alloc_new();
	}
	
	A[vSize] = elem;
	vSize++;
}

template<class T>
void Vector<T>::push_front(const T& elem) {
	if (vSize + 1 > maxSize) {
		alloc_new();
	}
	vSize++;

	T* tempArr = new T[vSize];
	tempArr[0] = elem;
	for (int i = 1; i < vSize; ++i) {
		tempArr[i] = A[i - 1];
	}

	delete[] A;
	A = tempArr;
}

template<class T>
void Vector<T>::resize(const size_t newSize) noexcept {
	if (newSize < vSize) {
		for (int i = newSize; i < vSize; ++i) {
			pop_back();
		}
	} else {
		maxSize = newSize * 2;
		T* tempArr = new T[maxSize];
		for (int i = 0; i < vSize; ++i) {
			tempArr[i] = A[i];
		}
		for (int i = vSize; i < newSize; ++i) {
			tempArr[i] = 0;
		}

		delete[] A;
		A = tempArr;
	}

	vSize = newSize;
}

template<class T>
void Vector<T>::insert(const unsigned position, const T& elem) {
	vSize++;
	maxSize++;
	T* tempArr = new T[maxSize];
	for (int i = 0; i < position; ++i) {
		tempArr[i] = A[i];
	}
	tempArr[position] = elem;
	for (int i = position + 1; i < vSize; ++i) {
		tempArr[i] = A[i - 1];
	}

	delete[] A;
	A = tempArr;

}

template<class T>
void Vector<T>::erase(const unsigned firstPosition, const unsigned secondPosition) {
	int difference = secondPosition - firstPosition;
	if (difference >= 0 && difference < vSize) {
		T* tempArr = new T[maxSize];
		unsigned i = 0;
		for (; i < firstPosition; ++i) {
			tempArr[i] = A[i];
		}
		for (; i < vSize - difference; ++i) {
			tempArr[i] = A[i + difference + 1];
		}
		vSize -= difference + 1;

		delete[] A;
		A = tempArr;
	} else {
		throw VectorException(ErrorsCodes::OUT_OF_RANGE);
	}
}

template<class T>
void Vector<T>::clear() {
	delete[] A;
	maxSize = 15;
	A = new T[maxSize];
	vSize = 0;
}