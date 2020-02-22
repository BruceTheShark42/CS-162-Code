// Made by Bruce Cosgrove

#include "CircularlyLinkedSet.h"

#include <iostream>

template<class T>
CircularlyLinkedSet<T>::CircularlyLinkedSet() : head(nullptr) {}

template<class T>
CircularlyLinkedSet<T>::~CircularlyLinkedSet() {
	if (head != nullptr) {
		const Node *const start = head;
		for (Node *node = head->next, *next; node != start; node = next) {
			next = node->next;
			delete node;
		}
		delete head;
	}
}

template<class T>
bool CircularlyLinkedSet<T>::add(const T &data) {
	if (head == nullptr) {
		head = new Node(data);
		head->next = head;
	} else {
		const Node *const start = head;
		do {
			if (head->data == data)
				return false;
			head = head->next;
		} while (head != start);
		new Node(head, data);
	}
	return true;
}

template<class T>
bool CircularlyLinkedSet<T>::remove(const T& data) {
	// switch (head)
	if (head == nullptr) return false;
	if (head == head->next && head->data == data) {
		delete head;
		head = nullptr;
		return true;
	}
	const Node *const start = head;
	do {
		if (head->next->data == data) {
			Node *newNext = head->next->next;
			delete head->next;
			head->next = newNext;
			return true;
		}
		head = head->next;
	} while (head != start);
	return false;
}

template<class T>
unsigned int CircularlyLinkedSet<T>::size() const {
	if (head == nullptr) return 0;
	unsigned int size = 0;
	const Node *const start = head;
	do {
		++size;
		head = head->next;
	} while (head != start);
	return size;
}

template<class T>
void CircularlyLinkedSet<T>::print(bool printSize) const {
	std::cout << "[ ";
	unsigned int size = 0;
	if (head != nullptr) {
		Node *start = head;
		do {
			++size;
			std::cout << head->data << ' ';
			head = head->next;
		} while (head != start);
	}
	std::cout << ']';
	if (printSize)
		std::cout << " - " << size;
	std::cout << '\n';
}

template<class T>
CircularlyLinkedSet<T>::Node::Node(const T &data, Node *next) : data(data), next(next) {}

template<class T>
CircularlyLinkedSet<T>::Node::Node(Node *prev, const T &data) : data(data), next(prev->next) { prev->next = this; }
