#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	return 0;
}

#include <stdio.h>
int main()
{
	int i = 0;
	int a[9] = { 0 };
	printf("请输入十个整数:\n");
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");
	int max = a[0];
	for (i = 0; i<10; i++)
	{
		if (max<a[i])
			max = a[i];
	}
	printf("max=%d\n", max);
	return 0;
}
