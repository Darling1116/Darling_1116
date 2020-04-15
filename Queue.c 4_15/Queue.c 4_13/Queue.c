#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QUDataType;

typedef struct QueueNode{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue{
	struct QueueNode* _prev;
	struct QueueNode* _tail;
}Queue;

void QueueInit(Queue* que){
	assert(que);
	que->_prev = NULL;
}

void QueueDestroy(Queue* que){
	assert(que);
	QueueNode* cur = que->_prev;
	while (cur != NULL){
		QueueNode* tail = cur->_next;
		//这里不用释放结点，
		//而是采用移动que队列队头指针来实现删除一个结点的操作
		que->_prev = que->_prev->_next;
		cur = tail;
	}
	que->_prev = NULL;
}

QueueNode* BuyNode(QUDataType x){
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* que, QUDataType x){
	assert(que);
	QueueNode* newnode = BuyNode(x);
	if (que->_prev == NULL){
		que->_prev = que->_tail = newnode;
	}
	else{
		que->_tail->_next = newnode;
		que->_tail = que->_tail->_next;
	}
}


void QueuePop(Queue* que){
	assert(que);
	if (que->_prev == NULL){
		return;
	}
	if (que->_prev = que->_tail){
		que->_tail = NULL;
	}
	QueueNode* cur = que->_prev;
	que->_prev = que->_prev->_next;
	free(cur);
}

QUDataType QueueFront(Queue* que){
	assert(que);
	if (QueueEmpty(que)){
		return NULL;
	}
	return que->_prev->_data;

}


QUDataType QueueBack(Queue* que){
	return que->_tail->_data;
}

int QueueEmpty(Queue* que){
	if (que->_tail == NULL){
		return 1;
	}
	return 0;
}

int QueueSize(Queue* que){
	QueueNode* cur = que->_prev;
	int size = 0;
	while (cur != NULL){
		size++;
		cur = cur->_next;
	}
	return size;
}

typedef struct Mystack{
	Queue qu1;
	Queue qu2;
}Mystack;

Mystack* MystackCreat(int maxSize){
	Mystack* st = (Mystack*)malloc(sizeof(QueueNode)*maxSize);
	QueueInit(&st->qu1);
	QueueInit(&st->qu2);
}

void MystackPush(Mystack* st, int x){
	if (QueueEmpty(&st->qu1) == NULL){
		QueuePush(&st->qu2, x);
	}
	else{
		QueuePush(&st->qu1, x);
	}
}

int  MystackPop(Mystack* st){
	Queue* empty = &st->qu1;
	Queue* nonempty = &st->qu2;
	if (QueueEmpty(&st->qu2) == NULL){
		empty = &st->qu2;
		nonempty = &st->qu1;
	}
	while (QueueSize(&nonempty) > 1){
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int tmp = QueueFront(nonempty);
	QueuePop(nonempty);
	return tmp;
}

int  MystackTop(Mystack* st){
	Queue* empty = &st->qu1;
	Queue* nonempty = &st->qu2;
	if (QueueEmpty(&st->qu2) == NULL){
		empty = &st->qu2;
		nonempty = &st->qu1;
	}
	while (QueueSize(&nonempty) > 1){
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int tmp = QueueFront(nonempty);
	QueuePush(empty, tmp);
	QueuePop(nonempty);
	return tmp;
}

int  MystackEmpty(Mystack* st){
	if (QueueEmpty(&st->qu1) == 1 && QueueEmpty(&st->qu2) == 1){
		return 1;
	}
	else{
		return 0;
	}
}


void MystackFree(Mystack* st){
	free(st);
	st = NULL;
}


int main( ){
	Queue que;
	QueueInit(&que);
	//QueueDestroy(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 5);
	QueuePush(&que, 6);
	//QueuePop(&que);

	system("pause");
	return 0;
}