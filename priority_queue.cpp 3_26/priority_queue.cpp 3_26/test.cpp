#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
//int main()
//{
//	vector<int> v{ 2, 3, 7, 1, 0, 4 };
//	priority_queue<int> pq;
//	for (auto e: v)
//	{
//		pq.push(e);
//	}
//	cout << pq.top() << endl;
//
//	priority_queue<int, vector<int>, greater<int>> pq1(v.begin(),v.end());
//	
//	cout << pq1.top() << endl;
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <deque>
//using namespace std;
//
//template<class T ,class Con = deque<T>>//形参
//
//class Stack
//{
//public:
//	Stack() {}
//
//	void Push(const T& x)
//	{
//		_c.push_back(x);
//	}
//	void Pop()
//	{
//		_c.pop_back();
//	}
//
//	T& top()
//	{
//		return _c.back();
//	}
//	size_t Size()
//	{
//		return _c.size();
//	}
//
//	bool Empty()
//	{
//		return _c.empty();
//	}
//
//private:
//	Con _c;
//};
//
//void TestStack()
//{
//	Stack<int> st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	cout << st.top() << endl;
//
//	st.Pop();
//	
//	cout << "Size:" << st.Size() << endl;
//	cout << "Empty:" << st.Empty() << endl;
//}

//template <class T ,class Con = deque<int>>
//class Queue
//{
//public:
//	Queue(){}
//	void Push(const T& x)
//	{
//		_c.push_back(x);
//	}
//	void Pop()
//	{
//		_c.pop_front();
//	}
//	T& Front()
//	{
//		return _c.front();
//	}
//	T& Back()
//	{
//		return _c.back();
//	}
//	size_t Size()
//	{
//		return _c.size();
//	}
//	bool Empty()
//	{
//		return _c.empty();
//	}
//
//private:
//	Con _c;
//};
//
//void TestQueue()
//{
//
//	Queue <int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	cout << "队头元素：" << q.Front() << endl;
//	cout << "队尾元素：" << q.Back() << endl;
//	cout << "队列的大小：" << q.Size() << endl;
//	cout << "队列是否为空：" << q.Empty() << endl;
//	
//}

template <class T ,class Con = vector<T>>
class Priority_queue//默认是大堆
{
public:
	void Push(const T& x)
	{
		_c.push_back(x);
		Adjustup(_c.size() - 1);
	}

	void Adjustup(int child)//用数组的下标控制
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_c[child] > _c[parent])
			{
				swap(_c[child], _c[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void Pop()
	{
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		Adjustdown(0);
	}
	
	void Adjustdown(int root)
	{
		int parent = root;
		int child = (parent * 2) + 1;
		while (child < _c.size())
		{
			if (child+1<_c.size() && _c[child + 1] > _c[child])//
			{
				child = child + 1;
			}
			if (_c[child] > _c[parent])
			{
				swap(_c[child], _c[parent]);
				parent = child;
				child = (parent * 2) + 1;
			}
			else
			{
				break;
			}
		}

	}
	T& top()
	{
		return _c[0];
	}
	size_t Size()
	{
		return _c.size();
	}
	bool Empty()
	{
		return _c.empty();
	}


private:
	Con _c;
};

void TestPriority_queue()
{
	Priority_queue<int> pq;
	pq.Push(1);
	pq.Push(2);
	pq.Push(3);
	pq.Push(4);
	cout << pq.top() << endl;
	while (pq.Size())
	{
		cout << pq.top() << " ";
		pq.Pop();
	}
	cout << endl;
	cout << "Size:" << pq.Size() << endl;
	cout << "Empty:" << pq.Empty() << endl;
}
int main()
{

	//TestStack();
	//TestQueue();
	TestPriority_queue();
	
	system("pause");
	return 0;
}