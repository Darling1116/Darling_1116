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
		//1.����RAII����
		auto_ptr(T* ptr = nullptr)
		:_ptr(ptr){
			cout << "auto_ptr..." << endl;
		}

		//2.��ָ��һ��ȥʹ��
		T& operator*(){
			return *_ptr;
		}

		T* operator->(){
			return _ptr;
		}

		//auto_ptr�ڿ������졢��ֵ����ʱ�����˹���Ȩת��
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr){
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T> ap){
			if (_ptr != ap._ptr){
				// �ͷŵ�ǰ��������Դ
				if (_ptr != nullptr){
					delete _ptr;
				}
				// ת��ap����Դ����ǰ������
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