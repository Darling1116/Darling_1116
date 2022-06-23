#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace GXR{
	class Date{
	public:
		Date() { 
			cout << "Date()" << endl; 
		}

		~Date(){ 
			cout << "~Date()" << endl; 
		}
		int _year;
		int _month;
		int _day;
	};


	template <class T>
	class auto_ptr{
	public:
		//1.利用RAII技术
		auto_ptr(T* ptr = nullptr)
		:_ptr(ptr){
			cout << "auto_ptr..." << endl;
		}

		//2.像指针一样去使用
		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

		//auto_ptr在拷贝构造、赋值重载时进行了管理权转移
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr){
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T> ap){
			if (_ptr != ap._ptr){
				// 释放当前对象中资源
				if (_ptr != nullptr){
					delete _ptr;
				}
				// 转移ap中资源到当前对象中
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}
			return *this;
		}


		~auto_ptr(){
			if (_ptr)
				delete _ptr;
			cout << "delete..." << endl;
		}

	private:
		T* _ptr;
	};

	void test_auto_ptr(){
		auto_ptr<Date> ap1(new Date);
		auto_ptr<Date> ap2(new Date);
		ap2->_month = 2012;
		ap1 = ap2;
		cout << ap1->_month << endl;
	}
}