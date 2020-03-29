#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QUDataType;

//用链表实现队列，要有队头和队尾
typedef struct QueueNode{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue{
	 QueueNode* _front;
	 QueueNode* _rear;
}Queue;


void QueueInit(Queue* pq){
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}

void QueueDestory(Queue* pq){
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur){
		QueueNode* tnode = cur->_next;
		free(cur);
		cur = tnode;
	}
	pq->_front = NULL;
	pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x){
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QUDataType));
	assert(newnode);
	newnode->_next = NULL;
	newnode->_data = x;
	return newnode;
}

void QueuePush(Queue* pq,QUDataType x){
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	assert(newnode);
	if (pq->_rear == NULL){
		pq->_front = newnode;
		pq->_rear = newnode;
		//当队列中只有一个结点时，front,rear都指向该结点
	}
	else{
		QueueNode* tail = pq->_rear;
		tail->_next = newnode;
		pq->_rear = newnode;
	}
}

void QueuePop(Queue* pq){
	assert(pq);
	QueueNode* tnode = pq->_front;
	pq->_front = tnode->_next;
	free(tnode);
	tnode = NULL;
	
}

QUDataType QueueFront(Queue* pq){
	assert(pq);
	if (pq->_front == NULL){
		return NULL;
	}
	return pq->_front->_data;
}

QueueNode* QueueBack(Queue* pq){
	assert(pq);
	if (pq->_rear == NULL){
		return NULL;
	}
	return pq->_rear;
}

int QueueEmpty(Queue* pq){
	assert(pq);
	if (pq->_front == NULL){
		return 1;
	}
	return 0;
}

int QueueSize(Queue* pq){
	assert(pq);
	QueueNode* cur = pq->_front;
	int size = 0;
	while (cur){
		++size;
		cur = cur->_next;
	}
	return size;
}


void QueuePrint(Queue* pq){
	assert(pq);
	QueueNode* cur = pq->_front;
	printf("队头<-");
	while (cur){
		printf("%d<-", cur->_data);
		cur = cur->_next;
	}
	printf("队尾\n");
}

int main(){
	Queue* que1;
	QueueInit(&que1);
	//QueueDestory(&que1);
	QueuePush(&que1, 2);
	QueuePush(&que1, 3);
	QueuePush(&que1, 4);
	QueuePush(&que1, 5);
	QueuePush(&que1, 6);
	
	//QueuePop(&que1);
	QueuePrint(&que1);

	int front = QueueFront(&que1);
	printf("%d\n", front);

	//QueueNode* rear = QueueBack(&que1);
	//printf("%f\n", rear->_data);

	printf("%d\n", QueueEmpty(&que1));
	printf("%d\n", QueueSize(&que1));
	system("pause");
	return 0;
}