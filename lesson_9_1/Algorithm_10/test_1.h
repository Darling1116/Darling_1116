#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>


using namespace std;

//字符串转换为整型形式
int str_to_int(string& str){
	int num = 0;
	int flag = 1;  //是否需要变号
	for (int i = 0; i < str.length(); i++){
		if (str[i] == '-'){
			flag = -1;
		}

		if (str[i] >= '1' && str[i] <= '9'){
			num = num * 10 + flag* (str[i] - '0');
		}
	}
	return num;
}


//复数乘法
//输入：1+2i   2+1   输出：0+5i
void test1_1(){
	string str1;
	string str2;
	cin >> str1 >> str2;

	//按+号分割字符串
	string str1_1 = str1.substr(0, str1.find('+'));
	string str1_2 = str1.substr(str1.find('+') + 1);
	string str2_1 = str2.substr(0, str2.find('+'));
	string str2_2 = str2.substr(str2.find('+') + 1);

	int int1_1 = str_to_int(str1_1);
	int int1_2 = str_to_int(str1_2);
	int int2_1 = str_to_int(str2_1);
	int int2_2 = str_to_int(str2_2);

	int ret1 = int1_1*int2_1 - int1_2*int2_2;  //整数乘积
	int ret2 = int1_2*int2_1 + int1_1*int2_2; //复数乘积

	cout << ret1 << "+" << ret2 << "i" << endl;
}
