#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

namespace GXR{
	template <class K, class V>
	struct TreeNode{
		TreeNode<K, V>* _left;
		TreeNode<K, V>* _right;
		K _key;
		V _val;

			TreeNode(const K& key, const V& val){
			_left = nullptr;
			_right = nullptr;
			_key = key;
			_val = val;
		}
	};


	template <class K, class V>
	class BSTree{
		typedef TreeNode<K, V> node;
	public:
		BSTree()
			:_root(nullptr){
		}

		BSTree(const BSTree<K, V>& t){
			_root = _copy(t._root);
		}

		node* _copy(const node* root){
			if (root == nullptr)
				return nullptr;
			node* copyroot = new node(root->_key, root->_val);
			copyroot->_left = _copy(root->_left);
			copyroot->_right = _copy(root->_right);
			return copyroot;
		}

		BSTree<K, V>& operator=(BSTree<K, V> t){
			swap(_root, t._root);
			return *this;
		}

		bool _insertR(node*& root, const K& key, const V& val){
			if (root == nullptr){
				root = new node(key, val);
				return true;
			}
			if (key < root->_key){
				return _insertR(root->_left, key, val);
			}
			else if (key > root->_key){
				return _insertR(root->_right, key, val);
			}
			else{
				return false;
			}
		}

		void insertR(const K& key, const V& val){
			_insertR(this->_root, key, val);
		}

		bool _eraseR(node*& root, const K& key){
			if (root == nullptr)
				return false;
			if (key < root->_key)
				return _eraseR(root->_left, key);
			else if (key > root->_key)
				return _eraseR(root->_right, key);
			else{ //�ý��պ��Ǵ�ɾ�����
				if (root->_left == nullptr){
					node* tmp = root;
					root = root->_right;
					delete tmp;
				}
				else if (root->_right == nullptr){
					node* tmp = root;
					root = root->_left;
					delete tmp;
				}
				else{  //��ǰ�������ҽ�㶼��Ϊ��
					//������������Сֵ��� 
					node* minparent = root;
					node* minnode = root->_right;
					while (minnode->_left){
						minparent = minnode;
						minnode = minnode->_left;
					}
					root->_key = minnode->_key;
					root->_val = minnode->_val;
					if (minparent->_left == minnode){
						minparent->_left = minnode->_right;
					}
					else{
						minparent->_right = minnode->_right;
					}
					delete minnode;
				}
				return true;
			}
		}

		void eraseR(const K& key){
			_eraseR(_root, key);
		}

		node* _findR(node*& root, const K& key){
			if (root == nullptr)
				return nullptr;
			if (key == root->_key)
				return root;
			else if (key < root->_key)
				return _findR(root->_left, key);
			else if (key > root->_key)
				return _findR(root->_right, key);
			else
				return false;
		}

		//void findR(const K& key){
		//	cout << _findR(_root, key)->_key  << ": " << _findR(_root, key)->_val << endl;
		//}

		node* findR(const K& key){
			return _findR(_root, key);
		}

		void _inOrder(node* root){
			if (root == nullptr)
				return;
			_inOrder(root->_left);
			cout << root->_key << ": " << root->_val << endl;
			_inOrder(root->_right);
		}

		void inOrder(){
			_inOrder(this->_root);
		}

		void destroy(node* root){
			if (root == nullptr)
				return;
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}

		~BSTree(){
			destroy(_root);
			_root = nullptr;
		}

	private:
		node* _root;
	};

	//ʵ�ּ򵥵��ֵ�
	void test_1(){
		typedef TreeNode<string, string> node;
		BSTree<string, string> dict;
		dict.insertR("apple", "ƻ��");
		dict.insertR("banana", "�㽶");
		dict.insertR("orange", "����");
		dict.insertR("potato", "������");
		
		/*dict.inOrder();
		cout << endl;*/

		//dict.findR("banana");

		string str;
		while (cin >> str){
			node* ret = dict.findR(str);
			if (ret == nullptr)
				cout << "�ֵ���û�д˵��ʵķ���" << endl;
			else
				cout << "���ķ���Ϊ: " << ret->_val << endl;
		}
	}


	//ͳ��ˮ�����ֵĴ���
	void test_2(){
		typedef TreeNode<string, int> node;
		BSTree<string, int> countTree;

		string arr[] = { "ƻ��", "�㽶", "����", "����", "�㽶", "����", "ƻ��", "�㽶", "����", "����"};
		for (const auto& e : arr){
			node* ret = countTree.findR(e);
			if (ret == nullptr)
				countTree.insertR(e, 1);
			else
				ret->_val++;
		}

		countTree.inOrder();

	}
}