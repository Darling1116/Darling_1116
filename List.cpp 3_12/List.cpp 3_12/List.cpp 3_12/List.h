#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdlib.h>
#include <iostream>
#include <algorithm>

namespace GXR
{
   template <class T>
   struct  _ListNode
	{
		_ListNode<T>* _prev;
		_ListNode<T>* _next;
		T _data;

		_ListNode(const T& x = T())
			: _next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{

		}
	};


	template <class T>
	struct _ListIterator
	{
		typedef _ListNode<T> Node;
     	Node* _node;

		_ListIterator()
			:_node(nullptr)
		{

		}

		_ListIterator(Node* node)
			:_node(node)
		{

		}


		T& operator*()
		{
			return _node->_data;
		}

		_ListIterator<T>& operator++ ()
		{
			_node = _node->_next;//让迭代器走向下一位
			return *this;
		}

		bool operator != (_ListIterator& self)
		{
			return _node != self._node;
		}

	};


	template<class T>
	class List
	{
		typedef _ListNode<T> Node;

	public:
		typedef _ListIterator<T> iterator;

		List()//构造
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}

			//保留头结点，保证一个完整的链表形式
			_head->_next = _head;
			_head->_prev = _head;
			
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		iterator Insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		iterator Erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_prev->_next = cur;
			cur->_prev = prev->_prev;
			delete prev;

			return iterator(cur->_next);
		}

		void PushBack(const T& x)
		{
			//先找到尾，然后生成一个新的结点
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

		}

		void PopBack()
		{

				Node* tail = _head->_prev;
				if (tail != _head)
				{
				Node* cur = tail->_prev;
				delete tail;
				cur->_next = _head;
				_head->_prev = cur;
			}
		}

		void PushFront(const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = _head->_next;
			_head->_next = newnode;
			newnode->_prev = _head;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		void PopFront()
		{
			Node* cur = _head->_next;
			if (cur != _head)
			{
				Node* next = cur->_next;
				delete cur;
				_head->_next = next;
				next->_prev = _head;
			}
		}

		size_t Size()
		{
			size_t count = 0;
			Node* cur = _head->_next;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
		
			}
			return count;
		}

		bool Empty()
		{
			return _head->_next == _head;
		}

		void ReSize(size_t newsize, const T& x = T())
		{
			size_t oldsize = Size();
			if (oldsize <= newsize)
			{
				for (size_t i = oldsize; i < newsize; i++)
				{
					PushBack(x);
				}
			}
			else
			{
				for (size_t i = newsize; i < oldsize; i++)
				{
					PushBack();
				}
			}
		}

	private:
		_ListNode<T>* _head;
	};
}


