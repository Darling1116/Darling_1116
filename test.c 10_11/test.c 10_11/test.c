//递归求斐波那契数：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
	{
		int i = 0;
		int a = 1, b = 1, c = 0;
		for (i = 0; i < n - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", fib(num));
	return 0;
}

//非递归找斐波那契数：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n <= 2)
		printf("1\n");
	else
	{
		int i = 0;
		int a = 1, b = 1, c = 0;
		for (i = 0; i < n - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		printf("%d\n", b);
	}
	return 0;
}

//递归求n^k.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num_power(int n, int k)
{

	if (k == 1)
		return n;
	else
		return  n*num_power(n, k - 1);
}
int main()
{
	int ret = 0;
	ret = num_power(2, 3);
	printf("%d\n", ret);
	return 0;
}

//用DigitSum函数求每一位数的和：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m = n % 10;
		n = n / 10;
		sum = m + DigitSum(n);
	}
	return sum;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", DigitSum(num));
	return 0;
}

//递归求n的阶乘：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n*fac(n - 1);
}
int main()
{
	int num = 0;
	int ret = 0;
	scanf("%d", &num);
	ret = fac(num);
	printf("%d\n", ret);
	return 0;
}

//非递归求n的阶乘：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	int sum = 1;
	int i = 0;
	scanf("%d", &n);
	if (n > 1)
	{

		for (i = 0; i < n; i++)
		{
			sum = sum*n;
			n--;
		}
		printf("%d\n", sum);
	}
	else printf("1\n");
	return 0;
}

//依次打印一个数的每一位：
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Print(int n)
{
	if (n > 9)
		Print(n / 10);
	printf("%d ", n % 10);
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	return 0;
}
