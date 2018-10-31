#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main( )
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2 && a != 3) || (b != 2 && a == 3))
							&& ((b == 2 && e != 4) || (b != 2 && e == 4))
							&& ((c == 1 && d != 2) || (c != 1 && d == 2))
							&& ((c == 5 && d != 3) || (c != 5 && d == 3))
							&& ((e == 4 && a != 1) || (e != 4 && a == 1)))
						{
							if ((a != b && a != c && a != d && a != e && b != c && b!=d && b != e && c != d &&c != e && d != e))
							{

								printf("A=%d ,B=%d ,C=%d ,D=%d ,E=%d \n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}


//#define N 9
//int main()
//{
//	int i = 0;
//	int j = 0;
//	char arr[N][N] = { 0 };
//	for (i = 0; i < N; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//
//	for (i = 2; i <= N; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//
//		}
//
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int killer = '0';
//	for (killer == 'A'; killer <= 'D';killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("%c ", killer);
//		}
//	}
//	return 0;
//}
