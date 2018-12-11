#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void HeapInit(Heap *hp, HPDataType *a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	memcpy(hp->_array, a, n*sizeof(HPDataType));

	int i = hp->_size-1;
	for (i = (i-1)/2; i >= 0; i--)
	{
		Adjustdown(hp->_array, hp->_size, i);
		//调的是结构体函数内部的数据。
	}

}

void Adjustdown(HPDataType *a, size_t n, int root)
//调的是数组之间的数据关系。
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			HPDataType *tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Adjustup(HPDataType *a, size_t n,int child)
{
	assert(a);
	//int child = n - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			HPDataType *tmp = a[child];
			a[child] = a[parent];
			a[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//void Heappush(Heap *hp, HPDataType *a, HPDataType x)
//{
//	assert(hp && a);
//	if (hp->_size == hp->_capacity)
//	{
//		hp->_array = realloc(hp->_array, a, (hp->_size-1)*sizeof(HPDataType));
//	}
//	assert(hp->_array);
//
//	hp->_array[hp->_size] = x;
//	hp->_size++;
//	
//	Adjustup(a, hp->_size, hp->_size - 1);
//}
void HeapPrint(Heap *hp)
{
	assert(hp);
	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void HeapDestory(Heap *hp)
{
	assert(hp);
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
}
void test()
{
	int a[] = { 2, 3, 6, 9, 5, 1, 0, 7 };
	HeapInit(&hp, a, sizeof(a) / sizeof(size_t));
	Heappush(&hp, a, 16);

	HeapPrint(&hp);
	HeapDestory(&hp);

}