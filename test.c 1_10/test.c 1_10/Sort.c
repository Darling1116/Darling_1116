#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
void Swap(int *x, int *y)//两个数的交换，传的是地址，
//在函数内部对其进行实现的时候，要解引用.
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//双指针法
int PastSort1(int* a, int left, int right)
{
	int key = a[left];//为了保存下king的值
	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (a[end]>key && begin<end)
		{
			end--;
		}
		while (a[begin] <= key && begin<end)//要从第一个数开始寻找比key大的数
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[end], &a[left]);//不能写成Swap(&a[end],key)，key存的只是临时的数值。
	return end;
}

int PartSort2(int* a, int left, int right)//(挖坑法)
{
	int key = a[left];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		if (a[end]>key && begin<end)
		{
			end--;
		}
		
		a[begin] = a[end];
		
		if (a[begin] <= key && begin<end)
		{
			begin++;
		}
		
		a[end] = a[begin];
		
	}
	a[end] = key;
	return end;
}

int PartSort3(int* a, int left, int right)//(左右指针法)
{ 
	/*int mid = GetMiddle(a, left, right);
	int key = a[mid];*/
	int key = a[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	//Swap(&a[prev], &a[mid]);//交换时，如果传递址，要传实参。
	Swap(&a[prev], &a[left]);
	return prev;
}

int GetMiddle(int*a, int left, int right)//(三数取中法:取中间值元素的下标)
{
	int mid = left + ((right - left) >> 1);
	if (a[left] >= a[right])
	{
		if (a[mid] < a[right])
		{
			return right;
		}
		else if (a[mid]>a[right])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
	if (a[left] < a[right])
	{
		if (a[mid] < a[left])
		{
			return left;
		}
		else if (a[mid]>a[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//int div = PastSort1(a, left,right);
	//int div = PartSort2(a, left, right);
	int div = PartSort3(a, left, right);
	//if (div - 1 > left){
	//按道理不用判断也可以，因为div本来就是在left和right中间找的。

		QuickSort(a, left, div - 1);
	
	//if (div + 1 < right){
		QuickSort(a, div + 1, right);

}

void test()
{
	int n = 10;
	int a[10] = { 5,9,7,2,4,1,0,4,6,8};
	//int a[10] = { 0 };
	//srand(time(0));
	//int i = 0;
	//for (i = 0; i < n; i++)
	//{
	//	a[i] = rand();
	//}
	QuickSort(a, 0, n - 1);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	//int x = 2;
	//int y = 3;
	//Swap(&x, &y);
	//printf("%d%d ", x,y);
}