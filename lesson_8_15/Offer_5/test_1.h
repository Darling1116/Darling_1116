#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

//×Ö·û´®µÄÈ«ÅÅÁÐ

void swap(string& str, int a, int b){
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
}


void PermutationChild(string str, size_t start, vector<string>& result){
	if (str.empty() || start < 0 || start >= str.length())
		return;
	if (start == str.length() - 1){
		if (find(result.begin(), result.end(), str) == result.end()){
			result.push_back(str);
		}
		return;
	}
	
	for (int i = start; i < str.length(); i++){
		swap(str, i, start);
		PermutationChild(str, start + 1, result);
		swap(str, i, start);
	}
}



vector<string> Permutation(string str){
	vector<string> result;
	if (str.empty())
		return result;
	PermutationChild(str, 0, result);
	sort(result.begin(), result.end());
	return result;
}

void test1_1(){
	string str = "abcdfg";
	vector<string> result =  Permutation(str);
	for (auto e : result){
		cout << e.c_str() << " ";
	}
}