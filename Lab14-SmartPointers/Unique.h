#pragma once
#include"SmartPointer.h"

template<class T>
class Unique : public SmartPointer<T> {
	using SmartPointer<T>::ptr;
public:
	Unique() : SmartPointer<T>() {}
	Unique(T* p) : SmartPointer<T>(p) {
		std::cout << p << "Constructor unique" << std::endl;
	}
	Unique(const Unique<T>&) = delete;
	Unique(Unique<T>&& other) noexcept {
		ptr = other.ptr;
		other.ptr = nullptr;
	}

	~Unique() noexcept {
		std::cout << ptr << "Unique Destructor" << std::endl;
		delete ptr;
	}

	Unique<T>& operator = (const Unique<T>&) = delete;
};
