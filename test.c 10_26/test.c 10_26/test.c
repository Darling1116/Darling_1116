#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//两个int 位整数m和n的二进制表达中，有多少个bit位不同：
int Difer_bits(int m,int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((m >> i & 1) != (n >> i & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int ret=Difer_bits(13, 24);
	printf("%d", ret);
	return 0;
}




//分别打印一个数的二进制中的偶数位和奇数位：
//void even_bits(int value)
//{
//	int i = 0;
//	for (i = 31; i > 0; i = i - 2)
//	{
//		printf("%d ", value >> i & 1);
//	}
//}
//void odd_bits(int value)
//{
//	int i = 0;
//	for (i = 30; i >= 0; i = i - 2)
//	{
//		printf("%d ", value >> i & 1);
//	}
//}
//int main()
//{
//	int n = 13;
//	even_bits(n);
//	printf("\n");
//	odd_bits(n);
//	return 0;
//
//}


//输出一个整数二进制中一的个数：
//int count_one_bits(int value)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 1; i != 0; i = i << 1)
//	{
//		if (value & 1 == 1)
//			count++;
//		value = value >> 1;
//	}
//	return count;
//
//}
//int main()
//{
//	int value = 0;
//	scanf("%d", &value);
//	int ret = count_one_bits(value);
//	printf("%d", ret);
//}

