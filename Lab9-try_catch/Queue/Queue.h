#pragma once

template <class T>
class Queue {

private:
	template<class T>
	struct Node {
		Node* pNext;
		T data;

		Node(const T data, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* pHead;
	Node<T>* pTail;
	size_t size;

public:
	Queue();
	~Queue();

	constexpr void push(const T value);
	constexpr void pop();
	constexpr void clear();
	constexpr T front();
	constexpr T back();
	constexpr size_t getSize();
	constexpr bool isEmpty();
};
