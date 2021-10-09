#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}* p;
//该结构体的大小为20个字节

void main1(){

	/*
	char* p = "abcdef";
	printf("%d\n", sizeof(p));  //4、8 计算的是指针变量p的大小
	printf("%d\n", sizeof(p + 1));  //4、8 得到的是字符b的地址
	printf("%d\n", sizeof(*p));  //1 第一个字符的大小
	printf("%d\n", sizeof(p[0]));  //1  p[0]==*(p+0)  第一个元素的大小
	printf("%d\n", sizeof(&p));  //4、8 数组的地址
	printf("%d\n", sizeof(&p + 1));  //4、8 跳过整个数组后的地址
	printf("%d\n", sizeof(&p[0] + 1));  //4、8 第二个元素的地址


	printf("%d\n", strlen(p));  //6
	printf("%d\n", strlen(p + 1));  //5
	printf("%d\n", strlen(&p));  //随机值
	printf("%d\n", strlen(&p + 1));  //随机值
	printf("%d\n", strlen(&p[0] + 1));  //5
	*/

	
	/*
	int a[3][4] = { 0 };
	printf("%p\n", &a[0][0]);  //数组的地址
	printf("%p\n", a[0] + 1);  //第一行第二个元素的地址
	printf("%p\n", a + 1);  //第二行首元素的地址
	printf("%p\n", &a[0] + 1);  //第二行首元素的地址
	*/

	
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));  //48
	printf("%d\n", sizeof(a[0][0]));  //4

	printf("%d\n", sizeof(a[0]));  
	//16  a[0]是第一行的数组名，计算的是第一行的大小
	printf("%d\n", sizeof(a[0]+1));  
	//4、8  a[0]是第一行的数组名，是首元素的地址,a[0]+1计算的是第一行第二个元素的地址
	printf("%d\n", sizeof(*(a[0] + 1)));  
	//4  第一行第二个元素的大小，int型，为4个字节

	printf("%d\n", sizeof(a+1));  
	//4、8  a是二维数组的数组名，是首元素的地址（第一行）,a+1计算的是第二行的地址
	printf("%d\n", sizeof(*(a + 1)));  
	//16    计算的是第二行的大小 4x4=16字节
	printf("%d\n", sizeof(&a[0] + 1));  
	//4、8  第二行的地址
	printf("%d\n", sizeof(*(&a[0] + 1)));  
	//16    第二行的大小

	printf("%d\n", sizeof(*a));  
	//16  a是二维数组的数组名，是第一行的地址,*a计算的是第一行的大小
	printf("%d\n", sizeof(a[3]));  //16


	system("pause");
	return 0;
}

