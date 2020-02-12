// Made by Bruce Cosgrove

#include "LinkedList.h"

#include <iostream>

template<class T>
LinkedList<T>::LinkedList() : head(new Node()) {}

template<class T>
LinkedList<T>::~LinkedList() {
	for (Node *node = head, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

template<class T>
bool LinkedList<T>::insert(const unsigned int &index, const T &data) {
	Node *node = head;
	for (unsigned int i = 0; node && i < index; ++i, node = node->next) {}
	if (node) {
		insertNode(node, data);
		return true;
	}
	return false;
}

template<class T>
bool LinkedList<T>::remove(const unsigned int &index) {
	Node *node = head; // Made this head to make removeNode possible
	for (unsigned int i = 0; node && i < index; ++i, node = node->next) {}
	if (node) {
		removeNode(node);
		return true;
	}
	return false;
}

template<class T>
void LinkedList<T>::print() const {
	std::cout << "[ ";
	for (Node *node = head->next; node != nullptr; node = node->next) {
		std::cout << node->data << ' ';
	}
	std::cout << ']';
}

template<class T>
void LinkedList<T>::insertNode(Node *node, const T &data) {
	Node *dNode = new Node(data);
	dNode->next = node->next;
	node->next = dNode;
}

template<class T>
void LinkedList<T>::removeNode(Node *before) {
	Node *node = before->next;
	before->next = node->next;
	delete node;
}

template<class T>
LinkedList<T>::Node::Node(const T &data) : data(data), next(nullptr) {}
