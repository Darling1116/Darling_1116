#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给定一个 n * m 的矩阵 a
//从左上角开始每次只能向右或者向下走
//最后到达右下角的位置
//路径上所有的数字累加起来就是路径和
//输出所有的路径中最小的路径和

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