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

void queueInit(Queue* p);	//큐 초기화
int indexAdd(Queue* p);	//front와 rear의 인덱스 조정
void enQueue(Queue* p, int data);	//데이터 저장
int deQueue(Queue* p);	//데이터 반환 및 저장
void printQueue(Queue* p);	//큐에 모든 데이터 출력

#endif // !_QUEUE2_H_

