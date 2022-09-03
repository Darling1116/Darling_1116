#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>


using namespace std;
int k_num(int n, int k){
	int num = 0;
	while (n){
		if (n % k == 0){
			num++;
			n = n / k;
		}
		else{
			break;
		}
	}
	return num;
}


//求表达式 f(n) = 1!×2!×3!×.....×n! 的结果末尾有几个连续的0
//输入：11     输出：9
void test1_1(){
	int n = 0;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += k_num(i, 5) * (n - i + 1);
	}

	cout << sum << endl;
}