#include <stdio.h>
#include "Queue2.h"

void main() {
	Queue queue;

	queueInit(&queue);		//큐 초기화
	enQueue(&queue, 10);	//데이터 저장
	enQueue(&queue, 20);	//데이터 저장
	enQueue(&queue, 30);	//데이터 저장
	enQueue(&queue, 40);	//데이터 저장
	enQueue(&queue, 50);	//데이터 저장
	enQueue(&queue, 60);	//데이터 저장
	printQueue(&queue);
	printf("\nfront : %d, rear : %d\n\n", queue.front, queue.rear);
	printf("deQueue : %d\n", deQueue(&queue));		//데이터 반환 및 저장
	printQueue(&queue);	//큐에 모든 데이터 출력
}