// Made by Bruce Cosgrove

#include <iostream>
using namespace std;

double sumLoop(double* ptr, size_t size) {
	double sum = 0.0;
	for (size_t i = 0; i < size; ++i)
		sum += ptr[i];
	return sum;
}

double sumRec(double* ptr, size_t size) {
    if (size == 0) return 0.0;
	return ptr[0] + sumRec(ptr + 1, size - 1);
}

class LinkedList {
    public:
        LinkedList() : head(new Node()) {}
        ~LinkedList() {
			destructorRec(head);
        }
        void printList() {
			cout << "{ ";
			printListRec(head->next);
			cout << "}\n";
        }
        void pushFront(double newData) {
			new Node(head, newData);
        }
        void pushBack(double newData) {
			new Node(findEnd(head), newData);
        }
        double popFront() {
			Node *toDelete = head->next;
			head->next = toDelete->next;
			double data = toDelete->data;
			delete toDelete;
            return data;
        }
        int getLength() {
			return getLengthRec(head->next);
        }
    private:
        struct Node {
			// These constructors make it easier to make nodes
			Node(double data = 0.0, Node *next = nullptr) : data(data), next(next) {}
			Node(Node *prev, double data = 0.0) : data(data), next(prev->next) { prev->next = this; }
            double data;
            Node *next;
        };
        Node *head;

        // Private helper functions
		void destructorRec(Node *node) {
			if (node != nullptr) {
				destructorRec(node->next);
				delete node;
			}
		}
		// This was printHelper
        void printListRec(Node *node) {
			if (node != nullptr) {
				cout << node->data << ' ';
				printListRec(node->next);
			}
        }
		// This was countNodes
        int getLengthRec(Node *node) {
			if (node == nullptr) return 0;
			return 1 + getLengthRec(node->next);
        }
        Node* findEnd(Node *node) {
			if (node->next == nullptr) return node;
			return findEnd(node->next);
        }
};

int main() {
    double array[] = { 3.4, -5.6, 1.2, -3.5 };
    int size = 4;
    cout << "Testing sumLoop ****************\n";
    cout << "\t Expecting -4.5, got " << sumLoop(array, size) << endl;
    cout << "Testing sumRec  ****************\n";
    cout << "\t Expecting -4.5, got " << sumRec(array, size) << endl;

    cout << "\n\nTesting LinkedList  ****************\n";
    LinkedList list;
    for (double i = -8.4; i < 8.0; i += 3.3) {
        list.pushFront(i);
    }
    cout << "\tTesting pushFront, printList, getLength\n";
    cout << "\tprintList: Expecting { 4.8 1.5 -1.8 -5.1 -8.4 } and got ";
    list.printList();
    cout << endl;
    cout << "\tgetLength: Expecting 5 and got " << list.getLength() << endl;

    cout << "\n\tTesting pushBack\n";
    list.pushBack(3.4);
    cout << "\tprintList: Expecting { 4.8 1.5 -1.8 -5.1 -8.4 3.4 } and got ";
    list.printList();
    cout << endl;
    cout << "\tgetLength: Expecting 6 and got " << list.getLength() << endl;

    cout << "\n\tTesting popFront\n";
    double poppedValue = list.popFront();
    cout << "\tExpected 4.8 and got " << poppedValue << endl;
    list.printList();
    cout << endl;

    return 0;
}
