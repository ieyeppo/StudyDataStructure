#include <stdio.h>

typedef struct node {
	int data;			//data 멤버
	struct node* link;	//다음 노드의 주소를 저장할 멤버
}Node;

void main()
{
	Node *head = malloc(sizeof(Node));		//헤더노드 생성
	Node* node1 = malloc(sizeof(Node));		//노드 생성
	Node* node2 = malloc(sizeof(Node));

	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;		//헤더노드에 첫번째 노드의 주소값을 넣는다.

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
		printf("%d번째 노드 데이터 : %d\n", i , curr->data);
		curr = curr->link;
		i++;
	}

	free(node1);
	free(head);
}