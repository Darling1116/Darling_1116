#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//���ĸ��ַ�Ϊ��ʼλ�ý���ȫ����
void PermutationChild(string str, vector<string>& res, int begin){
	if (str.empty() || begin < 0 || begin >= str.size())
		return;

	//�����һ���ַ�Ϊ������������
	if (begin == str.size() - 1){
		res.push_back(str);
		return;
	}


	//���ڶ�ʱ��Ч�ʵĿ��ǣ�����set����ÿ�ε�����������м�֦
	set<int> set;
	for (int i = begin; i < str.size(); i++){
		if (set.find(str[i]) != set.end()){
			continue;  //��ǰλ�õĵ�ǰ�ַ��Ѿ���ʹ�ù�
		}
		swap(str[i], str[begin]);
		PermutationChild(str, res, begin + 1);
		swap(str[i], str[begin]);
	}

}


//����һ���ַ�������ӡ�����ַ������ַ�����������
vector<string> permutation(string s) {
	vector<string> res;
	if (s.empty())
		return res;

	PermutationChild(s, res, 0);
	return res;
}


void test2_1(){
	string s = "abc";
	vector<string> ret = permutation(s);

	for (auto& e : ret){
		cout << e << " ";
	}
}