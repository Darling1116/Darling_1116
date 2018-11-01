#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main( )
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	printf("%d ", (b + ((a - b)>>1)));
	return 0;
}


//unsigned int reserve_bit(unsigned int value)
//{
//	unsigned sum = 0;
//	int n = 0;
//	unsigned int result = 0;
//	while (value)
//	{
//		result = value % 2;
//		sum = sum + (result << (31 - n));
//		value = value / 2;
//		n++;
//	}
//	return sum;
//}
//
//int main()
//{
//	int value = 0;
//	int ret = 0;
//	scanf("%d", &value);
//	ret = reserve_bit(value);
//	printf("%d ", ret);
//	return 0;
//
//}


//int main()
//{
//	int a, b, c, d, e;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2 && a != 3) || (b != 2 && a == 3)) && ((b == 2 && e != 4) || (b != 2 && e == 4))
//							&& ((c == 1 && d != 2) || (c != 1 && d == 2)) && ((c == 5 && d != 3) || (c != 5 && d == 3))
//							&& ((e == 4 && a != 1) || (e != 4 && a == 1)))
//						{
//							if (a != b && a != c && a != d && a != e && b != c && b != d && b != e && c != d && c != e && d != e)
//							{
//								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}


//
//#define N 9
//int main()
//{
//	int i = 0;
//	int j = 0;
//	char arr[N][N] = { 0 };
//	for (i = 0; i < N; i++)
//	{
//		arr[i][0] = 1;
//		for (j = 0; j <= i; j++)
//		{
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//		}
//	}
//
//	for (i = 2; i < N; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j < 3*(N - i) / 2; j++)  //控制其三角形的形状，3倍调整宽度。
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}