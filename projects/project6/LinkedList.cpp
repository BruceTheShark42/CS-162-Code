// Made by Bruce Cosgrove

#include "LinkedList.h"
#include <iostream>

template<class T>
LinkedList<T>::LinkedList() : head(new Node()), size(0) {}

template<class T>
LinkedList<T>::~LinkedList() {
	deleteRec(head);
}

template<class T>
void LinkedList<T>::deleteRec(Node *prev) {
	if (prev != nullptr) {
		Node *next = prev->next;
		delete prev;
		deleteRec(next);
	}
}

template<class T>
void LinkedList<T>::pushFront(const T &data) {
	insertRec(0, head, data);
	++size;
}

template<class T>
void LinkedList<T>::pushBack(const T &data) {
	++size;
	insertRec(size - 1, head, data);
}

template<class T>
void LinkedList<T>::insert(unsigned int index, const T &data) {
	if (index < size) {
		insertRec(index, head, data);
		++size;
	} else pushBack(data);
}

// Inserts the 6 one index too far right
template<class T>
void LinkedList<T>::insertRec(unsigned int index, Node *node, const T &data) {
	if (index != 0 && index < size && node->next != nullptr)
		insertRec(index + 1, node->next, data);
	else new Node(node, data);
}

template<class T>
T LinkedList<T>::popFront() {
	--size;
	return removeRec(0, head);
}

template<class T>
T LinkedList<T>::popBack() {
	T data = removeRec(size - 1, head);
	--size;
	return data;
}

template<class T>
T LinkedList<T>::remove(unsigned int index) {
	if (index < size) {
		T data = removeRec(index - 1, head);
		--size;
		return data;
	} else return popBack();
}

template<class T>
T LinkedList<T>::removeRec(unsigned int index, Node *node) {
	if (index < size && index != 0 && node->next != nullptr) {
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
T& LinkedList<T>::operator[](unsigned int index) { return subscriptOperatorRec(index, head->next); }

template<class T>
T& LinkedList<T>::subscriptOperatorRec(unsigned int index, Node *node) {
	return index > 0 ? subscriptOperatorRec(index - 1, node->next) : node->data;
}

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
