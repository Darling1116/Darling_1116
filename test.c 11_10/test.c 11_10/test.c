#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

杨氏矩阵：数组的每一行从左到右递增
          数组的每一列从上到下递增
在该数组中查找一个数字.(返回该数字的坐标）
如 1  3  5
   2  4  7
   4  5  9

1)从右上角开始寻找
int Rearch(int arr[3][3], int row, int col, int k, int *px, int *py)
{
	int i = 0;
	int j = col - 1;
	while (i < row&&j >= 0)
	{
		if (arr[i][j] == k)
		{
			*px = i;
			*py = j;
			return 1;
		}
		else if (arr[i][j]>k)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}
从左下角开始寻找（递归的方法）
int Rearch_r(int arr[3][3], int row, int col, int k, int x,int y,int *px_r, int *py_r)
{
	//x,y在函数中存在，不需要重定义
	if (x < 0 || y >= col)
	{
		*px_r = -1;
		*py_r = -1;
		return 0;
	}
	if (arr[x][y] == k)
	{
		*px_r = x;
		*py_r = y;
		return 1;
	}
	else if (arr[x][y]>k)
	{
		Rearch_r(arr, 3, 3, k, x - 1, y, px_r, py_r);
	}
	else if (arr[x][y]<k)
	{
		Rearch_r(arr, 3, 3, k, x, y + 1, px_r, py_r);
	}
}

int main( )
{
	
	/*int px=0;
	int py=0;*/
	int px_r = 0;
	int py_r = 0;
	int arr[3][3] = { 1, 2, 5, 2, 4, 7, 4, 5, 9 };
	//Rearch(arr,3,3,7,&px,&py);
	//printf("%d %d\n", px, py);

	Rearch_r(arr, 3, 3, 7, 2, 0, &px_r, &py_r);
	printf("%d %d\n", px_r, py_r);
	system("pause");
	return 0;
}




实现一组数中，奇数在前，偶数在后
int main()
{
	int i = 0;
	int j = 6;
	int arr[7] = { 3, 6, 1, 9, 3, 5, 0 };
	while (i < j)
	{
		while (i < j && (arr[i] % 2 != 0))
		{
			i++;
		}
		while (i < j && (arr[j] % 2 != 1))
		{
			j--;
		}
		if (i < j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	for (i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);

	}
	printf("\n");
	system("pause");
	return 0;
}
