#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//一个机器人在m×n大小的地图的左上角（起点）
//机器人每次可以向下或向右移动,要到达地图的右下角（终点）
//可以有多少种不同的路径从起点走到终点？
int uniquePaths(int m, int n) {
	//vv表示起点到点(i, j)的不同路径个数
	vector<vector<int>> vv(m, vector<int>(n, 1));
	//第一行、第一列元素的路径都为1
	for (int i = 0; i < m; i++){
		vv[i][0] = 1;
	}
	for (int j = 0; j < n; j++){
		vv[0][j] = 1;
	}

	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			//向下走的路径数与向右走的路径数之和
			vv[i][j] = vv[i - 1][j] + vv[i][j - 1]; 
		}
	}
	return vv[m - 1][n - 1];
}

void test1_1(){
	int ret = uniquePaths(2, 2);
	cout << ret << endl;
}