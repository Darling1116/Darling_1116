#pragma once
#include <iostream>
#include <vector>

using namespace std;

//统计一个数字在排序数组中出现的次数
int search(vector<int>& nums, int target) {
	if (nums.empty())
		return 0;

	int left = 0;
	int right = nums.size() - 1;
	//二分查找：找左边界
	while (left < right){
		int mid = (left + right) / 2;
		if (nums[mid] >= target){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	
	if (nums[left] != target)
		return 0;

	int begin = left;

	//找右边界
	left = 0;
	right = nums.size() - 1;
	while (left < right){
		int mid = (left + right + 1) / 2;
		if (nums[mid] <= target){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}

	int end = left;

	return end - begin + 1;  //相同元素个数

}

void test2_1(){
	vector<int> nums = { 5, 7, 7, 8, 8, 10 }; 
	int target = 8;  
	cout << search(nums, target) << endl; //输出2

}