#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


//求1～n这n个整数的十进制表示中1出现的次数
//动规---超出时间限制
int countDigitOne(int n) {
	int high = n;  //高位数
	int low = 0;  //低位数
	int cur = 0;  //当前位
	int num = 1;  //当前位因子
	int count = 0;  //1出现的次数

	while (high > 0){
		cur = high % 10;
		high /= 10;

		if (cur == 0)
			count += high * num;
		else if (cur == 1)
			count += high * num + low + 1;
		else
			count += (high + 1) * num;

		low = cur * num + low;
		num *= 10;
	}

	return count;
}




void test1_1(){
	int ret1 = countDigitOne(12);
	cout << ret1 << endl;
	int ret2 = countDigitOne(13);
	cout << ret2 << endl;
}