#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

namespace GXR{
	struct Date{
	public:
		Date(int year = 2022, int month = 6, int day = 27)
			:_year(year),
			_month(month),
			_day(day){ 
			//cout << "Date()" << endl; 
		}

		~Date(){ 
			//cout << "~Date()" << endl; 
		}
		int _year;
		int _month;
		int _day;
	};

	//让智能指针去管理Date对象

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

	template <class T>
	class unique_ptr{
	public:
		unique_ptr(T* ptr = nullptr)
			:_ptr(ptr){
			cout << "unique_ptr..." << endl;
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

		//禁止拷贝构造和赋值重载的功能
		unique_ptr(const unique_ptr& up)= delete;
		unique_ptr& operator=(const unique_ptr& up)= delete;

		~unique_ptr(){
			_ptr = nullptr;
			cout << "delete..." << endl;
		}
	private:
		T* _ptr;
	};
	
	void test_unique_ptr(){
		unique_ptr<Date> ap1(new Date);
		unique_ptr<Date> ap2(new Date);
		ap2->_month = 2012;
		//ap1 = ap2;
		//unique_ptr<Date> ap3(ap1);
	}


	//引入了引用计数，让多个智能指针对象管理同一块资源
	template <class T>
	class shared_ptr{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr),
			_count(new int(1)),
			_pmutex(new mutex){
			cout << "shared_ptr..." << _ptr << endl;
		}

		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

		int& get_count(){
			return *_count;
		}

		T* get_ptr(){
			return _ptr;
		}

		//拷贝构造时，引用计数加1
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr),
			_count(sp._count),
			_pmutex(sp._pmutex){
			add_ref_count();
			cout << _count << ": " << *_count << endl;
			cout << "shared_ptr..." << _ptr << endl;
		}

		//赋值重载时，引用计数加1
		shared_ptr<T>& operator=(shared_ptr<T>& sp){
			if (_ptr != sp._ptr){  
				//先处理this以前的资源
				/*if (--(*_count) == 0){
					delete _ptr;
					delete _count;
				}*/
				release();
				//赋值
				_ptr = sp._ptr;
				_count = sp._count;
				_pmutex = sp._pmutex;
				//++(*_count);
				add_ref_count();
			}
			cout << "operator=..." << _ptr << endl;
			return *this;
		}
		
		~shared_ptr(){
			//if (--(*_count) == 0){
			//	cout << "delete..." << _ptr << endl;
			//	delete _ptr;
			//	delete _count;
			//}
			release();
		}

	private:
		void add_ref_count(){
			_pmutex->lock();
			++(*_count);
			_pmutex->unlock();
		}

		void release(){  //释放以前的资源：锁也是资源，也要释放
			bool deleteflag = false;

			_pmutex->lock();
			if (--(*_count) == 0){
				cout << "delete..." << _ptr << endl;
				delete _ptr;
				delete _count;
				deleteflag = true;
			}
			_pmutex->unlock();

			if (deleteflag == true){
				delete _pmutex;
				cout << "delete pmutex..." << _pmutex << endl;
			}
		}

	private:
		T* _ptr;
		int* _count;  
		mutex* _pmutex;
	};

	void test_shared_ptr_1(){
		shared_ptr<Date> sp1(new Date);
		shared_ptr<Date> sp2(new Date(2022, 12, 12));
		//cout << sp2->_month << endl;
		//shared_ptr<Date> copy(sp1);
		sp1 = sp2;	
	}

	void test_shared_ptr_2(){
		shared_ptr<Date> sp1(new Date);
		//shared_ptr<Date> sp2(new Date(2022, 12, 12));
		shared_ptr<Date> sp3(sp1);
		sp3->_year = 2000;
		cout << sp1.get_count() << endl;
		cout << sp3.get_count() << endl;
	}

	//测试多线程安全问题

	void shared_func(shared_ptr<Date>& sp, size_t n){
		cout << sp.get_ptr() << endl;
		for (size_t i = 0; i < n; i++){
			//调用其拷贝构造函数，会产生_count++的操作
			shared_ptr<Date> copy(sp);
			copy->_year++;
			copy->_month++;
			copy->_day++;
		}
	}

	void test_shared_ptr_3(){
		shared_ptr<Date> sp(new Date(2000, 1, 1));
		cout << sp.get_ptr() << endl;
		cout << sp->_year << endl;

		size_t n = 1000;
		//让线程t1、t2执行相同的逻辑
		thread t1(shared_func, sp, n);
		thread t2(shared_func, sp, n);
		t1.join();
		t2.join();
		
		cout << sp->_year << endl;
		
		
	}
}