#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(){
	char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr1));  //6 计算的是数组的大小

	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));  //7 计算的是字符串的大小(包括/0)
	printf("%d\n", sizeof(arr+0));  //4 计算的是首元素的地址
	printf("%d\n", sizeof(*arr));  //1 首元素的大小
	printf("%d\n", sizeof(arr[1]));  //1 第二个元素的大小
	printf("%d\n", sizeof(&arr));  //4 数组的地址
	printf("%d\n", sizeof(&arr+1));  //4 跳过整个数组后的地址
	printf("%d\n", sizeof(&arr[0]+1));  //4 第二个元素的地址

	printf("%d\n", strlen(arr));  //6
	printf("%d\n", strlen(arr+0));  //6
	printf("%d\n", strlen(&arr));  //6
	printf("%d\n", strlen(&arr+1));  //随机值
	printf("%d\n", strlen(&arr[0]+1));  //5

	system("pause");
	return 0;
}