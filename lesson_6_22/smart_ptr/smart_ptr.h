#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

namespace GXR{
	//����ָ�룺���ö������������
	template <class T>
	class smart_ptr{
	public:
		smart_ptr(T* ptr)
		:_ptr(ptr){

		}

		~smart_ptr(){
			cout << "delete" << endl;
			delete _ptr;
		}

	private:
		T* _ptr;

		
	};

}