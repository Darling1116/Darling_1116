#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <unordered_set>


using namespace std;

//给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列
//使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）
bool wordBreak(string s, unordered_set<string> &dict) {
	if (s.empty())
		return true;  //空字符串也符合要求

	//array表示前i个字符串能否被分割
	vector<bool> array(s.length() + 1, false);  
	array[0] = true;

	for (int i = 1; i <= s.length(); i++){
		for (int j = 0; j < i; j++){
			//前j个字符可以被分割，j-i区间中的字符能在dict中找到
			if (array[j] && (dict.find(s.substr(j, i - j)) != dict.end())){
				array[i] = true;
				break;
			}
		}
	}

	return array[s.length()];

}


void test1_1(){
	string s = "nowcode";
	unordered_set<string> dict = {"now", "code"};
	cout << wordBreak(s, dict) << endl;
}