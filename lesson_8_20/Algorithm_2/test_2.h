#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ�� n * m �ľ��� a
//�����Ͻǿ�ʼÿ��ֻ�����һ���������
//��󵽴����½ǵ�λ��
//·�������е������ۼ���������·����
//������е�·������С��·����

int min_path(vector<vector<int>>& vv, int n, int m){
	for (int i = 1; i < n; i++){
		vv[i][0] = vv[i - 1][0] + vv[i][0];
	}
	for (int j = 1; j < m; j++){
		vv[0][j] = vv[0][j - 1] + vv[0][j];
	}

	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + vv[i][j];
		}
	}

	return vv[n - 1][m - 1];
}

void test2_1(){
	//int n = 0;
	//int m = 0;
	//
	//vector<vector<int>> vv(n, vector<int>(m, 0));
	//for (int i = 0; i < n; i++){
	//	for (int j = 0; j < m; j++){
	//		cin >> vv[i][j];
	//	}
	//}

	vector<vector<int>> vv = { {1, 3, 5, 9}, {8, 1, 3, 4}, {5, 0, 6, 1}, {8, 8, 4, 0} };
	int ret = min_path(vv, 4, 4);
	cout << ret << endl;

}