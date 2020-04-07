#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

typedef struct ListNode{
	struct ListNode* _next;
	int _data;
}ListNode;

typedef struct Stack{
	ListNode* top;
}Stack;

Stack* myStackCreate() {
	Stack* st = calloc(1, sizeof(Stack));
	return st;
}

void myStackPush(Stack* obj, int x){
	assert(obj);
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = obj->top;
	obj->top = node;
}

int myStackPop(Stack* obj) {
	assert(obj);
	ListNode* node = obj->top;
	obj->top = node->_next;
	int pop = node->_data;
	free(node);
	return pop;
}

int myStackTop(Stack* obj){
	assert(obj);
	return obj->top->_data;
}

int myStackEmpty(Stack* obj){
	assert(obj);
	if (obj->top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void myStackFree(Stack* obj){
	assert(obj);
	while (obj->top != NULL){
		ListNode* node = obj->top;
		obj->top = obj->top->_next;
		free(node);
	}
}

int main(){
	Stack* st;
	myStackPush(&st, 1);
	myStackPush(&st, 1);
	myStackPush(&st, 1);
	//myStackFree(&st);
	myStackPop(&st);

	system("pause");
	return 0;
}

