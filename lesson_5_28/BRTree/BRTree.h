#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

enum Colors{
	red,
	black
};

template <class K, class V>
struct BRTreeNode{
	BRTreeNode<K, V>* _left;
	BRTreeNode<K, V>* _right;
	BRTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colors _color;

	BRTreeNode(const pair<K, V>& kv, Colors color = red)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_kv(kv),
		_color(color){

	}
};

template <class K, class V>
class BRTree{
public:
	typedef BRTreeNode<K, V> node;

	BRTree()
		:_root(nullptr){

	}

	node* _copy(const node* root){
		if (root == nullptr)
			return nullptr;
		node* copyroot = new node(root->_kv);
		copyroot->_left = _copy(root->_left);
		copyroot->_right = _copy(root->_right);
		return copyroot;
	}

	BRTree(BRTree<K, V>& t){
		_root = _copy(t._root);
	}

	BRTree<K, V>& operator=(BRTree<K, V> t){
		swap(_root, t._root);
		return *this;
	}

	pair<node*, bool> insert(const pair<K, V>& kv){
		if (_root == nullptr){
			_root = new node(kv);
			_root->_color = black;  //������Ǻ�ɫ��
			return make_pair(_root, true);
		}

		//�Ҵ��������λ��
		node* parent = nullptr;
		node* cur = _root;
		while (cur != nullptr){
			if (kv.first < cur->_kv.first){
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first){
				parent = cur;
				cur = cur->_right;
			}
			else{
				return make_pair(cur, true);
			}
		}
		//�ҵ��˴��������λ��:�����½��
		node* newnode = new node(kv);
		cur = newnode;
		if (cur->_kv.first < parent->_kv.first){
			parent->_left = cur;
			cur->_parent = parent;
		}
		else{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//���Ƹ��������ʣ�ʹ������������Ҫ��
		//1. ��parentΪ��ɫ������Ҫ�����������
		if (parent->_color == black)
			return make_pair(cur, true);
		
		//2. parnetΪ��ɫ����Ҫ��������д���
		while (parent && parent->_color == red){  //parnetΪ��,һ����grandparent���
			node* grandparent = parent->_parent;

			if (parent == grandparent->_left){  //parent�����
				node* uncle = grandparent->_right;
				//���1��uncleΪred
				if (uncle && uncle->_color == red){  
					parent->_color = black;
					uncle->_color = black;
					grandparent->_color = red;
					//�������ϴ���
					cur = grandparent;
					parent = cur->_parent;
				}
				else{  //���2��uncle�����ڻ�uncleΪblack
					if (cur == parent->_left){  //�ҵ���
						RotateR(grandparent);
						parent->_color = black;
						grandparent->_color = red;
					}
					else{  //���������ҵ���
						RotateL(parent);
						RotateR(grandparent);
						cur->_color = black;
						grandparent->_color = red;
					}
					break;  //���2����Ҫ�ټ������ϴ�����Ϊ��ת���µ�"�����"���Ǻ�ɫ��
				}
			}
			else{  //parent���ұ�
				node* uncle = grandparent->_left;
				if (uncle && uncle->_color == red){
					parent->_color = black;
					uncle->_color = black;
					grandparent->_color = red;
					//�������ϴ���
					cur = grandparent;
					parent = cur->_parent;
				}
				else{
					if (cur == parent->_right){
						RotateL(grandparent);
						parent->_color = black;
						grandparent->_color = red;
					}
					else{
						RotateR(parent);
						RotateL(grandparent);
						cur->_color = black;
						grandparent->_color = red;
					}
					break;
				}
			}
		}
		//��������Ϊ��ɫ
		_root->_color = black;
		return make_pair(newnode, true);
	}

	//����
	void RotateL(node* parent){
		node* subR = parent->_right;
		node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr){
			subRL->_parent = parent;
		}
		subR->_left = parent;
		node* parentparent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root){
			_root = subR;
			_root->_parent = nullptr;
		}
		else{
			if (parent == parentparent->_left){
				parentparent->_left = subR;
				subR->_parent = parentparent;
			}
			else{
				parentparent->_right = subR;
				subR->_parent = parentparent;
			}
		}
	}

	//�ҵ���
	void RotateR(node* parent){
		node* subL = parent->_left;
		node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr){
			subLR->_parent = parent;
		}
		subL->_right = parent;
		node* parentparent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root){
			_root = subL;
			_root->_parent = nullptr;
		}
		else{
			if (parent == parentparent->_left){
				parentparent->_left = subL;
				subL->_parent = parentparent;
			}
			else{
				parentparent->_right = subL;
				subL->_parent = parentparent;
			}
		}
	}

	bool isBalance(){
		if (_root == nullptr)
			return true;
		//��֤����2
		if (_root->_color != black){
			cout << "����㲻�Ǻ�ɫ" << endl;
			return false;
		}
		//������˵�·��Ϊ���գ��������ɫ������Ŀ
		node* cur = _root;
		int blacknum = 0;
		while (cur != nullptr){
			if (cur->_color == black)
				blacknum++;
			cur = cur->_left;
		}
		//ʹ���Ӻ�����֤����3��4
		int count = 0;
		return _isBalance(_root, blacknum, count);
	}

	bool _isBalance(node* root, int blackNum, int count){
		if (root == nullptr){
			if (count != blackNum){
				cout << "��·����ɫ������Ŀ�����" << endl;
				return false;
			}
			return true;
		}
		
		//��֤����2�����Լ��븸������ɫ�Ƚϣ����Ƿ�Ϊ��ɫ��
		node* parent = root->_parent;
		if (root->_color == red && parent->_color == red)
			return false;

		if (root->_color == black)
			count++;

		return _isBalance(root->_left, blackNum, count) &&
			_isBalance(root->_right, blackNum, count);
	}

	node* find(const K& key){
		if (_root == nullptr)
			return nullptr;
		node* cur = _root;
		while (cur != nullptr){
			if (key < cur->_kv.first)
				cur = cur->_left;
			else if (key > cur->_kv.first)
				cur = cur->_right;
			else
				return cur;
		}
		return false;
	}

	void _inorder(node* root){
		if (root == nullptr)
			return;
		_inorder(root->_left);
		cout << root->_kv.first << ": " << root->_kv.second << "   ";
		_inorder(root->_right);
	}

	void inorder(){
		_inorder(_root);
		cout << endl;
	}

	void destroy(node* root){
		if (root == nullptr)
			return;
		destroy(root->_left);
		destroy(root->_right);
		delete root;
	}

	~BRTree(){
		destroy(_root);
		_root = nullptr;
	}

private:
	node* _root;
};

//insert��inorder
void test_1(){
	BRTree<int, int> t;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto&e : arr){
		t.insert(make_pair(e, e));
	}
	t.inorder();

	//cout << t.find(9)->_kv.first << endl;
}

//isBalance
void test_2(){
	BRTree<int, int> t;
	srand(time(0));
	int n = 100000;
	for (int i = 0; i < n; i++){
		t.insert(make_pair(i, i));
	}
	//t.inorder();
	cout << t.isBalance() << endl;
}

//�������졢��ֵ����
void test_3(){
	BRTree<int, int> t;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto&e : arr){
		t.insert(make_pair(e, 0));
	}
	t.inorder();

	//BRTree<int, int> t1(t);
	//t1.inorder();
	BRTree<int, int> t2;
	t2.insert(make_pair(100, 100));
	t2.inorder();

	t2 = t;
	t2.inorder();
}