#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//实现并查集的相关操作
template <class T>
struct union_find_set_2{
public:

	union_find_set_2(size_t n){
		_array.resize(n, -1);  //n个元素都初始化为-1，表示n棵树
	}

	//查找index下标的元素属于哪个集合
	int findRoot(int index){
		while (_array[index] >= 0){  
			index = _array[index];
		}
		return index;
	}

	//将两个集合合并成一个集合
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

	//查看两个元素是否属于同一个集合
	bool isOneSet(int index1, int index2){
		int root1 = findRoot(index1);
		int root2 = findRoot(index2);
		return root1 == root2;
	}


	//集合的个数
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