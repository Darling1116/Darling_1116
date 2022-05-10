#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::swap;

namespace GXR{

	template <class T>  //使用模板类
	class vector{
	public:
		typedef T* iterator;  //泛化迭代器的类型(数据类型为T)

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr){

		}


		vector(size_t n, T val = T())
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr){
			for (int i = 0; i < n; i++){
				push_back(val);
			}
		}


		//类模板的成员函数还可以是函数模板
		//template<class inputIterator>
		//vector(inputIterator begin, inputIterator end)
		//	:_start(nullptr),
		//	_finish(nullptr),
		//	_end_of_storage(nullptr){
		//	while (begin != end){
		//		push_back(*begin);
		//		++begin;
		//	}
		//}


		size_t size(){
			return _finish - _start;
		}

		size_t capacity(){
			return _end_of_storage - _start;
		}

		bool empty(){
			if (_start == _finish)
				return true;
			else
				return false;
		}

		iterator begin(){
			return _start;
		}

		iterator end(){
			return _finish;
		}

		T& operator[](size_t i){
			assert(i < size());
			return _start[i];
		}

		void reserve(size_t n){
			if (n > capacity()){
				//开辟一块新的空间
				T* tmp = new T[n];
				size_t sz = size();

				//如果原来的空间不为空，把原来的数据拷贝过去，释放旧空间
				if (_start != nullptr){
					//memcpy在对string这种内置类型进行拷贝构造、赋值重载时
					//会引发更深层次的深拷贝问题
					//memcpy(tmp, _start, sizeof(T)*sz);
					for (size_t i = 0; i < sz; i++){
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				//更新新空间的属性
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}


		void push_back(const T& x){

			//判断是否需要增容
			if (_finish == _end_of_storage){  //
				int new_capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(new_capacity);
			}
			//尾插数据
			*_finish = x;
			++_finish;
		}

		void pop_back(){
			if (!empty()){
				--_finish;
			}
		}


		void resize(size_t n, T val = T()){
			if (n < size()){
				_finish = _start + n;
			}
			else{
				if (n > capacity()){
					reserve(n);
				}
				while (_finish < _start + n){
					*_finish = val;
					++_finish;
				}
			}
		}


		iterator insert(iterator& pos, const T& x){
			assert(pos < _finish);
			size_t len = pos - _start;  //防止发生野指针问题

			if (_finish == _end_of_storage){
				reserve(2 * capacity());

				pos = _start + len;
			}

			iterator it = _finish - 1;
			while (it >= pos){
				*(it + 1) = *(it);
				--it;
			}
			*pos = x;
			_finish++;
			return pos;
		}

		iterator erase(iterator& pos){
			assert(pos < _finish);
			iterator it = pos;
			while (it != _finish){
				*(it) = *(it + 1);
				it++;
			}
			--_finish;
			return pos;
		}


		void Swap(vector<T>& v){
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}


		//拷贝构造
		vector(vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr){

			//方法1：使用new开空间，再把数据拷贝过去，更新vector属性
			//_start = new int[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());
			//_finish = _start + v.size();
			//_end_of_storage = _start + v.capacity();

			//方法2：使用reserve开空间，然后把元素依次插入到新对象中
			reserve(v.capacity());  //reserve把各属性都已经更新处理好了
			for (auto& e : v){
				push_back(e);
			}

		}


		//赋值重载
		vector<T>& operator=(vector<T> v){
			//1.传统写法
			//delete[] _start;
			//_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());
			//_finish = _start + v.size();
			//_end_of_storage = _start + v.capacity();

			//2.现代写法
			Swap(v);
			return *this;

		}


		void print(){
			for (size_t i = 0; i < size(); i++){
				cout << _start[i] << " ";
			}
			cout << endl;
		}

		~vector(){
			if (_start != nullptr){
				delete[] _start;
			}
			_start = nullptr;
			_finish = nullptr;
			_end_of_storage = nullptr;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};


	//push_back、pop_back、operator[]、reserve
	void test_vector_1(){
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end()){
			cout << *it << " ";
			++it;
		}
		cout << endl;

		cout << v1[3] << endl;

		cout << v1.empty() << endl;

		v1.pop_back();

		for (auto e : v1){
			cout << e << " ";
		}
		cout << endl;
	}

	//resize
	void test_vector_2(){
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v1.print();

		v1.resize(3);
		v1.print();

		v1.resize(7, int(6));
		v1.print();

		v1.resize(10, int (9));
		v1.print();
	}

	//insert、erase
	void test_vector_3(){
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		v1.print();

		vector<int>::iterator pos = std::find(v1.begin(), v1.end(), 3);
		cout << pos << endl;
		v1.insert(pos, 100);
		v1.print();
		cout << pos << endl;
		v1.erase(pos);
		v1.print();
		cout << pos << endl;
	}

	//拷贝构造和赋值重载
	void test_vector_4(){
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		v1.print();

		//vector<int> v2(v1);
		//v2.print();

		vector<int> v3;
		v3.push_back(100);
		v3.print();
		v3 = v1;
		v3.print();

	}

	//带参构造
	void test_vector_5(){
		vector<int> v(5, 10);
		v.print();
	}

	//迭代器构造
	void test_vector_6(){
		vector<std::string> v;
		v.push_back("111");
		v.push_back("222");
		v.push_back("333");
		v.push_back("444");
		v.push_back("555");
		v.push_back("666");
		v.print();
	}
}