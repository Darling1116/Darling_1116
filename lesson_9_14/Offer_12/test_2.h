#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//礼物的最大值(类似于最小路径)
int maxValue(vector<vector<int>>& grid) {
	if (grid.empty())
		return 0;

	int row = grid.size();
	int col = grid[0].size();

	vector<vector<int>> vv(row, vector<int>(col, 0));
	vv[0][0] = grid[0][0];

	for (int i = 1; i < row; i++){
		vv[i][0] = vv[i-1][0] + grid[i][0];
	}

	for (int j = 1; j < col; j++){
		vv[0][j] = vv[0][j - 1] + grid[0][j];
	}

	for (int i = 1; i < row; i++){
		for (int j = 1; j < col; j++){
			vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]) + grid[i][j];
		}
	}

	return vv[row - 1][col - 1];
}


void test2_1(){
	vector<vector<int>> grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };

	int ret = maxValue(grid);
	cout << ret << endl;

}