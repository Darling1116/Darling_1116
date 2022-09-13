#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//以哪个字符为开始位置进行全排列
void PermutationChild(string str, vector<string>& res, int begin){
	if (str.empty() || begin < 0 || begin >= str.size())
		return;

	//以最后一个字符为起点进行了排列
	if (begin == str.size() - 1){
		res.push_back(str);
		return;
	}


	//出于对时间效率的考虑，利用set，对每次的排列情况进行剪枝
	set<int> set;
	for (int i = begin; i < str.size(); i++){
		if (set.find(str[i]) != set.end()){
			continue;  //当前位置的当前字符已经被使用过
		}
		swap(str[i], str[begin]);
		PermutationChild(str, res, begin + 1);
		swap(str[i], str[begin]);
	}

}


//输入一个字符串，打印出该字符串中字符的所有排列
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