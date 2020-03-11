// Made by Bruce Cosgrove

#include "LinkedList.h"
#include <iostream>

// LinkedList
LinkedList::LinkedList() : head(new Node()) {}

LinkedList::~LinkedList() {
	deleteRec(head);
}

void LinkedList::deleteRec(Node *prev) {
	if (prev != nullptr) {
		Node *next = prev->next;
		delete prev;
		deleteRec(next);
	}
}

void LinkedList::pushFront(const double data) {
	insertRec(0, head, data);
}

void LinkedList::pushBack(const double data) {
	insertRec(getSize(), head, data);
}

void LinkedList::insert(const unsigned int index, const double data) {
	const unsigned int size = getSize(); // This is cached so the list is not iterated over an extra time
	insertRec(index < size ? index : size, head, data);
}

void LinkedList::insertRec(const unsigned int index, Node *node, const double data) {
	if (index != 0 && node->next != nullptr)
		insertRec(index - 1, node->next, data);
	else new Node(node, data);
}

double LinkedList::popFront() {
	return removeRec(0, head);
}

double LinkedList::popBack() {
	return removeRec(getSize() - 1, head);
}

double LinkedList::remove(const unsigned int index) {
	return index < getSize() ? removeRec(index, head) : popBack();
}

double LinkedList::removeRec(const unsigned int index, Node *node) {
	if (head->next == nullptr) {
		std::cout << "The list is empty :(\n";
		return 0.0;
	} // This line does not count towards the line count :p
	if (index != 0 && node->next != nullptr)
		return removeRec(index - 1, node->next);
	Node *toDelete = node->next;
	double data = toDelete->data;
	node->next = toDelete->next;
	delete toDelete;
	return data;
}

unsigned int LinkedList::getSize() const {
	return getSizeRec(head->next, 0);
}

unsigned int LinkedList::getSizeRec(Node *node, const unsigned int size) const {
	return node != nullptr ? getSizeRec(node->next, size + 1) : size;
}

void LinkedList::print() const {
	std::cout << "[ ";
	printRec(head->next);
	std::cout << "]\n";
}

void LinkedList::printRec(Node *node) const {
	if (node != nullptr) {
		std::cout << node->data << ' ';
		printRec(node->next);
	}
}

// LinkedList::Node
LinkedList::Node::Node(const double data, Node *next) : data(data), next(next) {}

LinkedList::Node::Node(Node *prev, const double data) : data(data), next(prev->next) {
	prev->next = this;
}
