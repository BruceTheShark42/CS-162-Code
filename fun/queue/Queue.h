// Made by Bruce Cosgrove

#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue {
public:
	Queue();
	~Queue();
	void enqueue(const T &data);
	T dequeue();
	void print();
	unsigned int getSize();
private:
	struct Node {
		Node(const T &data = (T)0, Node *next = nullptr);
		Node(Node *prev, const T &data = (T)0);
		T data;
		Node *next;
	} *head;
	unsigned int size;
};

template class Queue<int>;

#endif
