//打印乘法口诀表：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print_table(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%2d*%2d=%2d", i, j, i*j);
		printf("\n");
	}
}
int main()
{
	int line = 0;
	scanf("%d", &line);
	print_table(line);
	return 0;
}

//两个数的交换：
void Change_num(int x, int y)
{
	int z = 0;
	y = x;
	z = y;
	x = z;
	printf("x=%d,y=%d\n", x, y);
}
int main()
{
	int x = 0;
	int y = 0;
	scanf("%d%d", &x, &y);
	printf("x=%d,y=%d\n", x, y);
	Change_num(x, y);
	return 0;
}

//判断是否为闰年：
int Leap_year(int year)
{

	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		printf("%d是闰年\n", year);
	}
	else
		printf("%d不是闰年\n", year);
}
int main()
{
	int date = 0;
	scanf("%d", &date);
	Leap_year(date);
	return 0;
}

//实现函数初始化：
int Init(int arr[], int sz, int set)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = set;
		printf("%d ", arr[i]);
	}

}
int main()
{
	int sz = 0;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	sz = sizeof (arr) / sizeof (arr[0]);
	Init(arr, sz, 6);
	return 0;
}

//清空数组：
#include <stdlib.h>
void Empty(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}

}
int main()
{
	int sz = 0;
	int set = 0;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	sz = sizeof (arr) / sizeof (arr[0]);
	Empty(arr, sz);
	system("pause");
	return 0;
}
//实现逆序：
void Reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = 0;
		tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
		left++;
		right--;
	}
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

}
int main()
{
	int sz = 0;
	int set = 0;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	sz = sizeof (arr) / sizeof (arr[0]);
	Reverse(arr, sz);
	return 0;
}

//判断素数：
void Prime_num(int n)
{
	int j = 2;
	for (j = 2; j < n; j++)
	{
		if (n % j == 0)
		{
			printf("%d不是素数\n", n);
			break;
		}

	}
	if (j >= n)
		printf("%d是素数\n", n);
}

int main()
{
	int i = 0;
	scanf("%d", &i);
	Prime_num(i);
	return 0;
}
