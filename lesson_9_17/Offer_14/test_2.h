#pragma once
#include <iostream>
#include <vector>

using namespace std;

//ͳ��һ�����������������г��ֵĴ���
int search(vector<int>& nums, int target) {
	if (nums.empty())
		return 0;

	int left = 0;
	int right = nums.size() - 1;
	//���ֲ��ң�����߽�
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

	//���ұ߽�
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

	return end - begin + 1;  //��ͬԪ�ظ���

}

void test2_1(){
	vector<int> nums = { 5, 7, 7, 8, 8, 10 }; 
	int target = 8;  
	cout << search(nums, target) << endl; //���2

}