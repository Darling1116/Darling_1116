#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

//第一次只出现一次的字符
char firstUniqChar(string s) {
	if (s.size() == 0)
		return ' ';

	unordered_map<char, int> map;
	for (int i = 0; i < s.size(); i++){
		map[s[i]]++;
	}

	for (int i = 0; i < s.size(); i++){
		if (map[s[i]] == 1)
			return s[i];
	}
	return ' ';

}

void test1_1(){
	cout << firstUniqChar("abaccdeff") << endl;  //输出:b
}

