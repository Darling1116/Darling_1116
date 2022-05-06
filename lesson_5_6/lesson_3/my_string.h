#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace GXR{  //�����Լ��������ռ䣬��STL�е�string����и���

	class string{
		//����һ���Լ���String��(������)
		
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1]){  //��ʼ���б��ʼ��
			strcpy(_str, str);  //��ʼ���ַ���Ϊ��
		}


		char* c_str(){
			return _str;
		}

		////��ͳд��:�ȿ��ռ䣬�ٿ���
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1){
		//		strcpy(_str, s._str);  //ʹ��strcpy�����ַ�������
		//	}


		//string& operator=(string s){  
		//	//��ԭ���Ŀռ��ͷŵ��������Ͳ��ÿ��ǿռ䲻�������
		//	if (this != &s){
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}


		//�ִ�д��:����swap����
		string(const string& s)
			:_str(nullptr){
				//����һ����ʱ����,Ȼ�󽻻����������str
				string tmp(s._str);  
				swap(_str, tmp._str);
		}


		string& operator=(string s){
			//�����Ѿ����ڣ�ֱ�ӽ������������str
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

		string s3("honey");  //��ֵʱ����Ҫ�����˳�ʼ��
		s3 = s1;
		char* c3 = s3.c_str();
		std::cout << c3 << std::endl;
	}

}