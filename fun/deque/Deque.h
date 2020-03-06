// Made by Bruce Cosgrove

#ifndef DEQUE_H
#define DEQUE_H

template<class T>
class Deque {
public:
	Deque();
	~Deque();
public:
	void pushFront(const T &data);
	T popFront();
	T peekFront();
	void printFront() const;
	void pushBack(const T &data);
	T popBack();
	T peekBack();
	void printBack() const;
private:
	struct Node {
		Node(const T &data = (T)0);
		Node(Node *prev, const T &data, Node *next);
		T data;
		Node *next, *prev;
	} *head, *tail;

	// Assumes node is not head, tail, nor nullptr
	void removeNode(Node *node);
};

template class Deque<int>;

#endif
