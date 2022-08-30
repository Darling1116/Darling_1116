#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool isValidPos(vector<pair<int, int>>& curres, int row, int col){
	for (auto& e : curres){
		if ((e.second == col) || (e.first + e.second == row + col) 
			|| (e.first - e.second == row - col)){
			return false;
		}
	}
	return true;
}

void DFS(vector<vector<pair<int, int>>>& result, vector<pair<int, int>> curres, int currow, int n){
	if (currow == n){
		result.push_back(curres);
		return;
	}

	for (int i = 0; i < n; i++){
		if (isValidPos(curres, currow, i)){
			curres.push_back(make_pair(currow, i));
			DFS(result, curres, currow + 1, n);
			curres.pop_back();
		}
	}
}

vector<vector<string>> transform(vector<vector<pair<int, int>>>& result, int n){
	vector<vector<string>> transtr;
	for (auto res : result){
		vector<string> str(n, string(n, '.'));  //用n个.来初始化字符
		for (auto e : res){
			str[e.first][e.second] = 'Q';  //第几个字符串的第几个字符
		}
		transtr.push_back(str);
	}
	return transtr;
}

//n皇后问题
vector<vector<string>> solveNQueens(int n) {
	vector<vector<pair<int, int>>> result;
	vector<pair<int, int>> curres;
	DFS(result, curres, 0, n);

	return transform(result, n);
}


void test1_1(){
	vector<vector<string>> result;
	result = solveNQueens(4);

	for (auto res : result){
		for (auto e : res){
			cout << e << ",";
		}
		cout << endl;
	}

	//输出: [[".Q..","...Q","Q...","..Q."],
	//["..Q.","Q...","...Q",".Q.."]]

}