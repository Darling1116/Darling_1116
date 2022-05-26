#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;

namespace GXR{
	//����������ķ�ʽʵ��AVL���Ľ��
	template<class K, class V>
	struct AVLTreeNode{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		int _bf;  //ƽ������
		pair<K, V> _kv;  //����

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

		//����operator[ ]ȥ�����޸�valueֵ(ͨ��keyֵ�ҵ���Ӧ��valueֵ)
		V& operator[](const K& key){
			pair<node*, bool> ret = insert_1(make_pair(key, V()));
			return ret.first->_kv.second;
		}

		pair<node*, bool> insert_1(const pair<K, V>& kv){
			if (_root == nullptr){
				_root = new node(kv);
				return make_pair(_root, true);
			}

			//1.���ҵ�Ҫ�����λ��
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
				else{  //��������ȵĽ�����ݣ��޷�����
					return make_pair(cur, true);
				}
			}//curΪ�գ��ҵ��˴�����λ��

			//2.����kv��㣬�����㵽AVL����
			cur = new node(kv);
			if (kv.first < parent->_kv.first){
				parent->_left = cur;
				cur->_parent = parent;
			}
			else{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//3.�Ե����ϸ���ƽ������
			while (cur != _root){
				//3.1�ȸ���parent��ƽ������
				if (cur == parent->_left)
					parent->_bf--;
				else{
					parent->_bf++;
				}

				//3.2�ж��Ƿ���Ҫ�������ϸ���
				if (parent->_bf == 0){
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1){
					//�������ϸ���
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2){
					//parent���������Ѿ���ƽ�⣬��Ҫ��ת����
					if (parent->_bf == -2){
						if (cur->_bf == -1)
							//�ҵ���
							RotateR(parent);
						else
							RotateLR(parent);
					}
					else{
						if (cur->_bf == 1)
							//����
							RotateL(parent);
						else
							RotateRL(parent);
					}
					break;  //��ת���֮������ѭ��
				}
				else{
					//ƽ�������Ѿ������˴���
					assert(false);
				}
			}

			return make_pair(cur, true);  //����ɹ�

		}


		bool insert(const pair<K, V>& kv){
			if (_root == nullptr){
				_root = new node(kv);
				return true;
			}

			//1.���ҵ�Ҫ�����λ��
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
				else{  //��������ȵĽ�����ݣ��޷�����
					return false;
				}
			}//curΪ�գ��ҵ��˴�����λ��
			  
			//2.����kv��㣬�����㵽AVL����
			cur = new node(kv);
			if (kv.first < parent->_kv.first){
				parent->_left = cur;
				cur->_parent = parent;
			}
			else{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//3.�Ե����ϸ���ƽ������
			while (cur != _root){
				//3.1�ȸ���parent��ƽ������
				if (cur == parent->_left)
					parent->_bf--;  
				else{
					parent->_bf++;
				}

				//3.2�ж��Ƿ���Ҫ�������ϸ���
				if (parent->_bf == 0){
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1){
					//�������ϸ���
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2){
					//parent���������Ѿ���ƽ�⣬��Ҫ��ת����
					if (parent->_bf == -2){
						if (cur->_bf == -1)
							//�ҵ���
							RotateR(parent);
						else
							RotateLR(parent);
					}
					else{
						if (cur->_bf == 1)
							//����
							RotateL(parent);
						else
							RotateRL(parent);
					}
					break;  //��ת���֮������ѭ��
				}
				else{  
					//ƽ�������Ѿ������˴���
					assert(false);
				}
			}

			return true;  //����ɹ�
			
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

		//����˫��
		void RotateLR(node* parent){
			node* subL = parent->_left;
			node* subLR = subL->_right;

			int bf = subLR->_bf;  //��ת֮ǰ����subLR��ƽ�����ӵ�ֵ

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

		//����˫��
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

		//���ٽ���˳��������--������--�����
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

	//Insert��inorder
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

	//Insert��find
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
			cout << "û�ҵ�..." << endl;
		else
			cout << "�ҵ���---" << tnode->_kv.first << ": " << tnode->_kv.second << endl;
	}

	//hight��isBalance
	void test_3(){
		AVLTree<int, int> t;
		typedef AVLTreeNode<int, int> node;
		int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		for (auto &e : arr){
			t.insert(make_pair(e, e));
		}
		t.inorder();

		cout << "���ĸ߶�Ϊ��" << t.hight() << endl;
		cout << "�Ƿ�ƽ�⣺" << t.isBalance() << endl;
	}

	//�������졢��ֵ����
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