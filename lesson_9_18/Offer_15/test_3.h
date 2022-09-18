#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�������ڵ����ֵ
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> res;
	if (nums.empty())
		return res;

	priority_queue<pair<int, int>> pq;  //�ײ��Ƕѣ�Ĭ�Ͻ���
	for (int i = 0; i < k; i++){  //�ѵ�һ�鴰�ڵ����ݷ���pq��
		pq.push(make_pair(nums[i], i));
	}
	res.push_back(pq.top().first);
	
	for (int i = k; i < nums.size(); i++){
		pq.push(make_pair(nums[i], i));
		while (pq.top().second < i - k){
			pq.pop();
		}
		res.push_back(pq.top().first);
	}
	return res;

}

void test3_1(){
	vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int k = 3;

	for (auto&e : maxSlidingWindow(nums, k)){
		cout << e << " ";
	}
}
