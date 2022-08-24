#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool com(vector<int>& v1, vector<int>& v2){
	return v1[1] < v2[1];  //按活动的最早结束时间排序
}

//活动选择：优先选择结束时间较早的活动
int activity_nums(vector<vector<int>> vv){
	sort(vv.begin(), vv.end(), com);

	int i = 0;  //先执行第一个活动---结束时间最早的活动
	int count = 1;

	for (int j = 1; j < vv.size(); j++){
		if (vv[j][0] >= vv[i][1]){  //保证下一个活动的开始时间大于等于当前活动的结束时间
			count++;
			i = j;  //更新上一个活动
		}
	}

	return count;

}

void test3_1(){
	//记录各个活动的开始和结束时间
	vector<vector<int>> vv = { { 2, 5 }, { 3, 4 }, { 1, 6 }, { 5, 8 }, { 5, 7 }, { 3, 9 }, { 7, 10 } };
	int ret = activity_nums(vv);
	cout << ret << endl;
}