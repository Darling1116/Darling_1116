#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T>
struct UnionFindSet_1{
public:
	UnionFindSet_1(const T* array, size_t n){
		for (size_t i = 0; i < n; i++){
			_array.push_back(array[i]);
			_map[array[i]] = i;
		}
	}


private:
	vector<T> _array;  //存放数据：利用下标找数据
	unordered_map<T, int> _map;  //存放属于与下标之间的映射关系：利用数据找下标
};

void test_1(){
	const string array[] = { "花花", "小草", "大树", "河流" };
	UnionFindSet_1<string> ufs(array, array->size());
}

