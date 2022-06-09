#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//ֻ�ڶ��ϴ��������:
//���캯��˽�л����ھ�̬��Ա��������ɶѶ���Ĵ���
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


//ֻ��ջ�ϴ��������:
//1.���캯��˽�л����ھ�̬��Ա���������ջ����Ĵ���
class StackClass_1{
public:
	static StackClass_1 getclass(){
		return StackClass_1();  //����һ���ֲ�����
	}

	void print(){
		cout << "getStackClass_1" << endl;
	}
private:
	StackClass_1(){}
	StackClass_1(const StackClass_1& sc){}
};

//2.���캯�����л�������new
class StackClass_2{
public:

	
private:
	
};

void test_2(){
	StackClass_1::getclass().print();
}


//���ܱ��������ࣺ
//1.���캯���͸�ֵ����ֻ���������壬������Ƴ�˽��
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


//���ܱ��̳е��ࣺ
//1.���캯��˽�л����������е���������Ĺ��캯�����޷��̳�
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
