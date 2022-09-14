#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//�ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ���
//����set
int lengthOfLongestSubstring(string s) {
	if (s.empty())
		return 0;

	int max_len = 0;
	unordered_set<char> set;
	for (int i = 0; i < s.length(); i++){
		set.clear();
		//ÿһ�δ�i��ʼ�Ҳ��ظ���Ԫ���Ӵ�
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