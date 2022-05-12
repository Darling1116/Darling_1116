#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;

namespace GXR{

	template <class T>
	struct _list_node{	//struct定义类默认的访问权限为public
		T val;
		_list_node<T>* next;
		_list_node<T>* prev;

		_list_node(const T& val = T())  //这里使用匿名对象做缺省值
			:val(val),
			next(nullptr),
			prev(nullptr){
		}
	};



	template <class T, class Ref, class Ptr>
	struct _list_iterator{  //实现list迭代器模板类
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;

		node* _pnode;

		_list_iterator(node* pnode = nullptr)
			:_pnode(pnode){

		}
			
		Ref operator*(){
			return _pnode->val;
		}

		Ptr operator->(){
			return &_pnode->val;
		}

		bool operator!=(const self& l){
			return _pnode != l._pnode;
		}

		bool operator==(const self& l){
			return _pnode == l._pnode;
		}

		//前置++
		self& operator++(){
			_pnode = _pnode->next;
			return *this;
		}

		//前置--
		self& operator--(){
			_pnode = _pnode->prev;
			return *this;
		}

		//后置++
		self operator++(int){
			self tmp(*this);
			_pnode = _pnode->next;
			return tmp;

		}

		//后置--
		self operator--(int){
			self tmp(*this);
			_pnode = _pnode->prev;
			return tmp;
		}

	};



	template <class T>
	class list{
	public:
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<const T, const T&, const T*> const_iterator;

		list( ){
			_head = new node;
			_head->next = _head;
			_head->prev = _head;
		}


		list(list<T>& l){
			_head = new node;
			_head->next = _head;
			_head->prev = _head;
			for(auto& e : l){
				push_back(e);
			}
		}


		list<T>& operator=(list<T> l){
			//clear();
			//for (auto& e : l){
			//	push_back(e);
			//}
			swap(_head, l._head);
			return *this;
		}


		iterator begin(){
			return iterator(_head->next);
		}

		iterator end(){


		}

		const_iterator begin() const{
			return const_iterator(_head->next);
		}

		const_iterator end() const {
			return const_iterator(_head);
		}


		void push_back(const T& x){
			//node* newnode = new node(x);
			//node* tail = _head->prev;

			//tail->next = newnode;
			//newnode->prev = tail;
			//newnode->next = _head;
			//_head->prev = newnode;
			insert(end(), x);
		}

		void push_front(const T& x){
			insert(begin(), x);
		}

		iterator pop_back(){
			return erase(--end());
		}

		iterator pop_front(){
			return erase(begin());
		}


		void insert(iterator pos, const T& x){
			node* curnode = pos._pnode;
			node* prenode = curnode->prev;

			node* newnode = new node(x);
			prenode->next = newnode;
			newnode->prev = prenode;
			newnode->next = curnode;
			curnode->prev = newnode;
		}


		//删除操作：返回pos下一个位置的迭代器
		iterator erase(iterator pos){
			assert(pos != nullptr);
			assert(pos != end());

			node* curnode = pos._pnode;
			node* nextnode = curnode->next;
			
			curnode->prev->next = nextnode;
			nextnode->prev = curnode->prev;
			delete curnode;

			return iterator(nextnode);
		}
		

		bool empty(){
			if (_head->next == _head)
				return true;
			else
				return false;
		}

		size_t size() const{
			size_t sz = 0;
			node *p = _head->next;
			while (p != _head){
				p = p->next;
				++sz;
			}
			return sz;
		}

		void clear(){
			while (size() != 0){
				erase(begin());
			}
		}


		void print_list(){
			list<int>::iterator it = begin();
			while (it != end()){
				cout << *it << " ";
				it++;
			}
			cout << endl;
		}

		~list(){
			clear();
			delete _head;
			_head = nullptr;
		}

	private:
		node* _head;
	};


	struct Date{

		void print(){
			cout << _year << " " << _month << " " << _day << endl;
		}

		int _year = 2022;
		int _month =5;
		int _day = 20;
	};
	

	//push_back、迭代器遍历
	void test_list_1(){
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);

		for (auto e : l){
			cout << e << " ";
		}
		cout << endl;

		list<int>::iterator it = l.begin();
		while (it != l.end()){
			*it += 10;
			//若operator*返回值为引用类型，则val可读可写;
			//若为const T&，则val只读不可写
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}

	//operatoe->
	void test_list_2(){
		list<Date> l;
		Date d1;
		Date d2;
		Date d3;
		l.push_back(d1);
		l.push_back(d2);
		l.push_back(d3);

		//d1.print();

		list<Date>::iterator it = l.begin();
		while (it != l.end()){
			it->print();
			++it;
		}
		cout << endl;
	}

	//前后置++、--
	void test_list_3(){
		list<int> l;
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		
		list<int>::iterator it = l.begin();
		cout << *it << endl;

		//++it;
		//cout << *it << endl;

		//--it;
		//cout << *it << endl;

		cout << *it++ << endl;
		cout << *it-- << endl;
	}

	//insert、erase
	void test_list_4(){
		list<int> l;
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		//这里我们自定义类型的iterator就不能使用库里的find函数
		list<int>::iterator pos = l.begin();
		pos++;
		l.insert(pos, 100);
		cout << *pos << endl;
		for (auto& e : l){
			cout << e << " ";
		}
		cout << endl;

		list<int>::iterator ret = l.erase(pos);
		cout << *ret << endl;
		for (auto& e : l){
			cout << e << " ";
		}
		cout << endl;
	}

	//empty、size、clear
	void test_list_5(){
		list<int> l;
		l.push_back(2);
		l.push_back(2);
		l.push_back(2);
		l.push_front(1);
		l.pop_back();
		l.pop_front();
		for (auto& e : l){
			cout << e << " ";
		}
		cout << endl;

		cout << l.empty() << endl;
		cout << l.size() << endl;

		l.clear();
		for (auto& e : l){
			cout << e << " ";
		}
		cout << endl;

	}

	//拷贝构造和赋值重载
	void test_list_6(){
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);

		l.print_list();

		//list<int> l2(l);
		//l2.print_list();

		list<int> l3;
		l3.push_back(0);
		l3.print_list();
		l3 = l;
		l3.print_list();

	}
}