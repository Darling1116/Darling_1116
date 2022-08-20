#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//һ����������m��n��С�ĵ�ͼ�����Ͻǣ���㣩
//������ÿ�ο������»������ƶ�,Ҫ�����ͼ�����½ǣ��յ㣩
//�����ж����ֲ�ͬ��·��������ߵ��յ㣿
int uniquePaths(int m, int n) {
	//vv��ʾ��㵽��(i, j)�Ĳ�ͬ·������
	vector<vector<int>> vv(m, vector<int>(n, 1));
	//��һ�С���һ��Ԫ�ص�·����Ϊ1
	for (int i = 0; i < m; i++){
		vv[i][0] = 1;
	}
	for (int j = 0; j < n; j++){
		vv[0][j] = 1;
	}

	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			//�����ߵ�·�����������ߵ�·����֮��
			vv[i][j] = vv[i - 1][j] + vv[i][j - 1]; 
		}
	}
	return vv[m - 1][n - 1];
}

void test1_1(){
	int ret = uniquePaths(2, 2);
	cout << ret << endl;
}