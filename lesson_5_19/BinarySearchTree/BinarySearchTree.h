#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace GXR_1{

	template <class T>
	struct TreeNode{
		TreeNode<T>* _left;
		TreeNode<T>* _right;
		T _val;

		TreeNode(const T& val){
			_left = nullptr;
			_right = nullptr;
			_val = val;
		}
	};

	
	template <class T>
	class BSTree{
	typedef TreeNode<T> node;
	public:
		BSTree()
			:_root(nullptr){
		}

		BSTree(const BSTree<T>& t){
			_root = _copy(t._root);
		}

		node* _copy(node* root){
			if (root == nullptr)
				return nullptr;
			node* copyroot = new node(root->_val);
			copyroot->_left = _copy(root->_left);
			copyroot->_right = _copy(root->_right);
			return copyroot;
		}

		BSTree<T>& operator=(BSTree<T> t){
			swap(_root, t._root);
			return *this;
		}

		bool insert(const T& val){
			if (_root == nullptr){
				_root = new node(val);
				return true;
			}
			node* parent = nullptr;
			node* cur = _root;
			while (cur != nullptr){
				if (val < cur->_val){
					parent = cur;
					cur = cur->_left;
				}
				else if (val > cur->_val){
					parent = cur;
					cur = cur->_right;
				}
				else{
					return false;
				}
			}
			node* newnode = new node(val);
			if (parent->_val < val){
				parent->_right = newnode;
			}
			else{
				parent->_left = newnode;
			}
			return true;
		}

		void _inOrder(node* root){
			if (root == nullptr)
				return;
			_inOrder(root->_left);
			cout << root->_val << " ";
			_inOrder(root->_right);
		}

		void inOrder(){
			_inOrder(this->_root);
		}

		node* find(const T& val){
			node* cur = _root;
			while (cur != nullptr){
				if (val < cur->_val)
					cur = cur->_left;
				else if (val > cur->_val)
					cur = cur->_right;
				else
					return cur;
			}
			return nullptr;
		}

		bool erase(const T& val){
			//if (_root == nullptr)
			//	return false;
			//1.先找待删除结点的位置
			node* parent = nullptr;
			node* cur = _root;
			while (cur != nullptr){
				if (val < cur->_val){
					parent = cur;
					cur = cur->_left;
				}
				else if (val > cur->_val){
					parent = cur;
					cur = cur->_right;
				}
				else{  //2.找到了待删除结点的位置，删除结点
					//左为空或者右为空，把另一个孩子交给父亲
					if (cur->_left == nullptr){
						if (cur == _root){  //注意待删除结点是根结点的情况
							_root = cur->_right;
						}
						else{
							if (parent->_left == cur){
								parent->_left = cur->_right;
							}
							else{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr){
						if (cur == _root){
							_root = cur->_left;
						}
						else{
							if (parent->_left == cur){
								parent->_left = cur->_left;
							}
							else{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else{ //左右孩子都存不为空：替换删除
						node* minparent = cur;
						node* minnode = cur->_right;
						//先找到右子树的最小结点
						while (minnode->_left != nullptr){  
							minparent = minnode;
							minnode = minnode->_left;
						}
						//替换待删除结点的值，并删除替换结点
						//cur->_val = minnode->_val;
						//if (minparent->_left == minnode){
						//	minparent->_left = minnode->_right;
						//}
						//else{
						//	minparent->_right = minnode->_right;
						//}
						//delete minnode;

						//递归删除替换结点，再替换最小结点的值
						T minval = minnode->_val;
						this->erase(minval);
						cur->_val = minval;

					}
					return true;
				}
			}
			return false;
		}

		void destroy(node*& root){
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


	//insert、inOrder、find、erase
	void test_1(){
		typedef TreeNode<int> node;

		int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };

		BSTree<int> t;
		for (auto e : a){
			t.insert(e);
		}
		t.inOrder();
		cout << endl;

		//node* p = t.find(8);
		//cout << p->_val << endl;

		int b[] = { 8, 2, 6, 0, 9};
		BSTree<int> t2;
		for (auto e : b){
			t2.insert(e);
		}
		t2.inOrder();
		cout << endl;


		//for (auto e : b){
		//	t.erase(e);
		//	t.inOrder();
		//	cout << endl;
		//}

		//BSTree<int> copyt(t);
		//copyt.inOrder();
		//cout << endl;

		t2 = t;
		t2.inOrder();
		cout << endl;
	}

}


// 递归实现insert、erase、find操作
namespace GXR_2{

	template <class T>
	struct TreeNode{
		TreeNode<T>* _left;
		TreeNode<T>* _right;
		T _val;

		TreeNode(const T& val){
			_left = nullptr;
			_right = nullptr;
			_val = val;
		}
	};


	template <class T>
	class BSTree{
		typedef TreeNode<T> node;
	public:
		BSTree()
			:_root(nullptr){
		}

		bool _insertR(node*& root, const T& val){
			if (root == nullptr){
				root = new node(val);
				return true;
			}
			if (val < root->_val){
				return _insertR(root->_left, val);
			}
			else if (val > root->_val){
				return _insertR(root->_right, val);
			}
			else{
				return false;
			}
		}

		void insertR(const T& val){
			_insertR(this->_root, val);
		}


		bool _eraseR(node*& root, const T& val){
			if (root == nullptr)
				return false;
			if (val < root->_val)
				return _eraseR(root->_left, val);
			else if (val > root->_val)
				return _eraseR(root->_right, val);
			else{ //该结点刚好是待删除结点
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
				else{  //当前结点的左右结点都不为空
					//找右子树的最小值结点 
					node* minparent = root;
					node* minnode = root->_right;
					while (minnode->_left){
						minparent = minnode;
						minnode = minnode->_left;
					}
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

		void eraseR(const T& val){
			_eraseR(_root, val);
		}

		node* _findR(node*& root, const T& val){
			if (root == nullptr)
				return nullptr;
			if (val == root->_val)
				return root;
			else if (val < root->_val)
				return _findR(root->_left, val);
			else if (val > root->_val)
				return _findR(root->_right, val);
			else
				return false;
		}

		void findR(const T& val){
			cout << _findR(_root, val)->_val << endl;
		}

		void _inOrder(node* root){
			if (root == nullptr)
				return;
			_inOrder(root->_left);
			cout << root->_val << " ";
			_inOrder(root->_right);
		}

		void inOrder(){
			_inOrder(this->_root);
		}
		
	private:
		node* _root;
	};

	void test_2(){
		typedef TreeNode<int> node;

		int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
		
		BSTree<int> t;
		for (auto& e : a){
			t.insertR(e);
		}
		t.inOrder();
		cout << endl;

		//t.eraseR(5);
		//t.inOrder();
		//cout << endl;

		t.findR(8);

		int b[] = { 2, 6, 0, 9, 5, 3, 4, 1, 7, 8};
		for (auto& e : b){
			t.eraseR(e);
			t.inOrder();
			cout << endl;
		}


	}
}
