#define _CRT_SECURE_NO_WARNINGS

#include "seqlist.h"

SeqList ps;
void SeqListInit(SeqList *ps, size_t capacity)
{
	assert(ps);
	ps->_array = (SLDataType *)malloc(capacity *sizeof (SLDataType));
	ps->_size = 0;
	ps->_capacity = capacity;
}

void SeqListPrint(SeqList *ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
void SeqListDestory(SeqList *ps)
{
	assert(ps);
	if(ps->_array)//
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_size = 0;
		ps->_capacity = 0;
	}
}
void  CheckCapacity(SeqList *ps)
{
	assert(ps);
    ps->_capacity*=2;
	//size_t capacity = 0;
	if (ps->_size == ps->_capacity)
	{
		ps->_capacity *=2;
		ps->_array = (SLDataType *)realloc(ps->_array, (ps->_capacity)*sizeof(SLDataType));
		assert(ps->_array);//
	}

}

void SeqListpushback(SeqList *ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}

void SeqListpopback(SeqList *ps)
{
	assert(ps&&ps->_size>0);
	ps->_array[ps->_size - 1] = 0;
	ps->_size--;
}

void SeqListpushfront(SeqList *ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	size_t end = ps->_size;
	while (end > 0)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[0] = x;
	ps->_size++;
}

void SeqListpopfront(SeqList *ps)
{
	assert(ps&&ps->_size > 0);
	size_t begin = 1;
	while (begin <ps->_size )
	{
		ps->_array[begin - 1] = ps->_array[begin];
		++begin;
	}
	ps->_size--;
}


void SeqListInsert(SeqList *ps, size_t pos, SLDataType x)
{
	assert(ps&&pos<=ps->_size);
	CheckCapacity(ps);
	int  end = ps->_size;
	
	while (end>(int)pos)
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList *ps, size_t pos)
{
	assert(ps&&ps->_size > 0);
	size_t begin = pos+1;
	while (begin<=ps->_size)
	{
		ps->_array[begin - 1] = ps->_array[begin];
		++begin;
	}
	ps->_size--;
}

void SeqListBubbleSort(SeqList *ps)
{
	assert(ps);
	size_t begin = 1;
	while (begin<ps->_size)
	{
		if (ps->_array[begin - 1] > ps->_array[begin])
		{
			SLDataType tmp = ps->_array[begin - 1];
			ps->_array[begin - 1] = ps->_array[begin];
			ps->_array[begin] = tmp;
		}
		++begin;
	}
}

int  SeqListBinaryFind(SeqList *ps, SLDataType x)
{
	assert(ps&&ps->_size>0);
	size_t begin = 0;
	size_t end = ps->_size - 1;
	
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		if (ps->_array[mid] == x)
		{
			return mid;
		}
		else if (ps->_array[mid] > x)
		{
		   end = mid - 1;
		}
		else
		{
			begin = mid + 1;
		}
	}
}


void test()
{
	SeqListInit(&ps,8);
	SeqListpushback(&ps, 1);
	SeqListpushback(&ps, 2);
	SeqListpushback(&ps, 2);
	SeqListpushback(&ps, 2);
	SeqListpushback(&ps, 6);
	SeqListpushback(&ps, 2);
	SeqListpushback(&ps, 8);
	SeqListpushback(&ps, 9);

	SeqListpopback(&ps);

	SeqListpushfront(&ps, 3);
    SeqListpopfront(&ps);

	SeqListInsert(&ps,2,8);
	SeqListErase(&ps, 1);

	SeqListBubbleSort(&ps);

	printf ("%d\n",SeqListBinaryFind(&ps, 6));


	SeqListPrint(&ps);
	SeqListDestory(&ps);
	
}


















