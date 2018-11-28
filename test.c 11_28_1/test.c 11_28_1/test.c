#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long Fibonacci(size_t k)
{
	return k < 2 ? k : Fibonacci(k - 1) + Fibonacci(k - 2);
}

int main()
{
	printf("%d ", Fibonacci(3));
	system("pause");
	return 0;
}


//long long  Factorial(size_t  k)
//{
//	return k < 2 ? 1 : Factorial(k - 1) * k;
//}
//int main()
//{
//	printf("%d ", Factorial(6));
//	system("pause");
//	return 0;
//}