#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//分割平衡字符串
int balancedStringSplit(string& s) {
	int count = 0;
	int balabce = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == 'L')
			balabce++;
		else
			balabce--;

		if (balabce == 0){
			count++;
		}
	}

	return count;
}


void test2_1(){
	string s = "RLRRLLRLRL";
	int ret = balancedStringSplit(s);
	cout << ret << endl;
}


//买卖股票的最佳时期:最低点买入，最高点卖出
int maxProfit(vector<int>& prices) {
	int profit = 0;
	for (int i = 1; i < prices.size(); i++){
		if (prices[i] > prices[i - 1])
			profit += prices[i] - prices[i - 1];
	}
	return profit;
}

void test2_2(){
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	int ret = maxProfit(prices);
	cout << ret << endl;
}


//跳跃游戏
bool canJump(vector<int>& nums) {
	int max_path = 0;
	for (int i = 0; i < nums.size(); i++){
		if (max_path >= i){  //如果当前的最大跳跃距离小于i，说明一定跳不过去
			max_path = max(max_path, i + nums[i]);

			if (max_path >= nums.size())
				return true;
		}
		else{
			return false;
		}
	}
	return true;
}

void test2_3(){
	vector<int> nums = { 2, 3, 1, 1, 4 };
	bool ret = canJump(nums);
	cout << ret << endl;
}