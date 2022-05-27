#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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

	pair<node*, bool> insert(const pair<K, V>& kv){
		if (_root == nullptr){
			_root = new node(kv);
			_root->_color = black;  //根结点是黑色的
			return make_pair(_root, true);
		}

		//找待插入结点的位置
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
		//找到了待插入结点的位置:插入新结点
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

		//控制该树的性质，使其满足红黑树的要求
		//1. 若parent为黑色，不需要处理，插入完成
		if (parent->_color == black)
			return make_pair(cur, true);
		
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
		return make_pair(newnode, true);
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

	void _inorder(node* root){
		if (root == nullptr)
			return;
		_inorder(root->_left);
		cout << root->_kv.first << ": " << root->_kv.second << endl;
		_inorder(root->_right);
	}

	void inorder(){
		_inorder(_root);
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


void test_1(){
	BRTree<int, int> t;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto&e : arr){
		t.insert(make_pair(e, e));
	}
	t.inorder();
}