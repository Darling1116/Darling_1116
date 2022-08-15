#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//取最小的k个数
//方法1：直接利用sort库函数排序
vector<int> GetLeastNumbers_Solution_1(vector<int>& input, int k) {
	sort(input.begin(), input.end());
	input.resize(k);
	return input;
}


//方法2：利用堆排序---利用优先级队列
vector<int> GetLeastNumbers_Solution_2(vector<int> input, int k) {
	vector<int> result;
	if (k > input.size() || k <= 0)  //判断k值的合法性
		return result;

	priority_queue<int> pq;  //默认为降序：弱排序
	int i = 0;
	for (i = 0; i<k; i++){
		pq.push(input[i]);
	}

	for (; i<input.size(); i++){
		if (input[i] < pq.top()){
			pq.pop();
			pq.push(input[i]);
		}
	}

	while (!pq.empty()){
		result.push_back(pq.top());
		pq.pop();
	}
	return result;

}
void test2_1(){
	vector<int> v = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> result =  GetLeastNumbers_Solution_2(v, 5);
	for (auto e : result){
		cout << e << " ";
	}
	cout << endl;

	//priority_queue<int> pq;
	//for (auto e : v){
	//	pq.push(e);
	//}
	//while(!pq.empty()){
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}

}