#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void linkedListTraversal(Node* node) {
	while (node != NULL) {
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

void insert(Node* head, int pos, int val) {
	Node* p = head;
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = val;

	if (pos == 0) {
		node->next = head;
		*head = *node;
		linkedListTraversal(head);
	}
	else {
		for (int i=0; i<pos-1; i++) {
			p = p->next;
		}
		Node* temp = p->next;
		p->next = node;
		node->next = temp;
	}
}

void freeLinkedList(Node* head) {
	while (head != NULL) {
		free(head);
		head = head->next;
	}
}

int main(int argc, char** argv) {
	Node* head = (Node*) malloc(sizeof(Node));
	Node* second = (Node*) malloc(sizeof(Node));

	head->data = 2;
	head->next = second;

	second->data = 3;
	second->next = NULL;

	insert(head, 0, -1);

	linkedListTraversal(head);
	return 0;
}
