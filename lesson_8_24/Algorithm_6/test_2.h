#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//多机调度问题：优先执行花费时间长的活动
int finish_time(vector<int>& v, int m){
	sort(v.begin(), v.end());  //默认升序

	int n = v.size();  //有n个活动，需要在m个机器上执行

	//记录m台机器各自的工作时间
	vector<int> machines(m, 0);

	if (n <= m){
		return v[n - 1];  //返回花费时间最长的活动
	}
	else{
		for (int i = n - 1; i >= 0; i--){  //n个活动
			int finish = 0;  //0号机器
			int machinetime = machines[finish];  //当前机器的结束时间
			for (int j = 1; j < m; j++){
				if (machines[j] < machinetime){
					finish = j;
					machinetime = machines[finish];
				}
			}
			machines[finish] += v[i];  //让最先完成任务的机器执行当前任务
		}
	}

	//找工作时间最长的机器
	int finishtime = machines[0];
	for (int i = 1; i < m; i++){
		if (machines[i] > finishtime)
			finishtime = machines[i];
	}
	return finishtime;
}


void test2_1(){
	//6个任务，3台机器完成任务所需要的最少时间
	vector<int> v = { 10, 5, 3, 7, 2, 1 };  

	int ret = finish_time(v, 3);
	cout << ret << endl;
	

}