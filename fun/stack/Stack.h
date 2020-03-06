// Made by Bruce Cosgrove

#ifndef STACK_H
#define STACK_H

template<class T>
class Stack {
public:
	Stack();
	~Stack();
public:
	void push(const T &t);
	T pop();
	T peek();
	void print();
	unsigned int getSize();
private:
	struct Node {
		Node(const T &data = (T)0, Node *next = nullptr);
		Node(Node *prev, const T &data = (T)0);
		T data;
		Node *next;
	} *top;
	unsigned int size;
};

template class Stack<int>;

#endif
