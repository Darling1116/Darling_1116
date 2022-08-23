#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//ѡ������
void select_sort(vector<int>& v){
	for (int i = 0; i < v.size(); i++){
		int index = i;  //��¼��СֵԪ�����ڵ��±�
		for (int j = i+1; j < v.size(); j++){
			if (v[j] < v[index])
				index = j;
		}
		swap(v[i], v[index]);
	}
}

void test1_1(){
	vector<int> v = { 4, 6, 21, 0, 3, 31, 434, 67 };
	select_sort(v);
	for (auto &e : v){
		cout << e << " ";
	}
	cout << endl;
}