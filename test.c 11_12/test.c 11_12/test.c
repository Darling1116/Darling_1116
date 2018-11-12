#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// µœ÷strlen

int my_strlen(const char *str)
{
	int count = 0;
	assert(*str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char str = "abcdefg";
	int ret=my_strlen(str);
	printf("%d ", ret);
	system("pause");
	return 0;

}


//1 2 3
//3 5 6
//6 8 9

//int rearch(int  a[3][3], int row, int col, int k, int *px, int *py)
//{
//	int i = 0;
//	int j = col - 1;
//	while (i<row && j>=0)
//	{
//		if (a[i][j] == k)
//		{
//			*px = i;
//			*py = j;
//			return 1;
//		}
//
//		else if (a[i][j] > k)
//		{
//			j--;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;
//}
//
//int main()
//{
//	int px=0;
//	int py=0;
//	int  a[3][3] = { 1, 2, 3, 3, 5, 6, 6, 8, 9 };
//	rearch(a, 3, 3, 8, &px, &py);
//	printf("%d %d\n", px, py);
//	system("puase");
//	return 0;
//}




//int main( )
//{
//	int a[7] = { 2, 6, 8, 1, 7, 9, 3 };
//	int i = 0;
//	int sz = sizeof (a) / sizeof (a[0]);
//	int j = sz - 1;
//	while (i < j)
//	{
//		while (i < j && (a[i] % 2 != 0))
//		{
//			i++;
//		}
//		while (i < j && (a[j] % 2 != 1))
//		{
//			j--;
//		}
//		if (i < j)
//		{
//			int tmp = a[i];
//			a[i] = a[j];
//			a[j] = tmp;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
