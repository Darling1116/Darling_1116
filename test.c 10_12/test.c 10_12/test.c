#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void menu( )
{
	printf("*********************\n");
	printf("*******1.play********\n");
	printf("*******0.exit********\n");
	printf("*********************\n");
}
void game( )
{
	int num = 0;
	int ret = rand( ) % 100 + 1;//生成一个随机数
	while (1)
	{
		printf("请猜数字：>\n");
		scanf("%d", &num);
		if (num==ret)
		{
			printf("恭喜你\n");
			break;
		}
		else if (num > ret)
			printf("猜大了\n");
		else
			printf("猜小了\n");
	}
}
int main( )
{
	int input = 0;

	do
	{
		srand((unsigned)time(NULL));//提供每次获得随机数的基数，unsigned要用括号修饰
		menu( );
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game( );
			break;
		case 2:
			break;
		default:
			printf("选择错误\n");
			break;
		}
		
	}
	while (input);
	return 0;
}
