#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//1.����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��
bool VerifySquenceOfBSTChild(vector<int> sequence, int begin, int end){
	if (begin >= end)
		return true;

	int root = sequence[end];  //������������һ�����Ϊ�����
	int i = 0;
	while (i < end && sequence[i] < root){  //������������
		i++;
	}

	for (int j = i; j < end; j++){ //��֤���������ַ������϶���������������
		if (sequence[j] < root)
			return false;
	}

	return VerifySquenceOfBSTChild(sequence, begin, i-1)
		&& VerifySquenceOfBSTChild(sequence, i, end - 1);
}


bool VerifySquenceOfBST(vector<int> sequence){
	if (sequence.size() == 0)
		return false;
	return VerifySquenceOfBSTChild(sequence, 0, sequence.size() - 1);
}

void test1_1(){
	vector<int> v1 = { 3, 1, 2};
	cout << VerifySquenceOfBST(v1) << endl;

	vector<int> v2 = { 5, 7, 6, 9, 11, 10, 8 };
	cout << VerifySquenceOfBST(v2) << endl;
}

