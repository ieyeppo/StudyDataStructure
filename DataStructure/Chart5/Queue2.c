#include <stdio.h>
#include "Queue2.h"

void queueInit(Queue* p) {
	p->front = p->rear = 0;
}	//큐 초기화

int indexAdd(Queue* index) {
	if (index->rear == MAX - 1) {
		index->front % MAX + 1;
		return 0;
	}
						
	return index->rear % MAX +1;	//MAX가 안됬을 경우는 다음 배열로 한칸 이동

}	//front와 rear의 인덱스 조정


void enQueue(Queue* p, int data) {
	p->arr[p->rear % MAX] = data;
	p->rear = indexAdd(p);

}	//데이터 저장


int deQueue(Queue* p) {
	int index = p->front;
	p->front = p->front % MAX + 1;

	return p->arr[index];

}	//데이터 반환 및 저장


void printQueue(Queue* p) {
	for (int i = 0; i < MAX; i++)
			printf("arr[%d]=%d\n", i, p->arr[i]);
	printf("\n");
}//큐에 모든 데이터 출력