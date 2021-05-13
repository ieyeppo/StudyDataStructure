#include <stdio.h>

typedef struct node {
	int data;			//data ���
	struct node* link;	//���� ����� �ּҸ� ������ ���
}Node;

void main()
{
	Node *head = malloc(sizeof(Node));		//������ ����
	Node* node1 = malloc(sizeof(Node));		//��� ����
	Node* node2 = malloc(sizeof(Node));

	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;		//�����忡 ù��° ����� �ּҰ��� �ִ´�.

	node2->data = 1;
	node2->link = NULL;

	if (head->link == NULL) {
		head->link = node2;
	}
	else {
		node2->link = head->link;
		head->link = node2;
	}

	Node* curr = head->link;
	int i = 0;

	while (curr != NULL) {
		printf("%d��° ��� ������ : %d\n", i , curr->data);
		curr = curr->link;
		i++;
	}

	free(node1);
	free(head);
}