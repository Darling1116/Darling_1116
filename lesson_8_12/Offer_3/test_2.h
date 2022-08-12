#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>

using namespace std;

//方法3：递归+剪枝的思想

int fib3(int n){
	if (n == 1 || n == 2)
		return 1;

	unordered_map<int, int> map;
	int ppre = 0;
	if (map.find(n - 2) == map.end()){  //n-1个斐波那契书还没有计算
		ppre = fib3(n - 2);
		map.insert({ n - 2, ppre });
	}
	else{
		ppre = map[n - 2];
	}

	int pre = 0;
	if (map.find(n - 1) == map.end()){  //n-1个斐波那契书还没有计算
		pre = fib3(n - 1);
		map.insert({ n - 1, pre });
	}
	else{
		pre = map[n - 1];
	}
	return ppre + pre;
}



void test2_1(){
	cout << fib3(10) << endl;
}