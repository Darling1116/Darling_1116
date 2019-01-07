#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

Stack ps;

//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top; // Õ»¶¥
//	int _capacity; // ÈÝÁ¿
//}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
	
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);//
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity==0?8:2 * (ps->_capacity);//
		ps->_a= (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		assert(ps->_a != NULL);
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x;
	++(ps->_top);

}

void StackPop(Stack* ps)
{
	assert(ps&&ps->_top > 0);

	--(ps->_top);
}


STDataType StackTop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	return  ps->_a[ps->_top-1];

}
	
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

void TestStack( )
{
	StackInit(&ps);

	StackPush(&ps, 1);
	
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackEmpty(&ps);

	while (StackEmpty(&ps) != 0)
	{
		printf("%d ", StackTop(&ps));
		StackPop(&ps);
	}

}


