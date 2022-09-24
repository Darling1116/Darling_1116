#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//n�����ӵĵ�������������
vector<double> dicesProbability(int n) {
	vector<double> res;
	if (n == 0)
		return res;

	//i��������ϳɺ�Ϊj�Ŀ��ܴ���
	//n��������Ϻ͵ķ�ΧΪ��[n,6*n]
	vector<vector<int>> vv(n + 1, vector<int>(6 * n + 1, 0));
	
	//һ��������ϳɺ�Ϊ[1,6]�Ĵ�����Ϊ1
	for (int j = 1; j <= 6; j++){
		vv[1][j] = 1;
	}

	for (int i = 2; i <= n; i++){
		for (int j = i; j <= 6 * n; j++){
			//ÿ��ɸ��ÿ�ε�ȡֵΪ[1, 6]
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

	//�����ĸ��n��������Ϻ͵����
	double count = pow(6, n);

	//������Ϻ͵ķ�Χ����Ƶ��
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