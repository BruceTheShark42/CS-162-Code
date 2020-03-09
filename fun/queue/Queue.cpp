// Made by Bruce Cosgrove

#include "Queue.h"
#include <iostream>

template<class T>
Queue<T>::Queue() : head(new Node()), size(0) {}

template<class T>
Queue<T>::~Queue() {
	for (Node *node = head, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

template<class T>
void Queue<T>::enqueue(const T &data) {
	++size;
	Node *node = head;
	while (node->next != nullptr)
		node = node->next;
	new Node(node, data);
}

template<class T>
T Queue<T>::dequeue() {
	--size;
	Node *toDelete = head->next;
	head->next = toDelete->next;
	T data = toDelete->data;
	delete toDelete;
	return data;
}

template<class T>
void Queue<T>::print() {
	std::cout << '(' << size << ")=[ ";
	for (Node *node = head->next; node != nullptr; node = node->next)
		std::cout << node->data << ' ';
	std::cout << "]\n";
}

template<class T>
unsigned int Queue<T>::getSize() { return size; }

template<class T>
Queue<T>::Node::Node(const T &data, Node *next) : data(data), next(next) {}

template<class T>
Queue<T>::Node::Node(Node *prev, const T &data) : data(data), next(prev->next) { prev->next = this; }
