#include <stdio.h>
#include <stdbool.h>

typedef struct qnode {
	int data;
	int front, rear;
}Qnode;

//typedef struct qp {
//	Qnode* front;
//	Qnode* rear;
//}Qp;

void init(Qnode* pq) {
	pq->data = 0;
	pq->front = 0;
	pq->rear = 0;
}

int isEmpty(Qnode* pq) {
	if(pq->front)
}