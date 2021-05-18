#include <stdio.h>
#include <stdbool.h>

#ifndef _QUEUE2_H_
#define _QUEUE2_H_

#define MAX 5

typedef struct queue {
	int arr[MAX];
	int front;
	int rear;
}Queue;

void queueInit(Queue* p);	//ť �ʱ�ȭ
int indexAdd(Queue* p);	//front�� rear�� �ε��� ����
void enQueue(Queue* p, int data);	//������ ����
int deQueue(Queue* p);	//������ ��ȯ �� ����
void printQueue(Queue* p);	//ť�� ��� ������ ���

#endif // !_QUEUE2_H_

