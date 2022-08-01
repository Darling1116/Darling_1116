#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//求两个数的最小公倍数
//方法1：让大的数每次增加1，直到该数能同时被两个整数整除
void test3_1(){
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int max = a > b ? a : b;
	while (1){
		if (max%a == 0 && max%b == 0){
			printf("%d\n", max);
			break;
		}
		max++;
	}
}

//方法1的缺点：当两个整数很大时，循环次数较多
//方法2： 利用a*n%b==0来判断
void test3_2(){
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int n = 1;
	while (n){
		if (a*n%b == 0){
			printf("%d\n", a*n);
			break;
		}
		n++;
	}
}