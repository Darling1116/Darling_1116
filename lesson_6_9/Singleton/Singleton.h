#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//只在堆上创建类对象:
//构造函数私有化，在静态成员函数中完成堆对象的创建
class HeapClass{ 
public:
	static HeapClass* getclass(){
		return new HeapClass();
	}

	void print(){
		cout << "getHeapClass" << endl;
	}

private:
	HeapClass(){}
	HeapClass(const HeapClass& hc){}
};

void test_1(){
	HeapClass* hc = HeapClass::getclass();
	hc->print();
}


//只在栈上创建类对象:
//1.构造函数私有化，在静态成员函数中完成栈对象的创建
class StackClass_1{
public:
	static StackClass_1 getclass(){
		return StackClass_1();  //返回一个局部对象
	}

	void print(){
		cout << "getStackClass_1" << endl;
	}
private:
	StackClass_1(){}
	StackClass_1(const StackClass_1& sc){}
};

//2.构造函数公有化，屏蔽new
class StackClass_2{
public:

	
private:
	
};

void test_2(){
	StackClass_1::getclass().print();
}


//不能被拷贝的类：
//1.构造函数和赋值重载只声明不定义，并且设计成私有
class NoCopyClass{
public:
	NoCopyClass(){}
	void print(){
		cout << "NoCopyClass" << endl;
	}

private:
	NoCopyClass(const NoCopyClass& nc){};
	NoCopyClass& operator=(NoCopyClass nc){};
};

void test_3(){
	NoCopyClass nc;
	nc.print();
	//NoCopyClass nc_c(nc);
	//NoCopyClass copy;
	//copy = nc;
}


//不能被继承的类：
//1.构造函数私有化，派生类中调不到基类的构造函数，无法继承
class Person{
public:
	void print(){
		cout << "Person" << endl;
	}
private:
	Person(){}
};


class Student : public Person{
public:
	void print_s(){
		cout << "Student" << endl;
	}
};

void test_4(){
	//Student s;
	//s.print();
	//s.print_s();
}
