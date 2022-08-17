#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//适配器返回类型为bool型
bool com_pare(int x, int y){
	string sx = to_string(x);
	string sy = to_string(y);
	string A = sx;
	string B = sy;
	A += sy;
	B += sx;
	return A < B;
}



//把数组排成最小的数
//使用sort函数进行排序，编写适配器，定义自己的比较规则
string PrintMinNumber(vector<int> numbers) {
	string result;
	if (numbers.empty())
		return result;

	sort(numbers.begin(), numbers.end(), com_pare);
	for (int i = 0; i < numbers.size(); i++){
		result += to_string(numbers[i]);
	}
	return result;
}


void test1_1(){
	vector<int> v = { 3, 32, 321 };
	string s = PrintMinNumber(v);
	cout << s << endl;
}