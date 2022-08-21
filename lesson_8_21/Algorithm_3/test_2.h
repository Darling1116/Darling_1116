#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//动规求解是否是回文串
bool isHuiwen(string s){
	int len = s.length();
	//s中区间在[i, j]范围内的是否是回文串
	vector<vector<bool>> vv(len, vector<bool>(len, false));
	for (int i = len - 1; i >= 0; i--){
		for (int j =i; j < len; j++){
			if (i == j){
				vv[i][j] = true;
			}
			else if (i + 1 == j){
				vv[i][j] = (s[i] == s[j]);
			}
			else{
				vv[i][j] = (s[i] == s[j] && vv[i + 1][j - 1]);
			}
		}
	}
	return vv[0][len - 1];
}


bool isHuiwen_2(string s, int left, int right){
	while (left < right){
		if (s[left] != s[right])
			return false;
		left++;
		right--;
	}
	return true;
}

//给出一个字符串s
//分割s使得分割出的每一个子串都是回文串
//计算将字符串s分割成回文分割结果的最小切割数
int minCut(string s){
	int len = s.length();

	vector<int> result(len+1, 0);
	//s的前i个字符的最大切割次数为i-1
	for (int i = 1; i <= len; i++){
		result[i] = i - 1;
	}

	//从2个字符开始进行讨论
	for (int i = 2; i <= len; i++){
		if (isHuiwen_2(s, 0, i-1)){
			result[i] = 0;
			continue;
		}
		for (int j = 0; j < i; j++){  //i表示前i个字符
			if (isHuiwen_2(s, j, i-1)){
				result[i] = min(result[i], result[j] + 1);
			}
		}
	}

	return result[len];

}


void test2_1(){
	string s = "aab";

	//bool ret = isHuiwen(s);
	//cout << ret << endl;

	int ret = minCut(s);
	cout << ret << endl;
}