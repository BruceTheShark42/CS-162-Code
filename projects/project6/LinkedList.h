// Made by Bruce Cosgrove

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void pushFront(const T &data);
	void pushBack(const T &data);
	void insert(unsigned int index, const T &data);
	T popFront();
	T popBack();
	T remove(unsigned int index);
	T& operator[](unsigned int index);
	unsigned int getSize() const;
	void print() const;
private:
	struct Node {
		Node(const T &data = (T)0, Node *next = nullptr);
		Node(Node *prev, const T &data = (T)0);
		T data;
		Node *next;
	};
	void deleteRec(Node *prev);
	void insertRec(unsigned int index, Node *node, const T &data);
	T removeRec(unsigned int index, Node *node);
	T& subscriptOperatorRec(unsigned int index, Node *node);
	void printRec(Node *node) const;
	
	Node *head;
	unsigned int size;
};

template class LinkedList<int>;

#endif
