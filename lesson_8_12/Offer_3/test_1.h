#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//斐波那契数列
//方法1：动态规划的思想
int fib1(int n){
	if (n == 1 || n == 2)
		return 1;

	int a = 1;
	int b = 1;
	int c = 0;
	for (int i = 3; i <= n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

//方法2：简单的递归
int fib2(int n){
	if (n == 1 || n == 2)
		return 1;
	return fib2(n - 1) + fib2(n - 2);
}

void test1_1(){
	cout << fib1(10) << endl;
	cout << fib2(10) << endl;
}