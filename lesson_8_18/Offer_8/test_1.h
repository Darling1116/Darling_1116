#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;


//��ΪS��������������
vector<vector<int>> FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	if (sum <= 0)
		return result;

	//����һǰһ������ָ��
	int begin = 1;
	int end = 2;
	while (begin < end){
		//����begin-end�����к�
		if (((begin + end)*(end - begin + 1) / 2) == sum){
			vector<int> v;
			for (int i = begin; i <= end; i++){
				v.push_back(i);
			}
			result.push_back(v);
			begin++;  //��һ�λ�������ʼλ��
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