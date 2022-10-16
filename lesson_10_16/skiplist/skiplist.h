#include <iostream>
#include <vector>
#include <time.h>

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
		srand(time(0));
		_head = new Node(-1, 1);  //初始时，头结点为1层
	}

	bool search(int target) {
		size_t level = _head->_nextv.size()-1;  //level表示层数的下标
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


	//根据_p生成随机层数
	int randomLevel(){
		int level = 1;
		while (rand() < RAND_MAX*_p && level < _maxlevel){
			level++;
		}
		return level;
	}

	//找num结点每一层的前一个结点
	vector<Node*> findPrevV(int num){
		int level = _head->_nextv.size() - 1;
		Node* cur = _head;

		vector<Node*> prevV(level + 1, _head); //初始其每层前一个结点都为_head

		while (level >= 0){
			if (cur->_nextv[level] != nullptr && num > cur->_nextv[level]->_data){
				cur = cur->_nextv[level];
			}
			else if (cur->_nextv[level] == nullptr || num <= cur->_nextv[level]->_data){
				//向下走，当前结点为待插入结点当前层的前一个结点
				prevV[level] = cur;
				--level;
			}
		}
		return prevV;
	}


	void add(int num) {
		//1.记录待插入结点每一层的前一个结点
		vector<Node*> prevV = findPrevV(num);

		//2.插入结点
		int n = randomLevel();
		Node* newnode = new Node(num, n);
		//若待插入结点的层数大于头结点的层数，升高_head及prevV数组的层数
		if (n > _head->_nextv.size()){
			_head->_nextv.resize(n, nullptr);
			prevV.resize(n, _head);  //高出层数的前一个结点都为_head
		}
		//从下到上连接新结点的前后结点到跳表中
		for (size_t i = 0; i < n; i++){
			newnode->_nextv[i] = prevV[i]->_nextv[i];
			prevV[i]->_nextv[i] = newnode;
		}
	}


	bool erase(int num) {
		//1.先找到待删除结点每一层的前一个结点
		vector<Node*> prevV = findPrevV(num);
		
		//若num结点的第0层的前一个结点的下一个结点为空或其值不为num
		//说明num结点不在跳表中
		if (prevV[0]->_nextv[0] == nullptr || prevV[0]->_nextv[0]->_data != num){
			return false;
		}
		//2.删除num结点
		else{
			Node* delnode = prevV[0]->_nextv[0];
			for (int i = 0; i < delnode->_nextv.size(); i++){
				prevV[i]->_nextv[i] = delnode->_nextv[i];
			}
			delete delnode;
			return true;
		}
	}


	void print(){
		int level = _head->_nextv.size() - 1;
		for (int i = level; i >= 0; i--){
			Node* cur = _head->_nextv[i];
			while (cur){
				cout << cur->_data << " ";
				cur = cur->_nextv[i];
			}
			cout << endl;
		}
	}

private:
	Node* _head;  //头结点
	size_t _maxlevel = 10;  //跳表的最大层数
	double _p = 0.25;  //多增加一层的概率
};


void test(){
	int arr[] = { 30, 40, 50, 60, 70, 90 };
	Skiplist<int> splist;
	for (auto e : arr){
		splist.add(e);
	}
	splist.print();
	//splist.add(25);
	//splist.print();
	splist.erase(60);
	splist.print();
}