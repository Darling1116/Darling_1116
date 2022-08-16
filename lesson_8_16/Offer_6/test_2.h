#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//2.回文数索引:给找出一个位置，删掉那个字母之后，字符串变成回文
//总会有一个合法的解，如果给定的字符串已经是一个回文串，那么输出-1。

//输入：第一行包含T，测试数据的组数;后面跟有T行，每行包含一个字符串。
//输出：如果可以删去一个字母使它变成回文串，则输出任意一个满足条件的删去字母的位置

bool isHuiwen(string str, int* begin, int* end){
	int left = 0;
	int right = str.length() - 1;
	while (left < right){
		if (str[left] == str[right]){
			left++;
			right--;
		}
		else{
			if (begin != nullptr)
				*begin = left;
			if (end != nullptr)
				*end = right;
			return false;
		}
	}
	return true;
}


void test2_1(){
	int n = 0;
	cin >> n;

	while (n){
		string str;
		cin >> str;

		int begin = 0;
		int end = 0;

		if (isHuiwen(str, &begin, &end)){
			cout << -1 << endl;
		}
		else{
			str.erase(begin, 1);
			if (isHuiwen(str, nullptr, nullptr))
				cout << begin << endl;
			else
				cout << end << endl;
		}
		n--;
	}
}