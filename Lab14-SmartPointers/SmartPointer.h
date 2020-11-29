#pragma once

template<class T>
class SmartPointer {
public:
	SmartPointer() : ptr(new T{T()}) {
	}

	SmartPointer(T* p) : ptr(p) {
		std::cout << p << " Constructor SmartPointer" << std::endl;
	}

	T& operator*() const {
		return *ptr;
	}
	T* operator->() const {
		return ptr;
	}

	friend std::ostream& operator << (std::ostream& out, const SmartPointer& otherSmart) {
		out << otherSmart.ptr;
		return out;
	}

	virtual void swap(SmartPointer<T>& right) noexcept {
		if (this != &right) {
			/*T thisValue = *ptr;
			*ptr = *right.ptr;
			*right.ptr = thisValue;*/
			std::swap(this->ptr, right.ptr);
		}
	}

protected:
	T* ptr;
};
