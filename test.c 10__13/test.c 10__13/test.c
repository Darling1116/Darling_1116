#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12 };
	int key = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	scanf("%d", &key);

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid]>key)
		{
			right = mid - 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
		printf("ÕÒµ½À²\n");
	else
		printf("ÕÒ²»µ½\n");
	system("pause");
	return 0;
}
