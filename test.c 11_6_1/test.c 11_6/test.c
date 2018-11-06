#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。

int strlen(char*str)//计算字符串的长度
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;//字符串的长度加一，即，指向下一个字符
	}
	return count;
}

void Reverse_str(char* start, char* end)
{
	while (start < end)
	{
		int tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}




////一组数据中有一个数只出现了一次，其他的都是成对的出现。
////找出这个数字（使用位运算）
//int main()
//{
//	int i = 0;
//	int ret = 0;
//	int arr[] = { 1, 2, 3, 5, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof (arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		ret = ret^arr[i];
//		//对应为1的个数为奇数时，对应为结果为1；为偶数时，对应为肯定为0。
//	}
//	printf("%d ", ret);
//	system("pause");
//	return 0;
//}



//不使用(a+b)/2,求平均值
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	//printf("%d\n", ((a + b) >> 1));
//	//printf("%d\n", (a + ((b - a) >> 1)));
//	printf("%d\n", (a & b + ((a^b) >> 1)));
//	//a&b求两个数相同的部分；a^b求两个数不同的部分，除以2是保证不同的部分两个数平分
//	system("pause");
//	return 0;
//}

//实现二进制数序列的翻转：

//unsigned int Reserve_bits(unsigned int value)
//{
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum = sum + ((value >> i) & 1)*pow(2 ,32 - i);
//	}
//	return sum;
//}

//unsigned int Reserve_bits(unsigned int value)
//{
//	int i = 0;
//	unsigned int ret = 0;
//	for (i = 0; i < 32; i++)
//	{
//		ret = ret << 1;
//		ret = ret | ((value >> i) & 1);  //把一个数的每一位分别存到ret的最低位
//	}
//	return ret;
//}
//
//int main(  )
//{
//	unsigned int ret = 0;
//	unsigned int value = 0;
//	scanf("%d", &value);
//	ret = Reserve_bits(value);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abcdefg";
//	char *p1  = "abcdefg";
//	char *p2  = "abcdefg";
//	printf("%p\n", arr1);
//	printf("%p\n", arr2);//不同
//	//arr1,arr2是数组，可被修改
//	//"abcdefg"存在其中是存放在不同的空间里
//	printf("%p\n", p1);
//	printf("%p\n", p2);//相同
//	//p1,p2存的都是a的地址，不能被修
//	//"abcdefg"在其中属于常变量
//	//不能被修改
//	system("pause");
//	return 0;
//
//}
//
//打印一个二维数组：
//
//void Print(int(*arr)[5],int x, int y)//数组指针
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
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 6, 7, 9, 0, };
//	Print(arr, 3, 5);
//	system("pause");
//	return 0;
//}
//
//
//
//不同的方法实现计算器
//void menu( )
//{
//	printf("*************************\n");
//	printf("*******1.Add 2.Sub*******\n");
//	printf("*******3.Mul 4.Div*******\n");
//	printf("*******   0.exit  *******\n");
//	printf("*************************\n");
//}
//
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void Calc(int(*pfun)(int, int))
////利用函数指针来实现case语句的优化
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("请输入两个数:>\n");
//	scanf("%d%d", &x, &y);
//	ret = pfun(x, y);
//	printf("%d\n", ret);
//
//}
//
//int main( )
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default :
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	int(*pfun[5])(int, int) = {exit, Add, Sub, Mul, Div};//创建一个函数指针数组
//	do
//	{
//		menu();
//		printf("请选择:>\n");
//		scanf("%d", &input);
//		if (input >= 1 & input <= 4)
//		{
//			printf("请输入两个数:>\n");
//			scanf("%d%d", &x, &y);
//			ret = pfun[input](x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("退出\n");
//			break;
//		}
//
//	} while (input);
//	system("pause");
//	return 0;
//
//}



//int main( )
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个数:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个数:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个数:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Mul(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个数:>\n");
//			scanf("%d%d", &x, &y);
//			ret = Div(x, y);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default :
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}