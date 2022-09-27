#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//ʵ�ֲ��鼯����ز���
template <class T>
struct union_find_set_2{
public:

	union_find_set_2(size_t n){
		_array.resize(n, -1);  //n��Ԫ�ض���ʼ��Ϊ-1����ʾn����
	}

	//����index�±��Ԫ�������ĸ�����
	int findRoot(int index){
		while (_array[index] >= 0){  
			index = _array[index];
		}
		return index;
	}

	//���������Ϻϲ���һ������
	void Union(int index1, int index2){
		int root1 = findRoot(index1);
		int root2 = findRoot(index2);
		if (root1 == root2)
			return;
		else{
			_array[root1] += _array[root2];
			_array[root2] = root1;
		}
	}

	//�鿴����Ԫ���Ƿ�����ͬһ������
	bool isOneSet(int index1, int index2){
		int root1 = findRoot(index1);
		int root2 = findRoot(index2);
		return root1 == root2;
	}


	//���ϵĸ���
	size_t setSize(){
		size_t count = 0;
		for (size_t i = 0; i < _array.size(); i++){
			if (_array[i] <= -1){
				count++;
			}
		}
		return count;
	}
private:
	vector<T> _array;
};

void test_2(){
	union_find_set_2<int> ufs(5);
	ufs.Union(1, 2);
	ufs.Union(3, 4);
	cout << ufs.setSize() << endl;
}