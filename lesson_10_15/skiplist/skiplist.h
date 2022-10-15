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
		_head = new Node(-1, 1);  //��ʼʱ��ͷ���Ϊ1��
	}

	bool search(int target) {
		int level = _head->_nextv.size()-1;  //level��ʾ�������±�
		Node* cur = _head;
		while (level >= 0){
			if (cur->_nextv[level] != nullptr && target > cur->_nextv[level]->_data){
				//target���ڵ�ǰ����һ����Ϊ�յĽ�㣬������
				cur = cur->_nextv[level];
			}
			else if (cur->_nextv[level] == nullptr || target < cur->_nextv[level]->_data){
				//targetС�ڵ�ǰ����һ��������һ�����Ϊ�գ�������
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
	Node* _head;  //ͷ���
	int _maxlevel = 10;  //�����������
	float _p = 0.25;  //������һ��ĸ���
};


void test(){

}