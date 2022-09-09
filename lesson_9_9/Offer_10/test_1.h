#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
static bool cmp(pair<int, int>& m, pair<int, int>& n) {
	return m.second > n.second;
}

//出现频率前k高的元素
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> map;
	for (int i = 0; i<nums.size(); i++){
		map[nums[i]]++;
	}

	vector<pair<int, int>> v;
	for (auto &e : map){
		v.push_back(e);
	}

	sort(v.begin(), v.end(), cmp);

	vector<int> res;
	for (int i = 0; i < k; i++){
		res.push_back(v[i].first);
	}
	return res;

}

void test1_1(){
	vector<int> v = { 1, 1, 1, 2, 2, 3 };
	int k = 2;

	vector<int> ret = topKFrequent(v, k);
	for (auto e : ret){
		cout << e << " ";
	}
}