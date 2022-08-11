#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

//数组中有一个数字出现的次数超过数组长度的一半,请找出这个数字
//方法1：利用map
void test1_1(){
	vector<int> v1 = {1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int half = v1.size() / 2;

	unordered_map<int, int> map;
	for (auto e : v1){
		map[e]++;
		if (map[e] > half){
			printf("%d\n", e);
			break;
		}
	}

}


//方法2：利用sort排序
void test1_2(){
	vector<int> v1 = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	sort(v1.begin(), v1.end());
	int half = v1.size() / 2;
	printf("%d\n", v1[half]);
}



//方法3：使用不同的数字进行抵消的方式
void test1_3(){
	vector<int> v1 = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int count = 0;
	int ret = 0;
	for (auto e : v1){
		if (count == 0){
			ret = e;
			count++;
		}
		else{
			if (ret == e){
				count++;
			}
			else{
				count--;
			}
		}
	}
	printf("%d\n", ret);
}