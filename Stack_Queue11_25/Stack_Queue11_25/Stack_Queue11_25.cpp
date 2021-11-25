#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;


//栈的顺序存储
typedef struct Stack{
	int *array;
	int maxsize;
	int top;
}Stack;

void StackInit(Stack *st){
	st->array = (int *)malloc(sizeof(int)* 10);
	st->maxsize = 10;
	st->top = -1;
}

int StackFull(Stack *st){
	if (st->top == st->maxsize - 1)
		return 1;
	else
		return 0;
}

void StackPush(Stack *st, int x){ //进栈
	if (st->top == st->maxsize - 1)
		return;
	else
		st->array[++st->top] = x;
}
int StackEmpty(Stack *st){
	if (st->top == -1)
		return 1;
	else
		return 0;
}

void StackPop(Stack *st){ //出栈
	if (st->top > -1)
		st->top--;
	else
		return;
}

int StackTop(Stack *st){ //取栈顶元素
	assert(st);
	return st->array[st->top];
}

void StackPrint(Stack *st){
	int x;
	while (StackEmpty(st) != 1){
		printf("%d ", StackTop(st));
		StackPop(st);
	}
	printf("\n");
}


typedef struct MyQueue{
	Stack s1;
	Stack s2;
}MyQueue;

void MyQueueInit(MyQueue *mq){
	StackInit(&mq->s1);
	StackInit(&mq->s2);
}

int MyQueueEmpty(MyQueue *mq){
	if (StackEmpty(&mq->s1) && StackEmpty(&mq->s2)){
		return 1;
	}
	else{
		return 0;
	}
}

void MyQueuePush(MyQueue *mq, int x){
	if (mq->s1.top == mq->s1.maxsize){
		if (!StackEmpty(&mq->s2)) //s1满，s2非空
			return;
		else{  //s1满，s2空
			int y;
			while (!StackEmpty(&mq->s1)){
				y = StackTop(&mq->s1);
				StackPop(&mq->s1);
				StackPush(&mq->s2, y);
			}
			StackPush(&mq->s1, x);
		}
	}
	else{
		StackPush(&mq->s1, x); //s1不满，元素直接压入栈s1
	}
}


int MyQueueFront(MyQueue *mq){
	int y;
	if (!StackEmpty(&mq->s2)){ //s2非空，直接取栈顶元素
		y = StackTop(&mq->s2);
		StackPop(&mq->s2);
		return y;
	}
	else{
		if (StackEmpty(&mq->s1))
			return NULL;
		else{
			while (!StackEmpty(&mq->s1)){
				y = StackTop(&mq->s1);
				StackPop(&mq->s1);
				StackPush(&mq->s2, y);
			}
			y = StackTop(&mq->s2);
			StackPop(&mq->s2);
			return y;
		}
	}

}

void MyQueuePrint(MyQueue *mq){
	while (!MyQueueEmpty(mq)){
		printf("%d ", MyQueueFront(mq));
	}
	printf("\n");
}



int main(){
	//用栈实现队列
	MyQueue mq;
	MyQueueInit(&mq);
	MyQueuePush(&mq, 1);
	MyQueuePush(&mq, 2);
	MyQueuePush(&mq, 3);
	MyQueuePush(&mq, 4);
	MyQueuePush(&mq, 5);
	MyQueuePrint(&mq);

	system("pause");
	return 0;
}