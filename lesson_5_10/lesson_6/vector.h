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

	template <class T>  //ʹ��ģ����
	class vector{
	public:
		typedef T* iterator;  //����������������(��������ΪT)

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


		//��ģ��ĳ�Ա�����������Ǻ���ģ��
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
				//����һ���µĿռ�
				T* tmp = new T[n];
				size_t sz = size();

				//���ԭ���Ŀռ䲻Ϊ�գ���ԭ�������ݿ�����ȥ���ͷžɿռ�
				if (_start != nullptr){
					//memcpy�ڶ�string�����������ͽ��п������졢��ֵ����ʱ
					//�����������ε��������
					//memcpy(tmp, _start, sizeof(T)*sz);
					for (size_t i = 0; i < sz; i++){
						tmp[i] = _start[i];
					}
					delete[] _start;
				}

				//�����¿ռ������
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}


		void push_back(const T& x){

			//�ж��Ƿ���Ҫ����
			if (_finish == _end_of_storage){  //
				int new_capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(new_capacity);
			}
			//β������
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
			size_t len = pos - _start;  //��ֹ����Ұָ������

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


		//��������
		vector(vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr){

			//����1��ʹ��new���ռ䣬�ٰ����ݿ�����ȥ������vector����
			//_start = new int[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());
			//_finish = _start + v.size();
			//_end_of_storage = _start + v.capacity();

			//����2��ʹ��reserve���ռ䣬Ȼ���Ԫ�����β��뵽�¶�����
			reserve(v.capacity());  //reserve�Ѹ����Զ��Ѿ����´������
			for (auto& e : v){
				push_back(e);
			}

		}


		//��ֵ����
		vector<T>& operator=(vector<T> v){
			//1.��ͳд��
			//delete[] _start;
			//_start = new T[v.capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.size());
			//_finish = _start + v.size();
			//_end_of_storage = _start + v.capacity();

			//2.�ִ�д��
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


	//push_back��pop_back��operator[]��reserve
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

	//insert��erase
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

	//��������͸�ֵ����
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

	//���ι���
	void test_vector_5(){
		vector<int> v(5, 10);
		v.print();
	}

	//����������
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