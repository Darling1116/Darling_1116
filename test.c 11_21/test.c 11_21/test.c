#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void menu()
{
	printf("***********************\n");
	printf("******   0.exit  ******\n");
	printf("******1.Add 2.Sub******\n");
	printf("******3.Mul 4.Div******\n"); 
	printf("***********************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
//	int ret = 0;
	int(*pfun[5])(int, int) = { 0, Add, Sub, Mul, Div };//函数指针数组，一定要加上数组的大小
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个数:>\n");
			scanf("%d%d", &x, &y);
			//ret = pfun[input](x, y);//使用函数指针数组时，下标一定要补齐完整
			printf("%d ", pfun[input](x, y));
		}
		else
		{
			printf("选择错误，退出\n");
		}

	} while (input);
	return 0;
}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int(*p)(int, int) = &Add;//函数指针，函数中传参，传的是地址
//	printf("%d ", p(1, 2));
//	system("pause");
//	return 0;
//}

//void Print(int(*arr)[5], int x, int y)
////*arr为数组指针，每一行存放5个元素，类型为int形。
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 15, 16, 17, 18 };
//	Print(&arr, 3, 5);//函数中变量传参，传的是地址
//	system("pause");
//	return 0;
//}