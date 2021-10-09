#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//该结构体的大小为20个字节

void main(){

	/*
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	//00100014
	//00100001  指针加整数，取决于指针的类型,向后偏移了一个字节
	//00100004


	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d\n", *(a + 1), *(ptr - 1));
	//2  5
	*/

	
	/*
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	//4, 02000000
	*/


	/*
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//逗号表达式：先求表达式1的值，再求表达式2的值，表达式2的值为整个表达式的值
	int *p;
	p = a[0];
	printf("%d\n", p[0]);
	*/

	
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	

	/*
	char *a[] = { "work", "at", "alibaba" };
	char ** pa = a;
	printf("%s\n", *pa);
	*/


	/*
	//------未解决------
	char *c[] = { "enter", "new", "point", "first" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;
	//cp  = first point new enter
	printf("%s\n", **++cpp);  //point
	printf("%s\n", *--*++cpp+3);  //er
	//*++cpp：跳过一个cp数组    *--*++cpp：后退一个词   +3：往前数3个字符
	printf("%s\n", *cpp[-2]+3);  //st
	printf("%s\n", cpp[-1][-1]+1);  //ew
	*/

	system("pause");
	return 0;
}
