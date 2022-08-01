#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.递归打印一个数的每一位
void print(int n){
	if (n > 9)
		print(n / 10);
	printf("%d ", n % 10);
}
void test1_1(){
	int a = 8973;
	print(a);
}


//2.求阶乘（递归与非递归）
int fac(int n){
	if (n == 1)
		return 1;
	return fac(n - 1) * n;
}

void test1_2(){
	int ret = fac(5);
	printf("%d\n", ret);

	int n = 5;
	int sum = 1;
	for (int i = 1; i <= n; i++){
		sum = sum*i;
	}
	printf("%d\n", sum);
}



//3.字符串逆序（递归与非递归）
void reverse(char* str){
	int len = my_strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';

	if (my_strlen(str + 1) >= 2)
		reverse(str + 1);

	*(str + len - 1) = tmp;
}

void test1_3(){
	char str[] = "hiahsihd";
	reverse(str);
	printf("%s\n", str);

	int left = 0;
	int right = my_strlen(str) - 1;
	while (left < right){
		int tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
	for (int i = 0; i < my_strlen(str); i++){
		printf("%c ", str[i]);
	}
}

//4.递归实现计算一个非负整数的每位之和
int DigitSum(unsigned int n){
	if (n < 9)
		return n;
	return n % 10 + DigitSum(n / 10);
}

void test1_4(){
	int a = 7364;
	int ret = DigitSum(a);
	printf("%d\n", ret);
}


//5. 递归实现n的k次方:对k的取值范围进行考虑
double Power(int n, int k){
	if (k == 0)
		return 1;
	else if (k > 0){
		return n*Power(n, k - 1);
	}
	else{
		return 1.0 / n*Power(n, k + 1);
	}

}

void test1_5(){
	int ret1 = Power(2, 5);
	printf("%d\n", ret1);
	int ret2 = Power(2, 0);
	printf("%d\n", ret2);
	double ret3 = Power(2, -5);
	printf("%f\n", ret3);
}


//6.计算斐波那契数列（递归与非递归）
int fib(int n){
	if (n==0 || n==1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int fib2(int n){
	if (n == 0 || n == 1)
		return 1;
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	for (int i = 2; i <= n; i++){
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
void test1_6(){
	int ret1 = fib(8);
	printf("%d\n", ret1);
	int ret2 = fib2(8);
	printf("%d\n", ret2);
}