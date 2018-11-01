#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Difer_num(int arr[], int sz)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret^arr[i];
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 5, 3, 2, 1 };
	int sz = sizeof (arr) / sizeof (arr[0]);
	printf("%d ", Difer_num(arr, sz));
	return 0;
}