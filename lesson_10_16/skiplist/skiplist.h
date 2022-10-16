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
		_head = new Node(-1, 1);  //��ʼʱ��ͷ���Ϊ1��
	}

	bool search(int target) {
		size_t level = _head->_nextv.size()-1;  //level��ʾ�������±�
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


	//����_p�����������
	int randomLevel(){
		int level = 1;
		while (rand() < RAND_MAX*_p && level < _maxlevel){
			level++;
		}
		return level;
	}

	//��num���ÿһ���ǰһ�����
	vector<Node*> findPrevV(int num){
		int level = _head->_nextv.size() - 1;
		Node* cur = _head;

		vector<Node*> prevV(level + 1, _head); //��ʼ��ÿ��ǰһ����㶼Ϊ_head

		while (level >= 0){
			if (cur->_nextv[level] != nullptr && num > cur->_nextv[level]->_data){
				cur = cur->_nextv[level];
			}
			else if (cur->_nextv[level] == nullptr || num <= cur->_nextv[level]->_data){
				//�����ߣ���ǰ���Ϊ�������㵱ǰ���ǰһ�����
				prevV[level] = cur;
				--level;
			}
		}
		return prevV;
	}


	void add(int num) {
		//1.��¼��������ÿһ���ǰһ�����
		vector<Node*> prevV = findPrevV(num);

		//2.������
		int n = randomLevel();
		Node* newnode = new Node(num, n);
		//����������Ĳ�������ͷ���Ĳ���������_head��prevV����Ĳ���
		if (n > _head->_nextv.size()){
			_head->_nextv.resize(n, nullptr);
			prevV.resize(n, _head);  //�߳�������ǰһ����㶼Ϊ_head
		}
		//���µ��������½���ǰ���㵽������
		for (size_t i = 0; i < n; i++){
			newnode->_nextv[i] = prevV[i]->_nextv[i];
			prevV[i]->_nextv[i] = newnode;
		}
	}


	bool erase(int num) {
		//1.���ҵ���ɾ�����ÿһ���ǰһ�����
		vector<Node*> prevV = findPrevV(num);
		
		//��num���ĵ�0���ǰһ��������һ�����Ϊ�ջ���ֵ��Ϊnum
		//˵��num��㲻��������
		if (prevV[0]->_nextv[0] == nullptr || prevV[0]->_nextv[0]->_data != num){
			return false;
		}
		//2.ɾ��num���
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
	Node* _head;  //ͷ���
	size_t _maxlevel = 10;  //�����������
	double _p = 0.25;  //������һ��ĸ���
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