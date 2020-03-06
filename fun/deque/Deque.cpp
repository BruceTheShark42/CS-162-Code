// Made by Bruce Cosgrove

#include <iostream>

#include "Deque.h"

template<class T>
Deque<T>::Deque() : head(new Node()), tail(new Node()) {
	head->next = tail;
	tail->prev = head;
}

template<class T>
Deque<T>::~Deque() {
	for (Node *node = head, *next; node; node = next) {
		next = node->next;
		delete node;
	}
}

template<class T>
void Deque<T>::pushFront(const T &data) {
	new Node(head, data, head->next);
}

template<class T>
T Deque<T>::popFront() {
	T data = head->next->data;
	if (head->next != tail)
		removeNode(head->next);
	return data;
}

template<class T>
T Deque<T>::peekFront() {
	return head->next->data;
}

template<class T>
void Deque<T>::printFront() const {
	std::cout << "[ ";
	for (Node *node = head->next; node != tail; node = node->next)
		std::cout << node->data << ' ';
	std::cout << ']';
}

template<class T>
void Deque<T>::pushBack(const T &data) {
	new Node(tail->prev, data, tail);
}

template<class T>
T Deque<T>::popBack() {
	T data = tail->prev->data;
	if (tail->prev != head)
		removeNode(tail->prev);
	return data;
}

template<class T>
T Deque<T>::peekBack() {
	return tail->prev->data;
}

template<class T>
void Deque<T>::printBack() const {
	std::cout << "[ ";
	for (Node *node = tail->prev; node != head; node = node->prev)
		std::cout << node->data << ' ';
	std::cout << ']';
}

template<class T>
Deque<T>::Node::Node(const T &data) : prev(nullptr), data(data), next(nullptr) {}

template<class T>
Deque<T>::Node::Node(Node *prev, const T &data, Node *next) : prev(prev), data(data), next(next) {
	prev->next = this;
	next->prev = this;
}

template<class T>
void Deque<T>::removeNode(Node *node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
}
