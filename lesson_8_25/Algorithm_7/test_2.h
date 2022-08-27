#pragma once
#include <iostream>
#include <vector>


using namespace std;

//组合总和: candidates中的同一个数字可以无限制重复被选取 

void DFS(vector<int>& candidates, vector<vector<int>>& result, vector<int> curres, int cursum, int prev, int target){
	if (cursum >= target){
		if (cursum == target){
			result.push_back(curres);
		}
		return;
	}

	for (int i = prev; i < candidates.size(); i++){
		curres.push_back(candidates[i]);
		DFS(candidates, result, curres, cursum + candidates[i], i, target);
		curres.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if (candidates.empty()){
		return result;
	}

	vector<int> curres;
	DFS(candidates, result, curres, 0, 0, target);
	return result;

}

void test2_1(){
	vector<int> candidates = { 2, 3, 6, 7 };
	int target = 7;

	vector<vector<int>> result;
	result = combinationSum(candidates, target);

	for (auto e : result){
		for (auto i : e){
			cout << i << ",";
		}
		cout << endl;
	}

	//输出： [[2,2,3],[7]]

}