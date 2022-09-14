#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度
//利用set
int lengthOfLongestSubstring(string s) {
	if (s.empty())
		return 0;

	int max_len = 0;
	unordered_set<char> set;
	for (int i = 0; i < s.length(); i++){
		set.clear();
		//每一次从i开始找不重复的元素子串
		for (int j = i; j < s.length(); j++){
			if (set.find(s[j]) == set.end()){
				set.insert(s[j]);
			}
			else{
				break;
			}
		}
		if (set.size() > max_len)
			max_len = set.size();
	}

	return max_len;
}


void test3_1(){
	string s1 = "abcabcbb";
	cout << lengthOfLongestSubstring(s1) << endl;
	string s2 = "bbbbb";
	cout << lengthOfLongestSubstring(s2) << endl;
	string s3 = "pwwkew";
	cout << lengthOfLongestSubstring(s3) << endl;
}