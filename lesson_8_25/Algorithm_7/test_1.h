#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;

static int sum = 0;

//N本不同的书放到N个盒子里，共有多少种放法？
void DFS(vector<int>& book, vector<int>& box, int boxid, int n,  int& sum){
	if (boxid == n){
		for (auto& e : box){
			cout << e;
		}
		sum++;
		cout << endl;
	}

	for (int i = 0; i < n; i++){  //每一本书都有n种放法
		if (book[i] == 0){
			box[boxid] = i+1;
			book[i] = 1;

			//处理下一个盒子
			DFS(book, box, boxid + 1, n, sum);

			//回溯
			book[i] = 0;
		}
	}
}


void test1_1(){
	int n = 5;
	vector<int> book(n, 0);
	vector<int> box(n, 0);
	DFS(book, box, 0, n, sum);
	cout << sum << endl;
}