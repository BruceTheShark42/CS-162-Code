// Made by Bruce Cosgrove

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
public:
	bool insert(const unsigned int &index, const T &data);
	bool remove(const unsigned int &index);
	void printForwards() const;
	void printBackwards() const;
private:
	struct Node {
		Node(const T &data = (T)0);
		
		T data;
		Node *next;
		Node *prev;
	} *head, *tail;
	
	void insertNode(Node *node, const T &data);
	void removeNode(Node *node);
};

#endif
