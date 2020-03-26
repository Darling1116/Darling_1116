#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
//支持动态增长的栈
typedef struct Stack{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;


void StackInit(Stack* ps){
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps){
	assert(ps);
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x){
	assert(ps);
	if (ps->_top == ps->_capacity){
		if (ps->_capacity == 0){
			ps->_capacity = 10;
		}
		else{
			int newcapacity = 2 * ps->_capacity;
			ps->_capacity = newcapacity;
		}
		//realloc:追加空间
		ps->_a = (STDataType*)realloc(ps->_a,sizeof(STDataType)*ps->_capacity);
	}
	ps->_a[ps->_top++] = x;
}

void StackPop(Stack* ps){
	assert(ps);
	//要保证栈里有元素
	if (ps->_top > 0){
		ps->_top--;
	}
}

STDataType StackTop(Stack* ps){
	assert(ps);
	return ps->_a[ps->_top-1];
}

int StackEmpty(Stack* ps){
	assert(ps);
	if (ps->_top == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int StackSize(Stack* ps){
	assert(ps);
	return ps->_top;
}


void StackPrint(Stack* ps){
	assert(ps);
	//非空
	while (StackEmpty(ps) != 1){
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}

int main(){
	Stack st;
	StackInit(&st);
	//StackDestory(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPop(&st);

	int i = StackSize(&st);
	printf("Size=%d\n", i);

	StackPrint(&st);
	system("pause");
	return 0;
}