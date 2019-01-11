#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

void _MergeSort(int* a, int begin, int end,int* tmp)
{
	if (a == NULL || begin >= end)
		return;

	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	int begin1 = begin;
	int begin2 = mid + 1;
	int end1 = mid;
	int end2 = end;
	int index = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//index = 0;
	//while (index <= end)
	//{
	//	a[begin++] = tmp[index++];
	//}

	int i = 0;
	for (i = 0; i <index; i++)
	{
		a[begin+i] = tmp[i];
	}

}
void MergeSort(int* a, int n)
{
	int* tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n-1, tmp);
	free(tmp);
}

void Sort(int* a, int n)
{
	int i = 0;
	int min = a[0];
	int max = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;

	int* count = (int *)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);

	for (i = min; i <= max; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (i = 0; i < range; i++)
	{

		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}

void test()
{
	int n = 10;
	int a[10] = { 6, 8, 9, 4, 5, 6, 2, 1, 8, 0 };

	Sort(a, n);
	//MergeSort(a,n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}