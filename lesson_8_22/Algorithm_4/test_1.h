#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//最短编辑距离
int min_path(string& s, string& t){
	//s的前i个字符到t的前j个字符的最短编辑距离
	vector<vector<int>> vv(s.length() + 1, vector<int>(t.length() + 1, 0));

	for (int i = 1; i <= s.length(); i++){
		vv[i][0] = i;
	}

	for (int j = 1; j <= t.length(); j++){
		vv[0][j] = j;
	}

	for (int i = 1; i <= s.length(); i++){
		for (int j = 1; j <= t.length(); j++){
			//插入、删除
			vv[i][j] = min(vv[i][j - 1], vv[i - 1][j]) + 1;

			//替换
			if (s[i - 1] == t[j - 1])
				vv[i][j] = min(vv[i][j], vv[i - 1][j - 1]);
			else
				vv[i][j] = min(vv[i][j], vv[i - 1][j - 1] + 1);

		}
	}

	return vv[s.length()][t.length()];
}

void test1_1(){
	string s = "ABC";
	string t = "CBCD";
	int ret = min_path(s, t);
	cout << ret << endl;
}