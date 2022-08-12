#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>

using namespace std;

//����3���ݹ�+��֦��˼��

int fib3(int n){
	if (n == 1 || n == 2)
		return 1;

	unordered_map<int, int> map;
	int ppre = 0;
	if (map.find(n - 2) == map.end()){  //n-1��쳲������黹û�м���
		ppre = fib3(n - 2);
		map.insert({ n - 2, ppre });
	}
	else{
		ppre = map[n - 2];
	}

	int pre = 0;
	if (map.find(n - 1) == map.end()){  //n-1��쳲������黹û�м���
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