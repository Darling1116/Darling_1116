#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test1(){
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3 = "hello bit.";
	char *str4 = "hello bit.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str3)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

}


int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a*b;
}
int divsion(int a, int b) {
	return a / b;
}

void test2(){
	int x, y;
	int input = 1;
	int ret = 0;
	// 函数指针数组
	int(*p[5])(int x, int y) = { 0, add, sub, mul, divsion }; //转移表
	while (input){
		printf("*************************\n");
		printf(" 1:add             2:sub \n");
		printf(" 3:mul             4:div \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if ((input <= 4 && input >= 1))
		{
			printf("输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
			printf("输入有误\n");
		printf("ret = %d\n", ret);
	}
}


void test3_1(){
	//一维数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a + 0));  //首元素的地址
	printf("%d\n", sizeof(*a));  //首元素的大小
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(a[1]));
	printf("%d\n", sizeof(&a));  //整个数组地址的大小
	printf("%d\n", sizeof(*&a));
	printf("%d\n", sizeof(&a + 1));  //跳过一个数组后的地址
	printf("%d\n", sizeof(&a[0]));
	printf("%d\n", sizeof(&a[0] + 1));
}


void test3_2(){
	//字符数组
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));

	printf("%d\n", strlen(arr));  //数组的地址，求长度 随机值
	printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));

	//指向数组末尾，还是地址，随机值，和上面差6
	//printf("%d\n", strlen(&arr + 1));

	printf("%d\n", strlen(&arr[0] + 1));
}


void test3_3(){
	char arr[] = "abcdef";  //常量字符串，末尾隐藏字符'\0'

	//数组所占内存大小: 6个字符 + 末尾隐藏字符'\0'--> 7
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));

	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));
}

void test3_4(){
	char *p = "abcdef";
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));

	printf("%d\n", strlen(p));
	printf("%d\n", strlen(p + 1));
	//printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));

	//printf("%d\n", strlen(&p));
	// &p+1是跳过p之后的地址， 求长度 随机值 
	//printf("%d\n", strlen(&p + 1));

	printf("%d\n", strlen(&p[0] + 1));
}

void test3_5(){
	// 二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));

	//a+1表示第二个元素的地址，就是第二行数组的地址，求大小 4
	printf("%d\n", sizeof(a + 1));

	//*(a + 1)取出第二行数组，求大小 16
	printf("%d\n", sizeof(*(a + 1)));

	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));

	//a为首元素地址，*a取出首元素的内容，即第一行数组，求大小 16
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));
}