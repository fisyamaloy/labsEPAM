#pragma once
#include "Adapter.h"
#include "StackException.h"

template <class T>
class Stack : public Adapter<T>, public StackException {
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

public:
	Stack() {
		Adapter<T>::size = 0;
		pHead = nullptr;
	}
	~Stack() {
		clear();
	}
	void push(const T& data) override;
	void pop() override;
	const T& top() const override;
	void clear();
};


template<class T>
void Stack<T>::push(const T& data) {
	pHead = new Node<T>(data, pHead);
	Adapter<T>::size++;
}

template<class T>
void Stack<T>::pop() {
	if (Adapter<T>::size > 0) {
		Node<T>* temp = pHead;
		pHead = pHead->pNext;
		delete temp;
		Adapter<T>::size--;
	} else {
		throw StackException(ErrorsCodes::CONTAINER_IS_EMPTY);
	}
}

template<class T>
const T& Stack<T>::top() const {
	if (Adapter<T>::size > 0) {
		return pHead->data;
	} else {
		throw StackException(ErrorsCodes::CONTAINER_IS_EMPTY);
	}
}

template<class T>
void Stack<T>::clear() {
	while (Adapter<T>::size > 0) {
		pop();
	}
}