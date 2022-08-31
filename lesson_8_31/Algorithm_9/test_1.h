#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector<vector<int>> vv = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

//迷宫问题
bool canTravel(vector<vector<int>>& grid){
	

	int row = grid.size();
	int col = grid[0].size();

	vector<vector<int>> book(row, vector<int>(col, 0));
	queue<pair<int, int>> qu;
	qu.push(make_pair(0, 0));
	book[0][0] == 1;

	pair<int, int> cur;
	while (!qu.empty()){
		cur = qu.front();
		qu.pop();

		if (cur.first == row - 1 && cur.second == col - 1){
			return true;
		}

		for (auto e : vv){
			int newx = cur.first + e[0];
			int newy = cur.second + e[1];
			if (newx < 0 || newx >= row || newy < 0 || newy >= col){
				continue;
			}
			//判断是否有路可走且还没走过
			if (grid[newx][newy] == 0 && book[newx][newy] == 0){
				qu.push(make_pair(newx, newy));
				book[newx][newy] = 1;
			}
		}

	}
	return false;
	
}


void test1_1(){
	vector<vector<int>> grid = { { 0, 0, 1, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 0 }, { 1, 1, 0, 0 } };
	cout << canTravel(grid) << endl;

}