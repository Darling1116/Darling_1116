#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;

//有1分，2分，5分，10分四种硬币，每种硬币数量无限
//给定n分钱，有多少中组合可以组成n分钱？   输出组合数，答案对1e9+7取模
//输入：13      输出：16

//硬币划分
void test1_1(){
	int n = 0;
	cin >> n;

	vector<int> coins = { 1, 2, 5, 10 };
	vector<vector<int>> v(coins.size() + 1, vector<int>(n + 1, 0));

	for (int i = 0; i <= coins.size(); i++){
		v[i][0] = 1;
	}

	for (int i = 1; i <= coins.size(); i++){
		for (int j = 1; j <= n; j++){
			if (coins[i - 1] <= j){
				v[i][j] = v[i - 1][j] + v[i][j - coins[i - 1]];
			}
			else{
				v[i][j] = v[i - 1][j];
			}
		}
	}

	cout << v[coins.size()][n] << endl;

}