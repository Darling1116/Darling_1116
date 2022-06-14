#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>

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
	StackClass_2(){

	}
	
	void print(){
		cout << "getStackClass_2" << endl;
	}
private:
	void* operator new(size_t size) = delete;
	//void operator delete(void* p) = delete;
};

void test_2(){
	StackClass_1::getclass().print();
	StackClass_2 st;
	st.print();
}


//���ܱ��������ࣺ
//1.���캯���͸�ֵ����ֻ���������壬������Ƴ�˽��
class NoCopyClass_1{
public:
	NoCopyClass_1(){}
	void print(){
		cout << "NoCopyClass_1" << endl;
	}

private:
	NoCopyClass_1(const NoCopyClass_1& nc){};
	NoCopyClass_1& operator=(NoCopyClass_1 nc){};
};

//2.������ص�Ĭ�ϳ�Ա����
class NoCopyClass_2{
public:
	NoCopyClass_2(){}
	void print(){
		cout << "NoCopyClass_2" << endl;
	}

private:
	NoCopyClass_2(const NoCopyClass_2& t) = delete;
};

void test_3(){
	NoCopyClass_1 nc;
	nc.print();
	//NoCopyClass nc_c(nc);
	//NoCopyClass copy;
	//copy = nc;

	NoCopyClass_2 nc2;
	nc2.print();
	//NoCopyClass_2 nc3(nc2);
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
//2.����final�ؼ���

void test_4(){
	//Student s;
	//s.print();
	//s.print_s();
}

//����ģʽ
class Singleton_1{
public:
	static Singleton_1* getInstance(){
		return ptr;
	}
	void print(){
		cout << "getInstance" << endl;
	}

private:
	Singleton_1(){}
	Singleton_1(const Singleton_1&) = delete;
	Singleton_1& operator = (const Singleton_1&) = delete;
	static Singleton_1* ptr;
};

Singleton_1* Singleton_1::ptr = new Singleton_1;

//����ģʽ
class Singleton_2{
public:
	
	static Singleton_2* getInstace(){
		static mutex _mutex;
		if (str == nullptr){
			if (str == nullptr){
				_mutex.lock();
				str = new Singleton_2;
				_mutex.unlock();
				
			}
		}
		return str;
	}
private:
	Singleton_2(){};
	Singleton_2(const Singleton_2&)= delete;
	Singleton_2& operator=(Singleton_2&) = delete;
	static Singleton_2* str;
};
Singleton_2* Singleton_2::str = nullptr;

void test_5(){
	cout << Singleton_1::getInstance() << endl;
	cout << Singleton_1::getInstance() << endl;
	cout << Singleton_1::getInstance() << endl;
	Singleton_1* s = Singleton_1::getInstance();
	s->print();

	cout << Singleton_2::getInstace() << endl;
	cout << Singleton_2::getInstace() << endl;
	cout << Singleton_2::getInstace() << endl;

}