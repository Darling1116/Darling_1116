#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1.获取一个整数二进制序列中所有的偶数位和奇数位
//分别打印出二进制序列
void test1_1(){
	int a = 0;
	scanf("%d", &a);

	int i = 0;
	for (i = 31; i >= 1; i -= 2){
		printf("%d ", (a >> i) & 1);
	}
	printf("\n");
	for (i = 30; i >= 0; i -= 2){
		printf("%d ", (a >> i) & 1);
	}
	printf("\n");

}


//2.交换两个变量（不创建临时变量）
void test1_2(){
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	printf("a=%d, b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d, b=%d\n", a, b);
}

//写一个函数打印arr数组的内容，不使用下标，使用指针
void print_1(int* arr, int len){
	int* cur = arr;
	while (len--){
		printf("%d ", *cur);
		cur++;
	}
}

void print_2(int* arr, int len){
	int* cur = arr; 
	for (int i = 0; i < len; i++){
		printf("%d ", *(cur + i));
	}
}

void test1_3(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print_1(arr, len);
	printf("\n");
	print_2(arr, len);
}

//4.求S=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
int sum(int a, int n){
	int sum = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++){
		tmp = tmp * 10 + a;
		sum = sum + tmp;
	}
	return sum;
}
void test1_4(){
	int a = 2;
	int n = 5;
	printf("%d\n", sum(a, n));
}

//5.求出0-100000之间的所有水仙花数并输出

int count(int num){
	int n = 0;
	while (num){
		n++;
		num = num / 10;
	}
	return n;
}
void test1_5(){
	//printf("%d\n", n(2324));

	for (int i = 1; i < 100000; i++){
		int n = count(i);
		int tmp = i;
		int sum = 0;
		while (tmp){
			sum += (int)pow(tmp % 10, n);
			tmp = tmp / 10;
		}
		if (sum == i)
			printf("%d ", sum);
	}
}


