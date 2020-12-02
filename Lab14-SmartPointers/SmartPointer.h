#pragma once

template<class T>
class SmartPointer {
public:
	T* get() const noexcept {
		return ptr;
	}

	virtual void release() noexcept = 0;

	virtual void reset() noexcept = 0;

	virtual void reset(T* right) noexcept = 0;

	T& operator*() const noexcept {
		return *ptr;
	}

	T* operator->() const noexcept {
		return ptr;
	}

	friend std::ostream& operator << (std::ostream& out, const SmartPointer& otherSmart) {
		out << otherSmart.ptr;
		return out;
	}

protected:
	T* ptr;
};
