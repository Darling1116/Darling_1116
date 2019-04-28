#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
namespace GXR{
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
		typedef BSTNode<T>* Node;//结点
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
				if (kv < cur->_kv)
					cur = cur->_left;
				else if (kv > cur->_kv)
					cur = cur->_right;
				else
					return false;
			}
			//3.位置找到（此时，cur为空），插入元素
			cur = new Node(kv);
			if (kv < parent->_kv)
				parent->_left = cur;
			else
				parent->_right = cur;

			return true;
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

		pNode root;
	};
}

