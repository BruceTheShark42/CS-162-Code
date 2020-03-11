// Made by Bruce Cosgrove

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void pushFront(const double data);
	void pushBack(const double data);
	void insert(const unsigned int index, const double data);
	double popFront();
	double popBack();
	double remove(const unsigned int index);
	unsigned int getSize() const;
	void print() const;
private:
	struct Node {
		Node(const double data = 0.0, Node *next = nullptr);
		Node(Node *prev, const double data = 0.0);
		double data;
		Node *next;
	};
	void deleteRec(Node *prev);
	void insertRec(const unsigned int index, Node *node, const double data);
	double removeRec(const unsigned int index, Node *node);
	unsigned int getSizeRec(Node *node, const unsigned int size) const;
	void printRec(Node *node) const;
	
	Node *head;
};
#endif
