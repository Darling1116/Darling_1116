#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct SkiplistNode{
	T _data;
	vector<SkiplistNode*> _nextv;

	SkiplistNode(T data, int level)
		:_data(data),
		_nextv(level, nullptr){
	}
};

template <class T>
class Skiplist{
public:
	typedef SkiplistNode<T> Node;

	Skiplist() {
		_head = new Node(-1, 1);  //初始时，头结点为1层
	}

	bool search(int target) {
		int level = _head->_nextv.size()-1;  //level表示层数的下标
		Node* cur = _head;
		while (level >= 0){
			if (cur->_nextv[level] != nullptr && target > cur->_nextv[level]->_data){
				//target大于当前层下一个不为空的结点，向右走
				cur = cur->_nextv[level];
			}
			else if (cur->_nextv[level] == nullptr || target < cur->_nextv[level]->_data){
				//target小于当前层下一个结点或下一个结点为空，向下走
				level--;
			}
			else
				return true;
		}
		return false;
	}

	void add(int num) {

	}

	bool erase(int num) {

	}

private:
	Node* _head;  //头结点
	int _maxlevel = 10;  //跳表的最大层数
	float _p = 0.25;  //多增加一层的概率
};


void test(){

}