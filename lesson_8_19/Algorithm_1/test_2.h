#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给定一个三角形 triangle ，找出自顶向下的最小路径和
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.empty())
		return 0;

	int row = triangle.size();
	int col = triangle[0].size();

	//第一行的最小路径就是这个元素本身
	for (int i = 1; i < row; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0){
				triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
			}
			else if (i == j){
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
			}
			else{
				triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
			}
		}
	}

	int min_num = triangle[row - 1][0];
	for (int i = 1; i < row; i++){
		if (triangle[row - 1][i] < min_num)
			min_num = triangle[row - 1][i];
	}
	return min_num;
}


void test2_1(){
	vector<vector<int>> v = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	cout << minimumTotal(v) << endl;
}