#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node	*next;
}LList;

void printList(LList *n) {
	while(n != NULL) {
		printf("%d ", n->data);
		n = n->next;
	}
}

int main() {
	LList* head = NULL;
	LList* second = NULL;
	LList* third = NULL;

	head = (LList*) malloc(sizeof(LList));
	second = (LList*) malloc(sizeof(LList));
	third = (LList*) malloc(sizeof(LList));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printList(head);
	return 0;
}
