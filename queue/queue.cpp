// Queue data structure implementation, by Ojas Maheshwari

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string>

template<class T>
class Queue {
private:
	long long MAX_SIZE;
	int curr_size;
	T* arr;
	int q_start;
public:
	Queue(int size) {
		this->MAX_SIZE = size;	
		this->arr = (T*) malloc(sizeof(T)*size);
		this->curr_size = 0;
		this->q_start = 0;
	}
	~Queue() {
		free(this->arr);
	}
	void enqueue(T value) {
		if (this->curr_size < this->MAX_SIZE) {
			this->arr[this->curr_size] = value;
			this->curr_size++;
		} else {
			throw std::overflow_error("Tried to  into an already full queue.");
		}
	}
	void dequeue() {	
		if (this->curr_size > 0) {
			this->q_start++;
			this->curr_size--;
		} else {
			throw std::underflow_error("Tried to pop an already empty queue.");
		}
	}
	T peek() {
		if (!this->empty()) {
			return this->arr[this->q_start];
		}
		else {
			throw std::out_of_range("Attempt to access top() on an already empty queue.");
		}
	}
	bool empty() {
		if (this->curr_size == 0) return true;
		else return false;
	}
};

int main() {
	Queue<std::string> my_queue(3);
	my_queue.enqueue("ojas");
	my_queue.enqueue("akash");
	my_queue.enqueue("prabhdeep");
	std::cout << my_queue.peek() << '\n';
	return 0;
}
