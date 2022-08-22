#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//不同的子序列
int numDistinct(string S, string T) {
	//s的前i个字符包含t的前j个字符的不同子序列的个数
	vector<vector<int>> vv(S.length() + 1, vector<int>(T.length() + 1, 0));
	for (int i = 0; i <= S.length(); i++){
		vv[i][0] = 1;
	}

	for (int i = 1; i <= S.length(); i++){
		for (int j = 1; j <= T.length(); j++){
			if (S[i - 1] == T[j - 1]){
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
			else{
				vv[i][j] = vv[i - 1][j];
			}
		}
	}

	return vv[S.length()][T.length()];
}

void test2_1(){
	string S = "nowcccoder";
	string T = "nowccoder";
	int ret = numDistinct(S, T);
	cout << ret << endl;
}