#include <stdio.h>
#include "Queue2.h"

void main() {
	Queue queue;

	queueInit(&queue);		//ť �ʱ�ȭ
	enQueue(&queue, 10);	//������ ����
	enQueue(&queue, 20);	//������ ����
	enQueue(&queue, 30);	//������ ����
	enQueue(&queue, 40);	//������ ����
	enQueue(&queue, 50);	//������ ����
	enQueue(&queue, 60);	//������ ����
	printQueue(&queue);
	printf("\nfront : %d, rear : %d\n\n", queue.front, queue.rear);
	printf("deQueue : %d\n", deQueue(&queue));		//������ ��ȯ �� ����
	printQueue(&queue);	//ť�� ��� ������ ���
}