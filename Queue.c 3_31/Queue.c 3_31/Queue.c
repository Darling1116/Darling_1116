#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//重定义常量
#define Capacity 10

typedef int QUDataType;

//数组表实现环形队列

typedef struct Queue{
	QUDataType* _a;
	//默认环形列表的大小已经确定
	QUDataType*	_front;
	QUDataType* _rear;
	//指向数组的指针
	size_t _size;
}Queue;


void QueueInit(Queue* que){
	assert(que);
	que->_a = (QUDataType*)malloc(Capacity*sizeof(QUDataType));
	assert(que->_a);
	que->_front = que->_a;
	que->_rear = que->_a;
	que->_size = 0;
}

void QueueDestory(Queue* que){
	assert(que);
	free(que->_a);
	que->_front = NULL;
	que->_rear = NULL;
	que->_size = 0;
}

//que->_front代表数组首元素的地址
void QueuePush(Queue* que, QUDataType x){
	assert(que);
	//开10个空间，里面只放9个元素，最后一个空的，用来判断队列是否为满
	if (que->_rear + 1 != que->_front + 10 ){
		*(que->_rear)= x;
		que->_rear++;
		que->_size++;
	}
	else{
		printf("队列已满\n");
		return -1;
	}
}

//注意队列是先进先出
void QueuePop(Queue* que){
	assert(que->_a);
	if (que->_rear == que->_front){
		printf("队列中无元素，不可删\n");
		return -1;
	}
	que->_front++;
	que->_size--;
	//当头指针在最后一个空的元素时（即，队尾）
	//应该让头指针重新指向队列的开始
	if (que->_front == que->_a + Capacity){
		que->_front = que->_a;
	}
}

int QueueFront(Queue* que){
	assert(que);
	return *(que->_front);
}

//_rear每次插入过后，指向的是下一个位置的地址
//所以，最后一个元素应该是rear的上一个指向元素
int QueueRear(Queue* que){
	assert(que);
	return *(que->_rear-1);
}

size_t QueueIsEmpty(Queue* que){
	assert(que);
	if (que->_front == que->_rear){
		return 1;
	}
	else{
		return 0;
	}
}


size_t QueueSize(Queue* que){
	assert(que);
	return que->_size;
}

void QueuePrint(Queue* que){
	assert(que);
	QUDataType* cur = que->_front;
	while (cur!=que->_rear){
		printf("%d->", *cur);
		cur++;
	}
	printf("\n");
	//_rear每次插入过后，指向的是下一个位置的地址
//	printf("%d\n", *(que->_rear));
}


int main( ){
	Queue* que;
	QueueInit(&que);
	//QueueDestory(&que);
	
	QueuePush(&que, 2);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);
	QueuePush(&que, 1);

	//QueuePush(&que, 1);
	
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que); 
	QueuePush(&que, 3);
	QueuePush(&que, 3);
	QueuePrint(&que);

	int front = QueueFront(&que);
	printf("%d\n", front);
	int rear = QueueRear(&que);
	printf("%d\n", rear);

	system("pause");
	return 0;
}

