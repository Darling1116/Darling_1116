#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

namespace GXR{
	class string
	{
	public:
		string(const char* str="")
			:_size(strlen(str)),
			_capacity(_size),
			_str(new char[_capacity+1]){
			strcpy(_str, str);
		}

		//string(const string& s)
		//	:_size(s._size),
		//	_capacity(s._capacity),
		//	_str(new char[s._capacity+1]){
		//	strcpy(_str, s._str);
		//}


		string(const string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0){  //先构造再拷贝
			string tmp(s._str);
			Swap(tmp);
			/*swap(_str, tmp._str);
			swap(_size, tmp._size);
			swap(_capacity, tmp._capacity);*/
		}

		//string& operator=(string s){
		//	if (this != &s){
		//		delete[] _str;
		//		_str = new char[s._capacity + 1];
		//		_size = s._size;
		//		_capacity = s._capacity;
		//		strcpy(_str, s._str);
		//		return *this;
		//	}
		//}

		string& operator=(string s){
			/*swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);*/
			Swap(s);
			return *this;
		}

		void Swap(string& s){  //这里参数要用s的引用，传值在拷贝构造时会无限次的递归
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		char* c_str(){
			return _str;
		}

		size_t size(){
			return _size;
		}

		size_t capacity(){
			return _capacity;
		}

		
		char& operator[](int index){  
			assert(index < _size);
			return _str[index];
		}

		
		//迭代器底层是一个指针
		typedef char* iterator;
		iterator begin(){  //指向_str的起始地址
			return _str;
		}

		iterator end(){  //指向_str最后一个元素的下一个位置
			return _str+_size;
		}

		string& operator+=(const char c){
			push_back(c);
			return *this;
		}


		string& operator+=(const char* str){
			append(str);
			return *this;
		}
		  

		void push_back(const char c){  //尾插入单个字符后，还要把'/0'加到最后
			if (_size == _capacity){
				size_t new_capacity = _capacity;
				if (new_capacity == 0){
					new_capacity = 4;
				}
				else{
					reverse(new_capacity * 2);
				}
			}
			_str[_size] = c;
			_str[_size + 1] = '\0';
			++_size;
		}

		void append(const char* str){
			if (_size + strlen(str) > _capacity){
				reverse(_size + strlen(str));
			}
			strcpy(_str + _size, str);
			_size += strlen(str);

		}

		//增容：开空间，把原数据拷贝到新空间，释放旧空间，设置新空间为当前空间
		void reverse(size_t n){
			if (n > _capacity){
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//保留n个元素：开空间+初始化剩余元素，默认给'\0'
		void resize(size_t n, char val = '\0'){
			if (n < _size){
				_size = n;
				_str[_size] = '\0';
			}
			else{  
				if (n>_capacity){
					reverse(n);
				}
				for (size_t i = _size; i < n; i++){
					_str[i] = '\0';
				}
				_size = '\0';  //处理最后一个位置为'\0'
				_size = n;
			}
		}


		string& insert(size_t pos, char c){
			assert(pos <= _size);

			if (_size == _capacity){  //先判断是否需要增容
				reverse(_capacity==0 ? 4 : _capacity * 2);
			}

			int end = _str[_size]; 
			for (int i = end; i >= (int)pos; i--){  
				//这里pos要强转，否则pos为0时，0-1无符号整型为2的32次方-1
				_str[end + 1] = _str[end];
			}
			_str[pos] = c;
			++_size;
			return *this;
		}


		string& insert(size_t pos, char* str){
			assert(pos <= _size);
			if (_size + strlen(str) > _capacity){
				reverse(_size + strlen(str));
			}

			//用指针来挪动一段有距离的数据(指针解引用)
			char* end = _str + _size;
			while (end >= _str + pos){
				*(end + strlen(str)) = *end;
				end--;
			}
			strncpy(_str + pos, str, strlen(str));
			_size += strlen(str);
			return *this;

		}


		~string(){
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};


	void test_string_1(){
		string s1("hahaha");
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s2.c_str() << endl;

		string s3("xixixi");
		cout << s3.c_str() << endl;
		s3 = s1;
		cout << s3.c_str() << endl;

		cout << s3.size() << endl;
		cout << s3.capacity() << endl;
	}


	//string的三种遍历方式
	void test_string_2(){
		string s1("hahaha");
		cout << s1.c_str() << endl;

		for (int i = 0; i < s1.size(); i++){
			cout << s1[i] << " ";
		}
		cout << endl;


		string::iterator it = s1.begin();
		while (it != s1.end()){
			cout << *it << " ";
			it++;
		}
		cout << endl;

		//范围for会被编译器自动替换为迭代器的形式
		for (auto e : s1){
			cout << e << " ";
		}
		cout << endl;
		
		
	}

	void test_string_3(){
		string s1("hahaha");
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		s1.push_back('x');
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;


		s1 += 'm';
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		//s1.append("yyyyyyyyy");
		//cout << s1.c_str() << endl;
		//cout << s1.size() << endl;
		//cout << s1.capacity() << endl;

		s1 += "oooooo";
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
	}

	void test_string_4(){
		string s1("hahaha");
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		s1.resize(10, 'x');
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		s1.resize(3);
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
	}

	void test_string_5(){
		string s1("hahaha");
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		s1.insert(3, "yyy");
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
	}
}