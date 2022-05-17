#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

namespace GXR_1{

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
		Person* st = new Student();
		//Soldier sd;

		//Func_1(ps);
		//Func_1(st);
		//Func_1(sd);

		delete ps;
		delete st;
	}

}

namespace GXR_2{
	class Car
	{
	public:
		virtual void Drive(){
			cout << "Drive" << endl;
		}

	private:
		int _id = 1;
		//char _num = '\0';
	};

	/*class Benz :public Car
	{
	public:
		virtual void Drive()
		{
			cout << "Benz-����" << endl;
		}
	};
*/
	void test_2(){
		/*Benz b;
		b.Drive();*/
		cout << sizeof(Car) << endl;
	}
	
}


namespace GXR_3{
	class Base {
	public:
		virtual void func1() { cout << "Base::func1" << endl; }
		virtual void func2() { cout << "Base::func2" << endl; }
	private:
		int a;
	};

	class Derive :public Base {
	public:
		virtual void func1() { cout << "Derive::func1" << endl; }
		virtual void func3() { cout << "Derive::func3" << endl; }
		virtual void func4() { cout << "Derive::func4" << endl; }
	private:
		int b;
	};


	typedef void(*VFunc) ();
	void PrintVTable(VFunc* vTable)
	{
		// ����ȡ����е��麯��ָ���ӡ������,���þͿ��Կ���������ĸ�����
		cout << " ����ַ->" << vTable << endl;
		for (int i = 0; vTable[i] != nullptr; ++i)
		{
			printf(" ��%d���麯����ַ :%p\n", i+1, vTable[i]);
			vTable[i]();
		}
		cout << endl;
	}

	void test_3(){
		Base b;
		PrintVTable((VFunc*)(*(int*)&b));

		Derive d;
		PrintVTable((VFunc*)(*(int*)&d));
		
	}
}


namespace GXR_4{
	class A{
	public:
		virtual void func(int val = 1){
			cout << "A->" << val << endl;
		}
		virtual void test(){ func(); }
	};

	class  B : public A{
	public:
		//�������麯�������virtual������Ŀ��Բ��ӣ�Ҳ������д
		void func(int val = 0){
			cout << "B->" << val << endl;
		}

	};

	void test_4(){
		B* p = new B;
		p->test();  
		//�麯����д���Ǻ�����ľ���ʵ�֣��̳е��Ǹ���Ľӿڣ����������б�
	}

}