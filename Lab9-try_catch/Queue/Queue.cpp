#pragma once
#include "Queue.h"
#include "QueueException.cpp"

template<class T>
constexpr void Queue<T>::push(const T value) {
	Node<T>* newNode = new Node<T>(value);
	if (size != 0) {
		Node<T>* current = pHead;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = newNode;
		
		pTail = newNode;
	} else {
		pHead = newNode;
		pTail = newNode;
	}

	size++;
}

template<class T>
constexpr void Queue<T>::pop() {
	if (!Queue<T>::isEmpty()) {
		Node<T>* temp = pHead;

		if (pTail != pHead) {
			pHead = pHead->pNext;
		} else {
			pHead = pTail = nullptr;
		}
		size--;

		delete temp;
	} else {
		throw QueueException("Queue is empty", QueueException::QUEUE_IS_EMPTY);
	}
}

template<class T>
constexpr void Queue<T>::clear() {
	while (size > 0) {
		Queue<T>::pop();
	}
}

template<class T>
Queue<T>::Queue() {
	size = 0;
	pHead = nullptr;
	pTail = nullptr;
}

template<class T>
Queue<T>::~Queue() {
	Queue<T>::clear();
}

template<class T>
constexpr T Queue<T>::front() {
	if (!Queue<T>::isEmpty()) {
		return pHead->data;
	} else {
		throw QueueException("Queue is empty", QueueException::QUEUE_IS_EMPTY);
	}
}

template<class T>
constexpr T Queue<T>::back() {
	if (!Queue<T>::isEmpty()) {
		return pTail->data;
	} else {
		throw QueueException("Queue is empty", QueueException::QUEUE_IS_EMPTY);
	}
}

template<class T>
constexpr size_t Queue<T>::getSize() {
	return size;
}

template<class T>
constexpr bool Queue<T>::isEmpty() {
	return size == 0;
}

