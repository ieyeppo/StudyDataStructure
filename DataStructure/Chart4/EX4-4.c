#include <stdio.h>

typedef struct node {
	int data;
	struct node* link;
}Node;

typedef struct list {
	Node* head;
	Node* tail;
}List;

void createList(List* list)
{
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));
	list->head->link = list->tail;
	list->tail->link = list->tail;
}

void addFirst(List* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = list->head->link;
	list->head->link = newNode;
}

void addLast(List* list, int data) {
	Node* last = list->head;

	while (last->link != list->tail) {
		last = last->link;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = list->tail;
	last->link = newNode;

}

void printList(List* list) {
	Node* node = list->head->link;
	int i = 0;
	while (node != list->tail) {
		printf("NodeData : %d\n", node->data);
		node = node->link;
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

void main() {
	List* list;
	
	createList(&list);

	for (int i = 0; i < 5; i++)
	{
		addLast(&list, i);
	}

	printList(&list);
}