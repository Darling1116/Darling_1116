#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(){
	char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr1));  //6 �����������Ĵ�С

	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));  //7 ��������ַ����Ĵ�С(����/0)
	printf("%d\n", sizeof(arr+0));  //4 ���������Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr));  //1 ��Ԫ�صĴ�С
	printf("%d\n", sizeof(arr[1]));  //1 �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr));  //4 ����ĵ�ַ
	printf("%d\n", sizeof(&arr+1));  //4 �������������ĵ�ַ
	printf("%d\n", sizeof(&arr[0]+1));  //4 �ڶ���Ԫ�صĵ�ַ

	printf("%d\n", strlen(arr));  //6
	printf("%d\n", strlen(arr+0));  //6
	printf("%d\n", strlen(&arr));  //6
	printf("%d\n", strlen(&arr+1));  //���ֵ
	printf("%d\n", strlen(&arr[0]+1));  //5

	system("pause");
	return 0;
}