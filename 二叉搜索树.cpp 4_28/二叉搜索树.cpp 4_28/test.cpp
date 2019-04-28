#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
	template <class T>
	struct BSTNode
	{
		BSTNode(const T& kv = T())
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
		{}


		BSTNode<T>* _left;
		BSTNode<T>* _right;
		T _kv;
	};

	template <class T>
	class BSTree
	{
		typedef BSTNode<T> Node;//结点
		typedef Node* pNode;//指向结点的指针
	public:
		//构造
		BSTree()
			:root(nullptr)
		{}

		//析构
		~BSTree()
		{
			_Destroy(root);
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* newroot = new Node(root->_kv);
			newroot->_left = Copy(root->left);
			newroot->_right = Copy(root->_right);
			return newroot;
		}
		//拷贝
		BSTree(const BSTree<T>& tree)
		{
			root = Copy(tree.root);
		}
		//复制
		BSTree<T>& operator = (const BSTree<T>& tree)
		{
			if (this != &tree)
			{
				_Destroy(this->root);
				this->root = Copy(tree->root);
				return *this;
			}
		}

		//BSTree<T>& operator = (const BSTree<T>& tree)
		//{
		//	swap(this->root, tree->root);
		//	return *this;
		//}

		//插入
		bool Insert(const T& kv)
		{

			//1.如果树为空，直接插入根节点
			if (root == nullptr)
			{
				root = new Node(kv);
				return true;
			}
			//2.树不为空，找插入位置
			Node* cur = root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if ( kv < cur->_kv)
					cur = cur->_left;
				else if (kv > cur->_kv)
					cur = cur->_right;
				else
					return false;
				//否则，存在该结点，返回false
			}
			//3.位置找到（此时，cur为空），插入元素
			cur = new Node(kv);
			if (kv < parent->_kv)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}

		void Print()
		{
			_inorder(root);
		}

		//删除
		bool Erase(const T& kv)
		{
			//1.树为空，删除失败
			if (root == nullptr)
				return false;
	        //2.树不为空，找位置
			Node* cur = root;
			Node* parent = nullptr;
			while(cur)
			{
				if (cur->_kv == kv)
				{
					break;
				}
				else if (kv < cur->_kv)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					parent = cur;
					cur = cur->_right;
				}
			}
			//此时cur为空，表示没找到
			if (cur == nullptr)
				return false;

			//3.删除元素
			//结点的左为空，父亲指向结点的有右
			if (cur->_left == nullptr)
			{
				if (cur == root)//结点为根节点
					root = cur->_right;
				else
				{
					if (cur == parent->_left)//结点在父亲的左边
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;//结点在父亲的右边
				}
				delete cur;
			}
			//结点的右为空，父亲指向结点的左
			else if (cur->_right == nullptr)
			{
				if (cur == nullptr)
					root = cur->_left;
				else
				{
					if (cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				delete cur;
			}
			//结点的左右都不为空，找左树的最大结点或者右树的最小结点作为替换结点
			else
			{
				Node* replace = cur->_right;
				Node* preplace = nullptr;
				while (replace->_left)
				{
					preplace = replace;
					replace = replace->_left;
				}
				cur->_kv = replace->_kv;
				if (replace == preplace->_left)
					preplace->_left = nullptr;
				else
					preplace->_right = nullptr;
				delete replace;
				replace = nullptr;
			}
			return true;
		}

		//查找
		Node* Find(const T& kv)
		{
			Node* cur = root;
			while (cur)
			{
				if (kv == cur->_kv)
					return cur;
				else if (kv < cur->_kv)
					cur = cur->_left;
				else
					cur = cur->_right;
			}
			return nullptr;
		}

	private:
		void _Destroy(pNode& root)
		{
			if (root)
			{
				_Destroy(root->_left);
				_Destroy(root->_right);
				root = nullptr;
			}
		}

		void _inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_inorder(root->_left);
			cout << root->_kv << " ";
			_inorder(root->_right);
			cout << endl;
		}

		pNode root;
	};


int main()
{
	using  std::cout;
	using  std::endl;
	BSTree<int> T;
	T.Insert(1);
	T.Insert(1);
	T.Insert(3);
	T.Insert(1);
	T.Insert(6);
	T.Insert(9);
	T.Print();

	T.Erase(1);
	T.Print();
	T.Erase(9);
	T.Print();

	cout << T.Find(3) << endl;
	system("pause");
	return 0;
}