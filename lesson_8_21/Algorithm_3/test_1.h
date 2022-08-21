#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//��������
int max_value(vector<int>& value, vector<int>& wight, int& N, int& V){
	//��i����Ʒ���뱳����ļ�ֵ
	vector<vector<int>> vv(N + 1, vector<int>(V + 1, 0));

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= V; j++){
			if (wight[i-1] > j){
				vv[i][j] = vv[i - 1][j];
			}
			else{
				vv[i][j] = max(vv[i-1][j], vv[i-1][j-wight[i-1]] + value[i-1]);
			}
		}
	}
	return vv[N][V];
}


void test1_1(){
	int N = 5;  //��Ʒ����
	int V = 10;  //����������

	vector<int> value = { 8, 10, 4, 5, 5 };
	vector<int> wight = { 6, 4, 2, 4, 3 };

	int ret = max_value(value, wight, N, V);
	cout << ret << endl;
}