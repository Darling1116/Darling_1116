#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>

using namespace std;

namespace GXR_1{

	class Person {
	public:
		virtual void BuyTicket() { cout << "买票-全价" << endl; }

		 virtual ~Person(){
			cout << "~Person" << endl;
		}
	};

	class Student : public Person {
	public:
		virtual void BuyTicket() { cout << "买票-半价" << endl; }

		virtual ~Student(){
			cout << "~Student" << endl;
		}
	};

	class Soldier : public Person {
	public:
		 void BuyTicket() { cout << "买票-优先" << endl; }
	};

	void Func_1(Person& p) {  //被调函数的对象是引用
		p.BuyTicket();
	}

	void Func_2(Person* p) {  //被调函数的对象是指针
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
			cout << "Benz-舒适" << endl;
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
		// 依次取虚表中的虚函数指针打印并调用,调用就可以看出存的是哪个函数
		cout << " 虚表地址->" << vTable << endl;
		for (int i = 0; vTable[i] != nullptr; ++i)
		{
			printf(" 第%d个虚函数地址 :%p\n", i+1, vTable[i]);
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
		//父类是虚函数必须加virtual，子类的可以不加，也构成重写
		void func(int val = 0){
			cout << "B->" << val << endl;
		}

	};

	void test_4(){
		B* p = new B;
		p->test();  
		//虚函数重写的是函数体的具体实现，继承的是父类的接口，包括参数列表
	}

}