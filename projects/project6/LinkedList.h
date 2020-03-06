// Made by Bruce Cosgrove

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void insert(const unsigned int index, const T &data);
	T remove(const unsigned int index);
	T& operator[](const unsigned int index);
	unsigned int getSize() const;
	void print() const;
private:
	struct Node {
		Node(const T &data = (T)0, Node *next = nullptr);
		Node(Node *prev, const T &data = (T)0);
		T data;
		Node *next;
	};
	void insertRec(const unsigned int index, Node *node, const T &data);
	T removeRec(const unsigned int index, Node *node);
	T& subscriptOperatorRec(const unsigned int index, Node *node);
	void printRec(Node *node) const;
	
	Node *head;
	unsigned int size;
};

template class LinkedList<int>;

#endif
