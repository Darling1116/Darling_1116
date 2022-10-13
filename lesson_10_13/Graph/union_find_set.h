#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct UnionFindSet{
public:
	UnionFindSet(size_t n){
		_array.resize(n, -1);
	}

	int findRoot(int index){
		while (_array[index] >= 0){
			index = _array[index];
		}
		return index;
	}

	void Union(int index1, int index2){
		int root1 = findRoot(index1);
		int root2 = findRoot(index2);
		if (root1 != root2){
			if (_array[root1] > _array[root2]){
				swap(root1, root2);
			}
			_array[root1] += _array[root2];
			_array[root2] = root1;
		}
	}

	bool isOneSet(int index1, int index2){
		int root1 = findRoot(index1);
		int root2 = findRoot(index2);
		return root1 == root2;
	}

	size_t setSize(){
		size_t count = 0;
		for (size_t i = 0; i < _array.size(); i++){
			if (_array[i] < 0){
				count++;
			}
		}
		return count;
	}



private:
	vector<T> _array;
};

void test_3(){
	UnionFindSet<int> ufs(4);
	ufs.Union(0, 1);
	ufs.Union(2, 3);
	cout << ufs.isOneSet(1, 2) << endl;
	cout << ufs.isOneSet(0, 1) << endl;
	cout << ufs.setSize() << endl;
}
