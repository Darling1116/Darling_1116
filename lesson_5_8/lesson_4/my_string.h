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

		//最简洁版的构造：直接初始为'\0'
		//string()
		//	:_str(new char[1]){
		//	*_str = '\0';
		//}

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

		typedef char* const_iterator;
		const_iterator begin() const{  //指向_str的起始地址
			return _str;
		}

		const_iterator end() const {  //指向_str最后一个元素的下一个位置
			return _str + _size;
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

		#define npos -1

		string& erase(size_t pos, size_t len=npos){
			if (_size - pos <= len){  //删除之后后面没有元素
				_size = pos;
			}
			else{  //删除之后后面还有元素，需要把后面的元素往前挪
				strcpy(_str + pos, _str + pos + len);
				_size = _size - len;
			}
			return *this;
		}

		size_t find(char c, size_t pos = 0){
			for (size_t i = pos; i < _size; i++){
				if (_str[i] == c)
					return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0){
			//使用strstr(s,str)函数，返回值为str在s中所在位置的地址
			char* ret = strstr(_str, str);
			if (ret != nullptr){  //找到了,两个位置的地址相减即为对应的下标
				return ret - _str;
			}
			else{
				return npos;
			}
		}

		bool operator>(const string& s){
			return strcmp(_str, s._str)>0;
		}

		bool operator==(const string& s){
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s){
			return !(_str > s._str);
		}

		bool operator>=(const string& s){
			return !(_str < s._str);
		}

		bool operator<(const string& s){
			return strcmp(_str, s._str)<0;
		}

		bool operator!=(const string& s){
			return !(_str == s._str);
		}


		friend istream& operator>>(istream& in, string& s);
		friend ostream& operator<<(ostream& out, const string& s);

		string& clear(){
			_size = 0;
			_str[0] = '\0';
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


	istream& operator>>(istream& in, string& s){
		s.clear();
		char c = in.get();
		while (c != ' ' && c != '\n'){
			s += c;
			c = in.get();
		}
		return in;
	}

	istream& getline(istream& in, string& s){
		s.clear();
		char c = in.get();
		while (c != '\n'){
			s += c;
			c = in.get();
		}
		return in;
	}



	//输出重载，利用范围for：依次从s中拿字符给out
	ostream& operator<<(ostream& out, const string& s){
		for (auto e : s){
			out << e;
		}
		return out;
	}

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

	//插入操作
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

	//resize
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

	//insert
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

	//erase、clear

	void test_string_6(){
		string s1("my name is gxr.");
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		s1.erase(3, 2);
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		/*s1.clear();
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;*/
	}


	//find
	void test_string_7(){
		string s1("my name is gxr.");
		cout << s1.c_str() << endl;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		cout << s1.find('i', 0) << endl;
		cout << s1.find("gc", 5) << endl;
	}

	//> < >= <= == !=
	void test_string_8(){
		string s1("ab");
		cout << s1.c_str() << endl;

		string s2("a");
		cout << s2.c_str() << endl;

		cout << (s1 != s2) << endl;

	}


	//输入输出重载、实现getline
	void test_string_9(){
		string s1("init");
		string s2 = "init";  
		//隐式类型转换：先构造出一个临时对象，然后拿该临时对象去拷贝构造出s2，编译器对其进行优化，直接合二为一拷贝构造一个对象
		cout << s1 << endl;
		cout << s2 << endl;

		//cin >> s1;
		//cout << s1 << endl;

		//getline(cin, s1);
		//cout << s1 << endl;

	}

}
