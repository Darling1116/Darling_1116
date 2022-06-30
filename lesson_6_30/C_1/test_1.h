#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>

void test_1(){
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(long double));
}

void test_2_1() { int i = 0; i++; printf("%d ", i); }

void test_2_2() { static int i = 0; i++; printf("%d ", i); }
void test_2(){
	for (int i = 0; i<10; i++) { test_2_1(); }
	for (int i = 0; i<10; i++) { test_2_2(); }
}

void test_3(){
	//int a = 0;
	//scanf("%d", &a);
	//if (a % 2 == 0){
	//	printf("a为偶数\n");
	//}
	//else{
	//	printf("a为奇数\n");
	//}

	//for (int i = 1; i <= 100; i+=2){
	//	printf("%d ", i);
	//}

	//int i = 1;
	//while (i <= 10){
	//	i = i + 1;
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//	
	//}

	/*int day = 0;
	scanf("%d", &day);
	switch (day){
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	printf("weekday\n");
	break;
	case 6:
	case 7:
	printf("weekend\n");
	break;
	default:
	break;
	}*/

	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
		k++;
	printf("%d ", k);
}

void test_4(){
	char arr1[] = "welcome to eat the sweet ice cream...";
	char arr2[] = "#####################################";
	int left = 0;
	int right = strlen(arr1) - 1;
	printf("%s\n", arr2);
	while (left <= right){
		Sleep(100);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
}

void test_5(){
	//n的阶乘
	int n = 0;
	scanf("%d", &n);
	int sum = 1;
	/*for (int i = 1; i <= n; i++){
	sum = sum*i;
	}
	printf("%d\n", sum);
	*/

	//1！+2！+...+10!
	int ret = 0;
	for (int i = 1; i <= n; i++){
		sum = sum*i;
		ret += sum;
	}
	printf("%d\n", ret);
}

//顺序打印一个整数的每一位
void Print(int n){
	if (n > 9){
		Print(n / 10);
	}
	printf("%d ", n % 10);
}

//编写函数不允许创建临时变量，求字符串的长度
int Len(const char* str){
	if (*str == '\0')
		return 0;
	return 1 + Len(str + 1);
}

int Fib(int n){
	if (n <= 2)
		return 1;
	else{
		return Fib(n - 1) + Fib(n - 2);
	}
}

void test_6(){
	//int n = 1234;
	//Print(n);

	char* str = "abcdefg";
	int len = Len(str);
	printf("%d\n", len);

	int ret = Fib(15);
	printf("%d\n", ret);
}

void test_7(){
	int num1 = 1;
	int num2 = 2;
	printf("%d ", num1 & num2);
	printf("%d ", num1 | num2);
	printf("%d ", num1 ^ num2);
}

void test_8_1(int arr[]){
	printf("%d\n", sizeof(arr));//(2)
}
void test_8_2(char ch[]){
	printf("%d\n", sizeof(ch));//(4)
}


void test_8(){
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//(1)
	printf("%d\n", sizeof(ch));//(3)
	test_8_1(arr);
	test_8_2(ch);

	//int i = 0, a = 0, b = 2, c = 3, d = 4;
	////i = a++ && ++b && d++;
	//i = a++||++b||d++;
	//printf("a = %d b = %d c = %d d = %d\n", a, b, c, d);

	//int a = 1;
	//int b = 2;
	//int c = (a>b, a = b + 10, a, b = a + 1);
	//printf("%d\n", c);

	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("%d\n", ret);
	printf("%d\n", i);

}