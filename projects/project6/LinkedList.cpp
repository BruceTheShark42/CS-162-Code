// Made by Bruce Cosgrove

#include "LinkedList.h"
#include <iostream>

template<class T>
LinkedList<T>::LinkedList() : head(new Node()), size(0) {}

template<class T>
LinkedList<T>::~LinkedList() {
	for (Node *node = head, *next; node != nullptr; node = next) {
		next = node->next;
		delete node;
	}
}

template<class T>
void LinkedList<T>::insert(const unsigned int index, const T &data) {
	insertRec(index, head, data);
	++size;
}

// Inserts the 6 one index too far right
template<class T>
void LinkedList<T>::insertRec(const unsigned int index, Node *node, const T &data) {
	if (index - 1 < size && node->next != nullptr)
		insertRec(index + 1, node->next, data);
	else new Node(node, data);
}

template<class T>
T LinkedList<T>::remove(const unsigned int index) {
	removeRec(index, head);
	--size;
}

template<class T>
T LinkedList<T>::removeRec(const unsigned int index, Node *node) {
	if (index - 1 < size && node->next != nullptr) {
		return removeRec(index + 1, node->next);
	} else {
		Node *toDelete = node->next;
		T data = toDelete->data;
		node->next = toDelete->next;
		delete toDelete;
		return data;
	}
}

template<class T>
T& LinkedList<T>::operator[](const unsigned int index) { return subscriptOperatorRec(index, head); }

template<class T>
T& LinkedList<T>::subscriptOperatorRec(const unsigned int index, Node *node) { return index < size ? subscriptOperatorRec(index + 1, node->next) : node->data; }

template<class T>
unsigned int LinkedList<T>::getSize() const { return size; }

template<class T>
void LinkedList<T>::print() const {
	std::cout << '(' << size << ")=[ ";
	printRec(head->next);
	std::cout << "]\n";
}

template<class T>
void LinkedList<T>::printRec(Node *node) const {
	if (node != nullptr) {
		std::cout << node->data << ' ';
		printRec(node->next);
	}
}

// LinkedList<T>::Node
template<class T>
LinkedList<T>::Node::Node(const T &data, Node *next) : data(data), next(next) {}

template<class T>
LinkedList<T>::Node::Node(Node *prev, const T &data) : data(data), next(prev->next) { prev->next = this; }
