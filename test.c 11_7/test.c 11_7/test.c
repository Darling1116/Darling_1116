#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu( )
{
	printf("*************************\n");
	printf("******    0. Exit  ******\n");
	printf("****** 1.Add 2.Sub ******\n");
	printf("****** 3.Mul 4.Div ******\n");
	printf("*************************\n");
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

//void Calc(int(*pfun) (int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("请输入两个数:>\n");
//	scanf("%d%d",&x,&y);
//	ret = pfun(x, y);
//	printf("%d ", ret);
//
//}
int main( )
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int(*pfun[5])(int, int) = { 0, Add, Sub, Mul, Div };
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个数:>\n");
			scanf("%d%d", &x, &y);
			ret = pfun[input](x, y);
			printf("%d ", ret);

		}
	} while (input);
		/*switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出");
			break;
		default :
			break;
		}
	} while (input);*/
	return 0;
}

//void Print(int(*arr)[3], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ",*(*(arr+i)+j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 7, 8, 9, 3 };
//	Print(arr, 3, 3);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret*i;
//		sum = sum + ret;
//	}
//	printf("%d ", sum);
//	system("pause");
//	return 0;
//}


//unsigned int  Reverse_bits(unsigned int value)
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < 32; i++)
//	{
//		//ret = ret + ((value >> i) & 1)*pow(2, 31 - i);
//		ret = ret << 1;
//		ret = ret | ((value >> i) & 1);
//	}
//	return ret;
//}
//int main( )
//{
//	unsigned int value = 0;
//	unsigned int sum = 0;
//	scanf("%d",&value);
//	sum = Reverse_bits(value);
//	printf("%u ", sum);
//	system("pause");
//	return 0;
//	
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	//printf("%d ", ((a + b) >> 1));
//	printf("%d ", ((a&b) + ((a^b) >> 1)));
//	system("pause");
//	return 0;
//}