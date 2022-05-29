#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <time.h>
#include "reverse_iterator.h"

using namespace std;

enum Colors{
	red,
	black
};

template <class T>
struct BRTreeNode{
	BRTreeNode<T>* _left;
	BRTreeNode<T>* _right;
	BRTreeNode<T>* _parent;
	T _data;
	Colors _color;

	BRTreeNode(const T& data, Colors color = red)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_data(data),
		_color(color){

	}
};

template <class T, class Ref, class Ptr>
struct BRIterator{
	typedef Ref reference;
	typedef Ptr pointer;
	typedef BRTreeNode<T> node;
	typedef BRIterator<T, Ref, Ptr> self;

	node* _pnode;

	BRIterator(node* node)
		:_pnode(node){
	}

	self& operator++(){
		//如果_pnode的右不为空，++就是其右子树的最左端结点
		if (_pnode->_right != nullptr){
			node* cur = _pnode->_right;
			while (cur->_left != nullptr){
				cur = cur->_left;
			}
			_pnode = cur;
		}
		else{//如果_pnode的右为空：若其不是父亲的右孩子，++就是其父结点；否则继续沿着三叉链表向上找
			node* cur = _pnode;
			node* parent = cur->_parent;
			while (parent && parent->_right == cur){
				cur = parent;
				parent = parent->_parent;
			}
			_pnode = parent;
		}
		return *this;
	}

	self& operator--(){
		//如果_pnode的左不为空，++就是其左子树的最右端结点
		if (_pnode->_left != nullptr){
			node* cur = _pnode->_left;
			while (cur->_right != nullptr){
				cur = cur->_right;
			}
			_pnode = cur;
		}
		else{//如果_pnode的左为空：若其不是父亲的左孩子，--就是其父结点；否则继续沿着三叉链表向上找
			node* cur = _pnode;
			node* parent = cur->_parent;
			while (parent && cur == parent->_left){
				cur = parent;
				parent = parent->_parent;
			}
			_pnode = parent;
		}
		return *this;
	}

	Ref operator*(){
		return _pnode->_data;
	}

	Ptr operator->(){
		return &_pnode->_data;
	}

	bool operator!=(const self& s){
		return _pnode != s._pnode;
	}

	bool operator==(const self& s){
		return _pnode == s._pnode;
	}

};


template <class K, class T, class KeyOfT>
class BRTree{
public:
	typedef BRTreeNode<T> node;
	typedef BRIterator<T, T&, T*> iterator;
	typedef BR_ReverseIterator<iterator> reverse_iterator;

	BRTree()
		:_root(nullptr){

	}

	//node* _copy(const node* root){
	//	if (root == nullptr)
	//		return nullptr;
	//	node* copyroot = new node(root->_kv);
	//	copyroot->_left = _copy(root->_left);
	//	copyroot->_right = _copy(root->_right);
	//	return copyroot;
	//}

	//BRTree(BRTree<K, V>& t){
	//	_root = _copy(t._root);
	//}

	/*BRTree<K, V>& operator=(BRTree<K, V> t){
		swap(_root, t._root);
		return *this;
	}*/

	pair<iterator, bool> insert(const T& data){
		if (_root == nullptr){
			_root = new node(data);
			_root->_color = black;  //根结点是黑色的
			return make_pair(iterator(_root), true);
		}

		//找待插入结点的位置
		node* parent = nullptr;
		node* cur = _root;
		KeyOfT kot;
		while (cur != nullptr){
			if (kot(data) < kot(cur->_data)){
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(data) > kot(cur->_data)){
				parent = cur;
				cur = cur->_right;
			}
			else{
				return make_pair(iterator(cur), false);
			}
		}
		//找到了待插入结点的位置:插入新结点
		node* newnode = new node(data);
		cur = newnode;
		if (kot(cur->_data) < kot(parent->_data)){
			parent->_left = cur;
			cur->_parent = parent;
		}
		else{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//控制该树的性质，使其满足红黑树的要求
		//1. 若parent为黑色，不需要处理，插入完成
		if (parent->_color == black)
			return make_pair(iterator(cur), true);

		//2. parnet为红色，需要分情况进行处理
		while (parent && parent->_color == red){  //parnet为红,一定有grandparent结点
			node* grandparent = parent->_parent;

			if (parent == grandparent->_left){  //parent在左边
				node* uncle = grandparent->_right;
				//情况1：uncle为red
				if (uncle && uncle->_color == red){
					parent->_color = black;
					uncle->_color = black;
					grandparent->_color = red;
					//继续向上处理
					cur = grandparent;
					parent = cur->_parent;
				}
				else{  //情况2：uncle不存在或uncle为black
					if (cur == parent->_left){  //右单旋
						RotateR(grandparent);
						parent->_color = black;
						grandparent->_color = red;
					}
					else{  //先左单旋再右单旋
						RotateL(parent);
						RotateR(grandparent);
						cur->_color = black;
						grandparent->_color = red;
					}
					break;  //情况2不需要再继续向上处理，因为旋转后新的"根结点"都是黑色的
				}
			}
			else{  //parent在右边
				node* uncle = grandparent->_left;
				if (uncle && uncle->_color == red){
					parent->_color = black;
					uncle->_color = black;
					grandparent->_color = red;
					//继续向上处理
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
		//处理根结点为黑色
		_root->_color = black;
		return make_pair(iterator(newnode), true);
	}

	//左单旋
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

	//右单旋
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

	//bool isBalance(){
	//	if (_root == nullptr)
	//		return true;
	//	//验证规则2
	//	if (_root->_color != black){
	//		cout << "根结点不是黑色" << endl;
	//		return false;
	//	}
	//	//以最左端的路径为参照，计算其黑色结点的数目
	//	node* cur = _root;
	//	int blacknum = 0;
	//	while (cur != nullptr){
	//		if (cur->_color == black)
	//			blacknum++;
	//		cur = cur->_left;
	//	}
	//	//使用子函数验证规则3、4
	//	int count = 0;
	//	return _isBalance(_root, blacknum, count);
	//}

	//bool _isBalance(node* root, int blackNum, int count){
	//	if (root == nullptr){
	//		if (count != blackNum){
	//			cout << "各路径黑色结点的数目不相等" << endl;
	//			return false;
	//		}
	//		return true;
	//	}

	//	//验证规则2：拿自己与父结点的颜色比较，看是否都为红色的
	//	node* parent = root->_parent;
	//	if (root->_color == red && parent->_color == red)
	//		return false;

	//	if (root->_color == black)
	//		count++;

	//	return _isBalance(root->_left, blackNum, count) &&
	//		_isBalance(root->_right, blackNum, count);
	//}

	node* find(const K& key){
		if (_root == nullptr)
			return nullptr;
		KeyOfT kot;
		node* cur = _root;
		while (cur != nullptr){
			if (key < kot(cur->_data))
				cur = cur->_left;
			else if (key > kot(cur->_data))
				cur = cur->_right;
			else
				return cur;
		}
		return false;
	}

	iterator begin(){
		node* cur = _root;
		while (cur && cur->_left){
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end(){
		return iterator(nullptr);
	}

	reverse_iterator rbegin(){
		node* cur = _root;
		while (cur && cur->_right){
			cur = cur->_right;
		}
		return reverse_iterator(cur);
	}

	reverse_iterator rend(){
		return reverse_iterator(nullptr);
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


