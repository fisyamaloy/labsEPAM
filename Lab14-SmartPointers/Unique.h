#pragma once
#include"SmartPointer.h"

template<class T>
class Unique : public SmartPointer<T> {
	using SmartPointer<T>::ptr;
public:
	explicit Unique() noexcept : ptr(new T{}) {
		std::cout << "Default constructor unique" << std::endl;
	}

	explicit Unique(T* p) noexcept {
		ptr = p ;
		std::cout << "Constructor unique" << std::endl;
	}	

	Unique(const Unique<T>&) = delete;
	
	Unique<T>& operator = (const Unique<T>&) = delete;

	Unique(Unique<T>&& other) noexcept {
		std::cout << "Constructor RVALUE unique" << std::endl;
		ptr = other.ptr;
		other.ptr = nullptr;
	}

	void swap(Unique<T>& right) noexcept {
		if (this != &right) {
			std::swap(this->ptr, right.ptr);
		}
	}
	
	void release() noexcept {
		ptr = nullptr;
	}

	void reset() noexcept override {
		delete this->ptr;
		this->ptr = new T();
	}

	void reset(T* right) noexcept override {
		delete this->ptr;
		this->ptr = right;
	}

	~Unique() noexcept {
		std::cout << "Unique destructor" << std::endl;
		delete ptr;
		ptr = nullptr;
	}
};
