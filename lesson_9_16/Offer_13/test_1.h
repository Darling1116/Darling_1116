#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
//从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度
int lengthOfLongestSubstring(string s) {
	if (s.size() == 0)
		return 0;
	
	set<char> set;
	int max_len = 0;

	for (int i = 0; i < s.length(); i++){
		set.clear();
		for (int j = i; j < s.length(); j++){
			if (set.find(s[j]) == set.end()){
				set.insert(s[j]);
			}
			else{
				if (set.size() > max_len){
					max_len = set.size();
					break;
				}
			}
		}
	}

	return max_len;

}


void test1_1(){
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	cout << lengthOfLongestSubstring("pwwkew") << endl;

}