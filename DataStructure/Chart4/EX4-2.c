#include <stdio.h>

typedef struct node {
	int data;
	Node* link;
}Node;

void addNode(Node* target, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;
	target->link = newNode;
	//target->data++;
}

void main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;

	/* ������� �Լ� ȣ�� */
	addNode(head, 1);
	printf("%d\n", head);
}