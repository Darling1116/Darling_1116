#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//扑克牌中的顺子：判断5张扑克牌是否连续，0可表示任意牌
bool isStraight_1(vector<int>& nums) {
	//方法一：set+排序
	if (nums.size() != 5)
		return false;

	unordered_set<int> set;
	int max_num = INT_MIN;
	int min_num = INT_MAX;

	for (int i = 0; i < nums.size(); i++){
		if (nums[i] == 0){
			continue;
		}
		//让非0元素进入set，然后判断最大值与最小值之差是否小于5
		if (set.find(nums[i]) == set.end()){
			set.insert(nums[i]);
			max_num = max(max_num, nums[i]);
			min_num = min(min_num, nums[i]);
		}
		else  //除了0以外，不允许有重复元素
			return false;
	}

	return max_num - min_num < 5 ? true : false;
}


void test2_1(){
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	cout << isStraight_1(v1) << endl;

	vector<int> v2 = { 0, 0, 1, 2, 5 };
	cout << isStraight_1(v2) << endl;
}


bool isStraight_2(vector<int>& nums) {
	//方法二：排序+遍历计数
	if (nums.size() != 5)
		return false;

	sort(nums.begin(), nums.end());
	
	int count = 0;  //记录元素0出现的次数
	for (int i = 0; i < nums.size(); i++){
		if (nums[i] == 0)
			count++;
		else {  //当前元素不为0就要判断是否与上一个重复
			if (i >= 1 && nums[i] == nums[i - 1])
				return false;
		}
	}
	return nums[4] - nums[count] < 5 ? true : false;


}


void test2_2(){
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	cout << isStraight_2(v1) << endl;

	vector<int> v2 = { 0, 0, 1, 2, 5 };
	cout << isStraight_2(v2) << endl;
}