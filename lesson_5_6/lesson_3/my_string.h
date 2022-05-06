#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace GXR{  //增加自己的命名空间，与STL中的string类进行隔离

	class string{
		//构建一个自己的String类(基础版)
		
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1]){  //初始化列表初始化
			strcpy(_str, str);  //初始化字符串为空
		}


		char* c_str(){
			return _str;
		}

		////传统写法:先开空间，再拷贝
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1){
		//		strcpy(_str, s._str);  //使用strcpy进行字符串拷贝
		//	}


		//string& operator=(string s){  
		//	//把原来的空间释放掉，这样就不用考虑空间不足的问题
		//	if (this != &s){
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}


		//现代写法:利用swap函数
		string(const string& s)
			:_str(nullptr){
				//创建一个临时对象,然后交换两个对象的str
				string tmp(s._str);  
				swap(_str, tmp._str);
		}


		string& operator=(string s){
			//对象已经存在，直接交换两个对象的str
			swap(_str, s._str);
			return *this;
			
		}
	


		~string(){
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}


	private:
		char* _str;
	};


	void test_1(){
		string s1("sweet dream.");
		char* c1 = s1.c_str();
		std::cout << c1 << std::endl;

		string s2(s1);
		char* c2 = s2.c_str();
		std::cout << c2 << std::endl;

		string s3("honey");  //赋值时对象要进行了初始化
		s3 = s1;
		char* c3 = s3.c_str();
		std::cout << c3 << std::endl;
	}

}