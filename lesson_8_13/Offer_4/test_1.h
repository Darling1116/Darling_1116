#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//1.输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果
bool VerifySquenceOfBSTChild(vector<int> sequence, int begin, int end){
	if (begin >= end)
		return true;

	int root = sequence[end];  //后序遍历的最后一个结点为根结点
	int i = 0;
	while (i < end && sequence[i] < root){  //找左子树部分
		i++;
	}

	for (int j = i; j < end; j++){ //验证右子树部分符不符合二叉搜索树的性质
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

