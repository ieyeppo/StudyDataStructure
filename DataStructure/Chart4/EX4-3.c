#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Node;

typedef struct list {
	Node* head;
	Node* tail;
	int size;
}List;

void createList(List* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));
	list->head->link = list->tail;
	list->tail->link = list->tail;
	list->size = 0;
}

void addFirst(List* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = list->head->link;
	list->size++;
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
	list->size++;
}

void deleteList(List* list) {
	while (list->head != list->tail) {
		Node* delNode = list->head;
		list->head = delNode->link;
		free(delNode);
	}
	free(list->head);
	free(list->tail);
}

void printList(List* list) {
	Node* node = list->head->link;
	int i = 0;
	while (node != list->tail)
	{
		printf("%d번째 노드 : %d\n", i + 1, node->data);
		node = node->link;
	}
}

void main() {
	List list;
	createList(&list);

	for (int i = 0; i < 5; i++) {
		addLast(&list, i);
	}
	for (int i = 10; i < 15; i++) {
		addFirst(&list, i);
	}
	printList(&list);
}