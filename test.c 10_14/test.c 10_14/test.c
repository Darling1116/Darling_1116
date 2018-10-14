#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( )
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	//again:
	while (1)
	{
		printf("电脑在一分钟内将会关机，如果输入：我是猪，则取消关机\n");
		scanf("%s", input);
		if (strcmp(input, "我是猪") == 0)//比较两个字符串是否相同：strcmp
		{
			system("shutdown -a");//取消关机
			break;
		}
	}
	//else
	//{ 
		//goto again;
	//}
	return 0;
}