#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int fun(int n)
{
	int m = 0;
	int sum = 0;
	if (n != 0)
	{
		m = n % 10;
		n = n / 10;
		sum = m + fun(n);

	}
	return sum;
}
//int fun(int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return n % 10 + fun(n / 10);
////}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = 0;
	ret = fun(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}