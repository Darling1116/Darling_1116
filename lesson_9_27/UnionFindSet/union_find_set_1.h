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
	vector<T> _array;  //������ݣ������±�������
	unordered_map<T, int> _map;  //����������±�֮���ӳ���ϵ�������������±�
};

void test_1(){
	const string array[] = { "����", "С��", "����", "����" };
	UnionFindSet_1<string> ufs(array, array->size());
}

