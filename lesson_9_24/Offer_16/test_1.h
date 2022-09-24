#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//n个骰子的点数：动规问题
vector<double> dicesProbability(int n) {
	vector<double> res;
	if (n == 0)
		return res;

	//i个骰子组合成合为j的可能次数
	//n个骰子组合和的范围为：[n,6*n]
	vector<vector<int>> vv(n + 1, vector<int>(6 * n + 1, 0));
	
	//一个骰子组合成和为[1,6]的次数都为1
	for (int j = 1; j <= 6; j++){
		vv[1][j] = 1;
	}

	for (int i = 2; i <= n; i++){
		for (int j = i; j <= 6 * n; j++){
			//每个筛子每次的取值为[1, 6]
			for (int cur = 1; cur <= 6; cur++){
				if (j > cur){
					vv[i][j] += vv[i - 1][j - cur];
				}
				else{
					break;
				}
			}
		}
	}

	//计算分母：n个骰子组合和的情况
	double count = pow(6, n);

	//按照组合和的范围计算频率
	for (int j = n; j <= 6 * n; j++){
		res.push_back(vv[n][j] / count);
	}

	return res;

}


void test1_1(){
	vector<double> res = dicesProbability(2);

	for (auto& e : res){
		cout << e << " ";
	}
}