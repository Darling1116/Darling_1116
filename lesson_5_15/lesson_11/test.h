#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

namespace GXR_1{
	class Person
	{
	public:
		void print(){
			cout << "name is " << _name << endl;
			cout << "age is " << _age << endl;
		}
		Person(){

		}


		string _name = "Guoguo";
		int _age = 18;
	};


	class Student : public Person
	{
	public:
		void id(){
			cout << "age is " << _age << endl;
			//cout << "age is " << Person::_age << endl;
			cout << "stuId is " << _stuId << endl;
		}
		
		int _age = 6;
		int _stuId = 10010;
	};


	class Teacher : public Person
	{
	public:
		void id(){
			cout << "teaId is " << _teaId << endl;
		}
		
		int _teaId = 20002;
	};


	void test_1(){
		Person p;
		Student s;
		//s._name = "Mary";
		//s._age = 6;

		//p = s;
		//p.print();

		//Person *ptr = &s;

		//Person& ref = s;
	
		s.id();
		
	}

}

namespace GXR_2{
	class A {
	public:
		int _a;
	};
	// class B : public A
	class B : virtual public A {
	public:
		int _b;
	};
		
	class C : virtual public A {
	public:
		int _c;
	};
	class D : public B, public C {
	public:
		int _d;
	};
	

	void test_2(){
		D d;
		d.B::_a = 1;
		d.C::_a = 2;
		d._b = 3;
		d._c = 4;
		d._d = 5;
	}
}