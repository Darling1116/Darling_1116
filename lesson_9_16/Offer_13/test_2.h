#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//把只包含质因子 2、3 和 5 的数称作丑数
//求按从小到大的顺序的第 n 个丑数
//例：n=10     1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前10个丑数

int nthUglyNumber(int n) {
	//第i个丑数=前面某较小的丑数x某因数
	vector<int> v(n, 0);
	v[0] = 1; //第一个丑数为1

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
	cout << nthUglyNumber(10) << endl;   //输出12
}