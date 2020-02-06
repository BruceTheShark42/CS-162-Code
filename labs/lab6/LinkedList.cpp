// Made by Bruce Cosgrove

#include "LinkedList.h"

#include <iostream>

template<class T>
LinkedList<T>::LinkedList() : head(new Node()), tail(new Node()) {
	head->next = tail;
	tail->prev = head;
}

template<class T>
LinkedList<T>::~LinkedList() {
	for (Node *node = head, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

template<class T>
bool LinkedList<T>::insert(const unsigned int &index, const T &data) {
	Node *node = head->next;
	for (unsigned int i = 0; node && i < index; ++i, node = node->next) {}
	if (node) {
		insertNode(node, data);
		return true;
	}
	return false;
}

template<class T>
bool LinkedList<T>::remove(const unsigned int &index) {
	Node *node = head->next;
	for (unsigned int i = 0; node != tail && i < index; ++i, node = node->next) {}
	if (node != tail) {
		removeNode(node);
		return true;
	}
	return false;
}

template<class T>
void LinkedList<T>::printForwards() const {
	std::cout << "[ ";
	for (Node *node = head->next; node != tail; node = node->next)
		std::cout << node->data << ' ';
	std::cout << "]\n";
}

template<class T>
void LinkedList<T>::printBackwards() const {
	std::cout << "[ ";
	for (Node *node = tail->prev; node != head; node = node->prev)
		std::cout << node->data << ' ';
	std::cout << "]\n";
}

template<class T>
void LinkedList<T>::insertNode(Node *node, const T &data) {
	// Let's denote the node: "dNode"
	Node *dNode = new Node(data);
	
	dNode->prev = node->prev;
	dNode->next = node;
	node->prev->next = dNode;
	node->prev = dNode;
}

template<class T>
void LinkedList<T>::removeNode(Node *node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
}

template<class T>
LinkedList<T>::Node::Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}

template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<int>;
template class LinkedList<long>;
