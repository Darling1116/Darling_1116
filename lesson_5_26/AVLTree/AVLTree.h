#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;

namespace GXR{
	//以三叉链表的方式实现AVL树的结点
	template<class K, class V>
	struct AVLTreeNode{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		int _bf;  //平衡因子
		pair<K, V> _kv;  //数据

		AVLTreeNode(const pair<K, V>& kv)
			:_left(nullptr),
			_right(nullptr),
			_parent(nullptr),
			_bf(0),
			_kv(kv){
		}
	};

	
	template<class K, class V>
	class AVLTree{
	public:
		typedef AVLTreeNode<K, V> node;
		AVLTree()
			:_root(nullptr){
		}

		node* _copy(node* root){
			if (root == nullptr)
				return nullptr;
			node* copyroot = new node(root->_kv);
			copyroot->_left = _copy(root->_left);
			copyroot->_right = _copy(root->_right);
			return copyroot;
		}

		AVLTree(const AVLTree<K, V>& t){
			_root = _copy(t._root);
		}

		AVLTree<K, V>& operator = (AVLTree<K, V> t){
			swap(_root, t._root);
			return *this;
		}

		//重载operator[ ]去访问修改value值(通过key值找到对应的value值)
		V& operator[](const K& key){
			pair<node*, bool> ret = insert_1(make_pair(key, V()));
			return ret.first->_kv.second;
		}

		pair<node*, bool> insert_1(const pair<K, V>& kv){
			if (_root == nullptr){
				_root = new node(kv);
				return make_pair(_root, true);
			}

			//1.先找到要插入的位置
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
				else{  //碰到了相等的结点数据，无法插入
					return make_pair(cur, true);
				}
			}//cur为空，找到了待插入位置

			//2.构造kv结点，插入结点到AVL树中
			cur = new node(kv);
			if (kv.first < parent->_kv.first){
				parent->_left = cur;
				cur->_parent = parent;
			}
			else{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//3.自底向上更新平衡因子
			while (cur != _root){
				//3.1先更新parent的平衡因子
				if (cur == parent->_left)
					parent->_bf--;
				else{
					parent->_bf++;
				}

				//3.2判断是否需要继续向上更新
				if (parent->_bf == 0){
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1){
					//继续向上更新
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2){
					//parent所在子树已经不平衡，需要旋转处理
					if (parent->_bf == -2){
						if (cur->_bf == -1)
							//右单旋
							RotateR(parent);
						else
							RotateLR(parent);
					}
					else{
						if (cur->_bf == 1)
							//左单旋
							RotateL(parent);
						else
							RotateRL(parent);
					}
					break;  //旋转完成之后跳出循环
				}
				else{
					//平衡因子已经出现了错误
					assert(false);
				}
			}

			return make_pair(cur, true);  //插入成功

		}


		bool insert(const pair<K, V>& kv){
			if (_root == nullptr){
				_root = new node(kv);
				return true;
			}

			//1.先找到要插入的位置
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
				else{  //碰到了相等的结点数据，无法插入
					return false;
				}
			}//cur为空，找到了待插入位置
			  
			//2.构造kv结点，插入结点到AVL树中
			cur = new node(kv);
			if (kv.first < parent->_kv.first){
				parent->_left = cur;
				cur->_parent = parent;
			}
			else{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//3.自底向上更新平衡因子
			while (cur != _root){
				//3.1先更新parent的平衡因子
				if (cur == parent->_left)
					parent->_bf--;  
				else{
					parent->_bf++;
				}

				//3.2判断是否需要继续向上更新
				if (parent->_bf == 0){
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1){
					//继续向上更新
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2){
					//parent所在子树已经不平衡，需要旋转处理
					if (parent->_bf == -2){
						if (cur->_bf == -1)
							//右单旋
							RotateR(parent);
						else
							RotateLR(parent);
					}
					else{
						if (cur->_bf == 1)
							//左单旋
							RotateL(parent);
						else
							RotateRL(parent);
					}
					break;  //旋转完成之后跳出循环
				}
				else{  
					//平衡因子已经出现了错误
					assert(false);
				}
			}

			return true;  //插入成功
			
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

			parent->_bf = 0;
			subL->_bf = 0;

			if (parent == _root){
				_root = subL;
				_root->_parent = nullptr;
			}
			else{
				if (parent == parentparent->_left){
					parentparent->_left = subL;
				}
				else{
					parentparent->_right = subL;
				}
				subL->_parent = parentparent;
			}

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

			parent->_bf = 0;
			subR->_bf = 0;

			if (parent == _root){
				_root = subR;
				_root->_parent = nullptr;
			}
			else{
				if (parent == parentparent->_left){
					parentparent->_left = subR;
				}
				else{
					parentparent->_right = subR;
				}
				subR->_parent = parentparent;
			}

		}

