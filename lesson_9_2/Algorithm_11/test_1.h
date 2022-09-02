#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;

//��1�֣�2�֣�5�֣�10������Ӳ�ң�ÿ��Ӳ����������
//����n��Ǯ���ж�������Ͽ������n��Ǯ��   �����������𰸶�1e9+7ȡģ
//���룺13      �����16

//Ӳ�һ���
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