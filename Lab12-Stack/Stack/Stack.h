#pragma once
#include "Adapter.h"
#include "StackException.h"

template <class T>
class Stack : public Adapter<T> {
private:
	template<class T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(const T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* pHead;
	size_t size;

public:
	Stack() noexcept {
		size = 0;
		pHead = nullptr;
	}
	Stack(const Stack<T>&) = delete;

	~Stack() noexcept {
		clear();
	}
	void push(const T& data) override;
	void pop() override;
	const T& top() const override;
	void clear();

	constexpr bool empty() const noexcept {
		return size == 0;
	}
	constexpr size_t getSize() const noexcept {
		return size;
	}
};

template<class T>
void Stack<T>::push(const T& data) {
	pHead = new Node<T>(data, pHead);
	size++;
}

template<class T>
void Stack<T>::pop() {
	if (size > 0) {
		Node<T>* temp = pHead;
		pHead = pHead->pNext;
		delete temp;
		size--;
	} else {
		throw StackException(StackException::ErrorsCodes::CONTAINER_IS_EMPTY);
	}
}

template<class T>
const T& Stack<T>::top() const {
	if (size > 0) {
		return pHead->data;
	} else {
		throw StackException(StackException::ErrorsCodes::CONTAINER_IS_EMPTY);
	}
}

template<class T>
void Stack<T>::clear() {
	while (size > 0) {
		pop();
	}
}