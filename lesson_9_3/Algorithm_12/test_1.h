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


//����ʽ f(n) = 1!��2!��3!��.....��n! �Ľ��ĩβ�м���������0
//���룺11     �����9
void test1_1(){
	int n = 0;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += k_num(i, 5) * (n - i + 1);
	}

	cout << sum << endl;
}