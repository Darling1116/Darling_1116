#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//设置sort的比较规则
bool com(vector<int>& v1, vector<int>& v2){
	return v1[0] > v2[0];
}

//钱币找零
int money_num(vector<vector<int>> vv, int k){
	//把纸币按照面值的大小进行降序排序
	sort(vv.begin(), vv.end(), com);
	int count = 0;
	for (int i = 0; i < vv.size(); i++){
		int c = k / vv[i][0];
		c = min(c, vv[i][1]);
		count += c;
		k -= c*vv[i][0];
		if (k == 0){
			return count;
		}
	}
}


void test1_1(){
	vector<vector<int>> vv = { { 20, 4 }, { 10, 5 }, { 100, 2 }, { 50, 9 }, { 1, 8 }, { 2, 5 }, { 5, 6 } };
	int ret = money_num(vv, 310);
	cout << ret << endl;
}