#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//在区间left-right上的序列是否是某二叉搜索树的后序遍历结果
bool verifyPostorderChild(vector<int>& postorder, int left, int right){
	if (left >= right)
		return true;

	int p = left;
	while (p < right && postorder[p] < postorder[right]){
		p++;
	}
	int mid = p - 1;  //划分左子树

	while (p < right && postorder[p] > postorder[right]){
		p++;
	}

	return  p == right && verifyPostorderChild(postorder, left, mid)
		&& verifyPostorderChild(postorder, mid + 1, right-1);

}


//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
bool verifyPostorder(vector<int>& postorder) {
	if (postorder.empty())
		return true;

	return verifyPostorderChild(postorder, 0, postorder.size() - 1);

}

void test1_1(){
	vector<int> v1 = { 1, 3, 2, 6, 5 };
	//输出true
	cout << verifyPostorder(v1) << endl;

	vector<int> v2 = { 1, 6, 3, 2, 5 };
	//输出false
	cout << verifyPostorder(v2) << endl;
}