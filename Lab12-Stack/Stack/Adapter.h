#pragma once

template <class T>
class Adapter {
protected:
	size_t size;

public:
	size_t getSize() {
		return size;
	}
	virtual bool empty() const {
		return size == 0;
	}
	virtual void push(const T& data) = 0;
	virtual void pop() = 0;
	virtual const T& top() const = 0;
};