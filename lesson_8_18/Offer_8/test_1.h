#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;


//和为S的连续正数序列
vector<vector<int>> FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	if (sum <= 0)
		return result;

	//设置一前一后两个指针
	int begin = 1;
	int end = 2;
	while (begin < end){
		//计算begin-end的序列和
		if (((begin + end)*(end - begin + 1) / 2) == sum){
			vector<int> v;
			for (int i = begin; i <= end; i++){
				v.push_back(i);
			}
			result.push_back(v);
			begin++;  //下一次滑动的起始位置
		}
		else if (((begin + end)*(end - begin + 1) / 2) < sum){
			end++;
		}
		else{
			begin++;
		}
	}
	return result;

}


void test1_1(){
	vector<vector<int>> vv = FindContinuousSequence(9);
	for (auto& e : vv){
		for (auto& a : e){
			cout << a << " ";
		}
		cout << endl;
	}
}