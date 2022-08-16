#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. ���������������
//����1���������
int FindGreatestSumOfSubArray_1(vector<int> array){
	if (array.empty())
		return 0;
	vector<int> sum;
	sum.resize(array.size());  //��ʼʱ��Ҫ��vector��ʼ����
	sum[0] = array[0];
	int max_num = sum[0];
	for (int i = 1; i < array.size(); i++){
		sum[i] = max(sum[i - 1] + array[i], array[i]);
		if (max_num < sum[i])
			max_num = sum[i];
	}
	return max_num;
}


//����2�������Ƚ����
int FindGreatestSumOfSubArray_2(vector<int> array){
	if (array.empty())
		return 0;

	int total = array[0];
	int max = total;

	for (int i = 1; i < array.size(); i++){
		if (total < 0){
			total = array[i];
		}
		else{
			total += array[i];
		}
		if (total > max)
			max = total;
	}
	return max;
}

void test1_1(){
	vector<int> v = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int ret = FindGreatestSumOfSubArray_1(v);
	cout << ret << endl;

	int ret2 = FindGreatestSumOfSubArray_2(v);
	cout << ret2 << endl;
}