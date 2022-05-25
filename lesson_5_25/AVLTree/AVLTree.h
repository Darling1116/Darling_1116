#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>

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

			////3.�Ե����ϸ���ƽ������
			//while (cur != _root){
			//	//3.1�ȸ���parent��ƽ������
			//	if (cur == parent->_left)
			//		parent->_bf--;  
			//	else{
			//		parent->_bf++;
			//	}

			//	//3.2�ж��Ƿ���Ҫ�������ϸ���
			//	if (parent->_bf == 0){
			//		break;
			//	}
			//	else if (parent->_bf == 1 || parent->_bf == -1){
			//		//�������ϸ���
			//		cur = parent;
			//		parent = parent->_parent;
			//	}
			//	else if (parent->_bf == 2 || parent->_bf == -2){
			//		//parent���������Ѿ���ƽ�⣬��Ҫ��ת����
			//		if (parent->_bf == -2 && cur->_bf == -1){
			//			//�ҵ���
			//			RotateR(parent);
			//		}
			//		else if (parent->_bf == 2 && cur->_bf == 1){
			//			//����
			//			RotateL(parent);
			//		}
			//		else if (parent->_bf == -2 && cur->_bf == 1){
			//			//����˫��
			//			RotateLR(parent);
			//		}
			//		else{  //(parent->_bf == 2 && cur->_bf == -1)
			//			//����˫��
			//			RotateRL(parent);
			//		}
			//		break;  //��ת���֮������ѭ��
			//	}
			//	else{  
			//		//ƽ�������Ѿ������˴���
			//		assert(false);
			//	}
			//}

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
					subL->_parent = parentparent;
				}
				else{
					parentparent->_right = subL;
					subL->_parent = parentparent;
				}
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
				subR = _root;
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
			if (_root == nullptr)
				return nullptr;
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

	//find��hight��isBalance
	void test_2(){
		AVLTree<int, int> t;
	    typedef AVLTreeNode<int, int> node;
		int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		for (auto &e : arr){
			t.insert(make_pair(e, e));
		}
		t.inorder();

		/*node* tnode = t.find(5);
		cout << tnode->_kv.first << ": " << tnode->_kv.second << endl;*/
	}
};