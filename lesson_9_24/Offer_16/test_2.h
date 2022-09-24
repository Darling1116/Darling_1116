#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//�˿����е�˳�ӣ��ж�5���˿����Ƿ�������0�ɱ�ʾ������
bool isStraight_1(vector<int>& nums) {
	//����һ��set+����
	if (nums.size() != 5)
		return false;

	unordered_set<int> set;
	int max_num = INT_MIN;
	int min_num = INT_MAX;

	for (int i = 0; i < nums.size(); i++){
		if (nums[i] == 0){
			continue;
		}
		//�÷�0Ԫ�ؽ���set��Ȼ���ж����ֵ����Сֵ֮���Ƿ�С��5
		if (set.find(nums[i]) == set.end()){
			set.insert(nums[i]);
			max_num = max(max_num, nums[i]);
			min_num = min(min_num, nums[i]);
		}
		else  //����0���⣬���������ظ�Ԫ��
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
	//������������+��������
	if (nums.size() != 5)
		return false;

	sort(nums.begin(), nums.end());
	
	int count = 0;  //��¼Ԫ��0���ֵĴ���
	for (int i = 0; i < nums.size(); i++){
		if (nums[i] == 0)
			count++;
		else {  //��ǰԪ�ز�Ϊ0��Ҫ�ж��Ƿ�����һ���ظ�
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