#pragma once
#include "SmartPointer.h"

template<class T>
class Shared : public SmartPointer<T> {
	using SmartPointer<T>::ptr;
	size_t referencesCount;
public:
	explicit Shared() noexcept : ptr(new T{}) {
		std::cout << "Default constructor shared" << std::endl;
		referencesCount = 1;
	}

	explicit Shared(T* p) noexcept {
		ptr = p;
		referencesCount = 1;
		std::cout << "Constructor shared" << std::endl;
	}

	Shared(const Shared<T>& other) noexcept {
		ptr = other.ptr;
		this->referencesCount = other.referencesCount + 1;
		std::cout << "COPY Constructor shared" << std::endl;
	}

	~Shared() noexcept {
		if (referencesCount != 1) {
			referencesCount--;
			std::cout << "referencesCount--" << std::endl;
		} else {
			std::cout << "Destructor shared" << std::endl;
			delete ptr;
			ptr = nullptr;
			referencesCount = 0;
		}
	}

	Shared<T>& operator = (const Shared<T>& other) {
		std::cout << "Operator = " << std::endl;
		if (this != &other) {
			referencesCount++;
			return other;
		}

		return *this;
	}

	void use_count() const {
		return referencesCount;
	}

	void unique() const {
		return referencesCount == 1;
	}
	
	void release() noexcept override {
		this->ptr = nullptr;
		this->referencesCount = 0;
	}

	void reset() noexcept override {
		delete this->ptr;
		this->ptr = new T();
		this->referencesCount = 0;
	}

	void reset(T* right) noexcept override {
		delete this->ptr;
		this->ptr = right;
		this->referencesCount = 1;
	}
	
	void swap(Shared<T>& right) noexcept {
		if (this != &right) {
			std::swap(this->ptr, right.ptr);
			std::swap(this->referencesCount, right.referencesCount);
		}
	}
};

