#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��ֻ���������� 2��3 �� 5 ������������
//�󰴴�С�����˳��ĵ� n ������
//����n=10     1, 2, 3, 4, 5, 6, 8, 9, 10, 12 ��ǰ10������

int nthUglyNumber(int n) {
	//��i������=ǰ��ĳ��С�ĳ���xĳ����
	vector<int> v(n, 0);
	v[0] = 1; //��һ������Ϊ1

	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 1; i < n; i++){
		int da = v[a] * 2;
		int db = v[b] * 3;
		int dc = v[c] * 5;

		v[i] = min(min(da, db), dc);
		if (v[i] == da)
			a++;
		if (v[i] == db)
			b++;
		if (v[i] == dc)
			c++;
	}
	return v[n - 1];

}


void test2_1(){
	cout << nthUglyNumber(10) << endl;   //���12
}