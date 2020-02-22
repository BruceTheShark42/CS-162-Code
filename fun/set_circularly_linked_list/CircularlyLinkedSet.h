// Made by Bruce Cosgrove

#ifndef CIRCULARLY_LINKED_SET
#define CIRCULARLY_LINKED_SET

template<class T>
class CircularlyLinkedSet {
public:
	CircularlyLinkedSet();
	~CircularlyLinkedSet();
	bool add(const T &data);
	bool remove(const T& data);
	unsigned int size() const;
	void print(bool printSize = false) const;
private:
	struct Node {
		Node(const T &data = (T)0, Node *next = nullptr);
		Node(Node *prev, const T &data);
		T data;
		Node *next;
	};
	mutable Node *head;
};

template class CircularlyLinkedSet<int>;

#endif
