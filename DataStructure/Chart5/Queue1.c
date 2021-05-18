#include <stdio.h>
#include <stdbool.h>

#define MAX 6

int isEmpty();
int isFull();
void enQueue(int);	//q�� ����
int deQueue();		//q���� ����

int rear = 0;		//�Ա�
int front = 0;		//�ⱸ
int queue[MAX];

void main() {
	enQueue(10);
	enQueue(20);
	enQueue(30);
	printf("%d\n", queue[rear]);
}

int isEmpty()
{
	if (rear == front) return true;
	else return false;
}

int isFull()
{
	if (front == (rear + 1) % MAX) return true;
	else return false;
}

void enQueue(int data)
{
	if (isFull()) {
		printf("Queue Overflow!!\n");
		return;
	}
	rear = rear % MAX;
	queue[rear] = data;
	rear++;
}

int deQueue()
{
	if (isEmpty()) {
		printf("Queue Empty!!\n");
		return;
	}
	return queue[front++ % MAX];
}
