#pragma once

template <class T>
class Adapter {
protected:
	virtual void push(const T& data) = 0;
	virtual void pop() = 0;
	virtual const T& top() const = 0;
};