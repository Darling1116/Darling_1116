#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
//#include <stack>
//#include <queue>
#include <vector>
#include <list>

#include <deque>

using namespace std;

using std::cout;
using std::endl;

//void test_stack(){
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	st.push(5);
//	st.push(6);
//
//	while (!st.empty()){
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
//
//void test_queue(){
//	queue<int> qu;
//	qu.push(1);
//	qu.push(2);
//	qu.push(3);
//	qu.push(4);
//	qu.push(5);
//	qu.push(6);
//	while (!qu.empty()){
//		cout << qu.front() << " ";
//		qu.pop();
//	}
//	cout << endl;
//}

namespace GXR_1{
	//stack是一个容器适配器，底层我们可以用vector来实现
	template <class T, class Container = vector<T>>
	class stack_1{

	public:
		void push(const T& x){
			_con.push_back(x);
		}

		void pop(){
			_con.pop_back();
		}

		T top(){
			return _con[_con.size() - 1];
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_1(){
		stack_1<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);
		while (!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;

	}


	//stack的底层用list实现
	template <class T, class Container = list<T>>
	class stack_2{
	public:
		void push(const T& x){
			_con.push_back(x);
		}

		void pop(){
			_con.pop_back();
		}

		T top(){
			return _con.back();
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_2(){
		stack_2<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		st.push(6);
		while (!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}


	//queue是一个容器适配器，底层我们用deque来实现
	template < class T, class Container = deque<T>>
	//deque为一个双端队列
	class queue{
	public:
		void push(const T& x){
			_con.push_back(x);
		}

		void pop(){
			_con.pop_front();
		}

		T front(){
			return _con.front();
		}

		T back(){
			return _con.back();
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_3(){


		queue<int> qu;
		qu.push(1);
		qu.push(2);
		qu.push(3);
		qu.push(4);
		qu.push(5);
		qu.push(6);
		while (!qu.empty()){
			cout << qu.front() << " ";
			qu.pop();
		}
		cout << endl;
	}
}

