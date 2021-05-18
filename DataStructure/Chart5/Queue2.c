#include <stdio.h>
#include "Queue2.h"

void queueInit(Queue* p) {
	p->front = p->rear = 0;
}	//ť �ʱ�ȭ

int indexAdd(Queue* index) {
	if (index->rear == MAX - 1) {
		index->front % MAX + 1;
		return 0;
	}
						
	return index->rear % MAX +1;	//MAX�� �ȉ��� ���� ���� �迭�� ��ĭ �̵�

}	//front�� rear�� �ε��� ����


void enQueue(Queue* p, int data) {
	p->arr[p->rear % MAX] = data;
	p->rear = indexAdd(p);

}	//������ ����


int deQueue(Queue* p) {
	int index = p->front;
	p->front = p->front % MAX + 1;

	return p->arr[index];

}	//������ ��ȯ �� ����


void printQueue(Queue* p) {
	for (int i = 0; i < MAX; i++)
			printf("arr[%d]=%d\n", i, p->arr[i]);
	printf("\n");
}//ť�� ��� ������ ���