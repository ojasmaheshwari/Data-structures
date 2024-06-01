#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
	int MAX_SIZE;
	int curr_size;
	int* arr;
} stack;

stack createStack(int max_size) {
	int* arr = (int*) malloc(sizeof(int) * max_size);
	stack st;
	st.curr_size = 0;
	st.arr = arr;
	st.MAX_SIZE = max_size;
	return st;
}

int peek(stack* st) {
	return st->arr[st->curr_size-1];
}

void push(stack* st, int val) {
	st->arr[st->curr_size] = val;
	st->curr_size++;
}

void printStack(stack* st) {
	for (int i=0; i<st->curr_size; i++) {
		printf("%d\n", st->arr[(st->curr_size) - 1 - i]);
	}
}

int pop(stack* st) {
	int pop_elem = peek(st);
	st->arr[st->curr_size - 1] = 0;
	st->curr_size--;
	return pop_elem;
}

bool isEmpty(stack* st) {
	return (st->curr_size == 0) ? true : false;
}

bool isFull(stack* st) {
	return (st->curr_size == st->MAX_SIZE) ? true : false;
}

int main() {
	stack st = createStack(3);
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);

	printStack(&st);

	if (isFull(&st))
		printf("Stack is full\n");
	else
		printf("Stack is not full\n");

	free(st.arr);
	return 0;
}
