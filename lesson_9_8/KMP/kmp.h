#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>


using namespace std;

void nextval(string& sub, vector<int>& next){
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k = 0;  //表示前一项的next值
	while(i < sub.length()){
		if (k == -1 || sub[i - 1] == sub[k]){
			next[i] = k + 1;
			i++;
			k++;
		}
		else{
			k = next[k];  //子串回退
		}
	}
}


int kmp(string& str, string& sub, int pos){
	if (str.empty() || sub.empty())
		return -1;
	if (str.length() == 0 || sub.length() == 0)
		return -1;
	if (pos < 0 || pos >= str.length())
		return -1;

	int i = pos;  //遍历主串
	int j = 0;  //遍历子串

	vector<int> next(sub.length(), 0);
	nextval(sub, next);

	while (i < str.length() && j < sub.length()){
		if (j == -1 || str[i] == sub[j]){
			//j回退到了最初位置的前一位
			i++;
			j++;
		}
		else{
			//i指针不回退，j指针回退到一个合适的位置
			j = next[j];
		}
	}
	if (j >= sub.length()){
		return i - j;
	}
	return -1;
}


void test(){
	string str = "ababbaaabcd";
	string sub = "abcd";
	cout << kmp(str, sub, 0) << endl;

}