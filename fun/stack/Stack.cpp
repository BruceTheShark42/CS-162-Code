// Made by Bruce Cosgrove

#include "Stack.h"
#include <iostream>

// Stack<T>
template<class T>
Stack<T>::Stack() : top(new Node()), size(0) {}

template<class T>
Stack<T>::~Stack() {
	for (Node *node = top, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

template<class T>
void Stack<T>::push(const T &t) {
	++size;
	new Node(top, t);
}

// Seg-faults if size == 0
template<class T>
T Stack<T>::pop() {
	--size;
	Node *oldTop = top->next;
	top->next = oldTop->next;
	T data = oldTop->data;
	delete oldTop;
	return data;
}

// Seg-faults if size == 0
template<class T>
T Stack<T>::peek() { return top->next->data; }

template<class T>
unsigned int Stack<T>::getSize() { return size; }

template<class T>
void Stack<T>::print() {
	std::cout << '(' << size << ")=[ ";
	for (Node *node = top->next; node != nullptr; node = node->next)
		std::cout << node->data << ' ';
	std::cout << "]\n";
}

// Stack<T>::Node
template<class T>
Stack<T>::Node::Node(const T &data, Node *next) : data(data), next(next) {}

template<class T>
Stack<T>::Node::Node(Node *prev, const T &data) : data(data), next(prev->next) { prev->next = this; }
