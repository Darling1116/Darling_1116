#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

//������left-right�ϵ������Ƿ���ĳ�����������ĺ���������
bool verifyPostorderChild(vector<int>& postorder, int left, int right){
	if (left >= right)
		return true;

	int p = left;
	while (p < right && postorder[p] < postorder[right]){
		p++;
	}
	int mid = p - 1;  //����������

	while (p < right && postorder[p] > postorder[right]){
		p++;
	}

	return  p == right && verifyPostorderChild(postorder, left, mid)
		&& verifyPostorderChild(postorder, mid + 1, right-1);

}


//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ���������
bool verifyPostorder(vector<int>& postorder) {
	if (postorder.empty())
		return true;

	return verifyPostorderChild(postorder, 0, postorder.size() - 1);

}

void test1_1(){
	vector<int> v1 = { 1, 3, 2, 6, 5 };
	//���true
	cout << verifyPostorder(v1) << endl;

	vector<int> v2 = { 1, 6, 3, 2, 5 };
	//���false
	cout << verifyPostorder(v2) << endl;
}