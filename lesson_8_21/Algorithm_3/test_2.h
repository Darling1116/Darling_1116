#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//��������Ƿ��ǻ��Ĵ�
bool isHuiwen(string s){
	int len = s.length();
	//s��������[i, j]��Χ�ڵ��Ƿ��ǻ��Ĵ�
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

//����һ���ַ���s
//�ָ�sʹ�÷ָ����ÿһ���Ӵ����ǻ��Ĵ�
//���㽫�ַ���s�ָ�ɻ��ķָ�������С�и���
int minCut(string s){
	int len = s.length();

	vector<int> result(len+1, 0);
	//s��ǰi���ַ�������и����Ϊi-1
	for (int i = 1; i <= len; i++){
		result[i] = i - 1;
	}

	//��2���ַ���ʼ��������
	for (int i = 2; i <= len; i++){
		if (isHuiwen_2(s, 0, i-1)){
			result[i] = 0;
			continue;
		}
		for (int j = 0; j < i; j++){  //i��ʾǰi���ַ�
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