		//左右双旋
		void RotateLR(node* parent){
			node* subL = parent->_left;
			node* subLR = subL->_right;

			int bf = subLR->_bf;  //旋转之前保留subLR的平衡因子的值

			RotateL(parent->_left);
			RotateR(parent);

			if (bf == 1){  
				parent->_bf = 0;
				subL->_bf = -1;
				subLR->_bf = 0;
			}
			else if (bf == -1){
				parent->_bf = 1;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else if (bf == 0){
				parent->_bf = 0;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else{
				assert(false);
			}
		}

		//右左双旋
		void RotateRL(node* parent){
			node* subR = parent->_right;
			node* subRL = subR->_left;

			int bf = subRL->_bf;

			RotateR(parent->_right);
			RotateL(parent);

			if (bf == 1){
				parent->_bf = 0;
				subR->_bf = -1;
				subRL->_bf = 0;
			}
			else if (bf == -1){
				parent->_bf = 1;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
			else if (bf == 0){
				parent->_bf = 0;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
			else{
				assert(false);
			}
		}


		node* find(const K& key){
			node* cur = _root;
			while (cur != nullptr){
				if (key == cur->_kv.first)
					return cur;
				else if (key < cur->_kv.first)
					cur = cur->_left;
				else
					cur = cur->_right;
			}
			return nullptr;
		}

		int _hight(node* root){
			if (root == nullptr)
				return 0;
			int left_hignt = _hight(root->_left);
			int right_hight = _hight(root->_right);
			return left_hignt > right_hight ? left_hignt + 1 : right_hight + 1;
		}

		int hight(){
			return _hight(_root);
		}

		bool _isBalance(node* root){
			if (root == nullptr)
				return true;
			int left_hight = _hight(root->_left);
			int right_hight = _hight(root->_right);
			if (right_hight - left_hight != root->_bf)
				cout << "error..." << endl;
			return abs(right_hight - left_hight) < 2 && _isBalance(root->_left) && _isBalance(root->_right);
		}

		bool isBalance(){
			return _isBalance(_root);
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

		//销毁结点的顺序：左子树--右子树--根结点
		void destory(node* root){
			if (root == nullptr)
				return;
			destory(root->_left);
			destory(root->_right);
			delete root;
		}

		~AVLTree(){
			destory(_root);
			_root = nullptr;
		}

	private:
		node* _root;
	};

	//Insert、inorder
	void test_1(){
		AVLTree<int, int> t;
		t.insert(make_pair(4, 2));
		t.insert(make_pair(5, 2));
		t.insert(make_pair(1, 2));
		t.insert(make_pair(2, 2));
		t.insert(make_pair(3, 2)); 
		t.insert(make_pair(6, 2));
		t.insert(make_pair(9, 2));
		t.inorder();
	}

	//Insert、find
	void test_2(){
		AVLTree<int, int> t;
	    typedef AVLTreeNode<int, int> node;
		int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		for (auto &e : arr){
			t.insert(make_pair(e, e));
		}
		t.inorder();

		node* tnode = t.find(11);
		if (tnode == nullptr)
			cout << "没找到..." << endl;
		else
			cout << "找到啦---" << tnode->_kv.first << ": " << tnode->_kv.second << endl;
	}

	//hight、isBalance
	void test_3(){
		AVLTree<int, int> t;
		typedef AVLTreeNode<int, int> node;
		int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		for (auto &e : arr){
			t.insert(make_pair(e, e));
		}
		t.inorder();

		cout << "树的高度为：" << t.hight() << endl;
		cout << "是否平衡：" << t.isBalance() << endl;
	}

	//拷贝构造、赋值重载
	void test_4(){
		AVLTree<int, int> t;
		typedef AVLTreeNode<int, int> node;
		int arr[] = { 16, 3, 7, 11, 9};
		for (auto &e : arr){
			t.insert(make_pair(e, e));
		}
		t.inorder();

		//AVLTree<int, int> t1(t);
		//t1.inorder();

		AVLTree<int, int> t2;
		t2.insert(make_pair(1, 0));
		t2.insert(make_pair(2, 0));
		t2.insert(make_pair(3, 0));
		t2.inorder();

		t2 = t;
		t2.inorder();
	}

	//operator=
	void test_5(){
		AVLTree<int, int> t;
		typedef AVLTreeNode<int, int> node;
		int arr[] = { 16, 3, 7, 11, 9 };
		for (auto &e : arr){
			t.insert(make_pair(e, e));
		}
		t.inorder();
		t[3] *= 10;
		t[7] *= 10;
		t.inorder();
	}
};