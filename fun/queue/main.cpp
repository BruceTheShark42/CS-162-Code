// Made by Bruce Cosgrove

#include "Queue.h"

int main() {
	Queue<int> q;
	q.print();
	q.enqueue(6);
	q.print();
	q.enqueue(2);
	q.print();
	q.enqueue(7);
	q.print();
	q.dequeue();
	q.print();
	q.dequeue();
	q.print();
	q.enqueue(9);
	q.print();
	return 0;
}
