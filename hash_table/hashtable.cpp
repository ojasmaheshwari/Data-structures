#include <iostream>

using namespace std;

template<typename T>
struct Node{
	T data;
	struct Node* next;
};

template<class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* node;
	int SIZE=0;
public:
	LinkedList(const T data) {
		Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>));
		node->data = data;
		this->head = node;
		this->SIZE = 1;
	}
	void insertAtEnd(const T data) {
		Node<T>* node = (Node<T>*) malloc(sizeof(Node<T>));
		node->data = data;
		if (this->SIZE == 1) {
			this->head->next = node;
			this->node = node;
		} else {
			this->node->next = node;
			this->node = node;
		}
		this->SIZE++;
	}
	void print() {
		Node<T>* curr_node = this->head;
		for (int i=0; i<this->SIZE; i++) {
			cout << curr_node->data << " -> ";
			curr_node = curr_node->next;
		}
		cout << "NULL\n";
	}

	int size() {
		return this->SIZE;
	}
};

template<class T>
class HashTable {
private:
	const int SIZE = 10;
	LinkedList<T>* arr;

public:
	HashTable() {
		this->arr = (LinkedList<T>*) malloc(sizeof(LinkedList<T>) * this->SIZE);
	}
	void insert(int key, T value) {
		// Hash algorithm is k mod n
		int hashKey = key % this->SIZE;
		LinkedList list(value);
		if (this->arr[hashKey].size() == 0)
			this->arr[hashKey] = list;
		else
			this->arr[hashKey].insertAtEnd(value);
	}
	void print() {
		for (int i=0; i<this->SIZE; i++) {
			this->arr[i].print();
		}
	}
	void search(int key) {
		int hashKey = key % this->SIZE;
		this->arr[hashKey].print();
	}
};

int main() {
	HashTable<string> table;
	table.insert(22, "ojas");
	table.insert(41, "lol");
	table.insert(22, "hehe");
	table.search(22);
	return 0;
}