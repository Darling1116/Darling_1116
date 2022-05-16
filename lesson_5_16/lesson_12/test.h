#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

namespace GXR{

	class Person {
	public:
		virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }

		 virtual ~Person(){
			cout << "~Person" << endl;
		}
	};


	class Student : public Person {
	public:
		virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

		virtual ~Student(){
			cout << "~Student" << endl;
		}
	};

	class Soldier : public Person {
	public:
		 void BuyTicket() { cout << "��Ʊ-����" << endl; }
	};


	void Func_1(Person& p) {  //���������Ķ���������
		p.BuyTicket();
	}

	void Func_2(Person* p) {  //���������Ķ�����ָ��
		p->BuyTicket();
	}

	void test_1(){
		Person* ps = new Person();
		Student* st = new Student();
		//Soldier sd;

		//Func_1(ps);
		//Func_1(st);
		//Func_1(sd);

		delete ps;
		delete st;
	}
}