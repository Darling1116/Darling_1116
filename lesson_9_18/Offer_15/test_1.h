#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
//在递增数组中查找两个数，使得它们的和正好是s
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	if (nums.empty())
		return res;

	int left = 0;
	int right = nums.size() - 1;
	int sum = 0;

	//剪枝
	if (nums[nums.size() / 2] >= target)
		right = nums.size() / 2;
	
	while (nums[right] >= target)
		right--;

	while (left < right){
		sum = nums[left] + nums[right];
		if (sum == target){
			res.push_back(nums[left]);
			res.push_back(nums[right]);
			break;
		}
		else if (sum < target){
			left++;
		}
		else{
			right--;
		}

	}
	
	return res;
}

void test1_1(){
	vector<int> nums = { 10, 26, 30, 31, 47, 60 };
	int target = 40;

	for (auto& e : twoSum(nums, target)){
		cout << e << " ";
	}

}