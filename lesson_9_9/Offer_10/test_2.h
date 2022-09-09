#pragma once
#include <iostream>
#include <vector>

using namespace std;


//À≥ ±’Î¥Ú”°æÿ’Û
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.empty())
		return res;

	int left = 0;
	int right = matrix[0].size()-1;
	int up = 0;
	int bottom = matrix.size() - 1;

	while (true){
		for (int j = left; j <= right; j++){
			res.push_back(matrix[up][j]);
		}
		if (++up > bottom)
			break;

		for (int i = up; i <= bottom; i++){
			res.push_back(matrix[i][right]);
		}
		if (--right < left)
			break;

		for (int j = right; j >= left; j--){
			res.push_back(matrix[bottom][j]);
		}
		if (--bottom < up)
			break;

		for (int i = bottom; i >= up; i--){
			res.push_back(matrix[i][left]);
		}
		if (++left > right)
			break;
	
	}

	return res;

}

void test2_1(){
	vector<vector<int>> vv = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	vector<int> res = spiralOrder(vv);

	for (auto& e : res){
		cout << e << ",";
	}
	cout << endl;

}