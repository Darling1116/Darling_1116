#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void test_1(){
	try{
		char* a = new char[0x7fffffff];
	}
	catch (exception &e){
		cout << e.what() << endl;
	}
}

void func_1(){
	int i, j;
	cin >> i >> j;
	if (j == 0){
		throw 1;
	}
	cout << i / j << endl;
}

void test_2(){
	try{
		func_1();
	}
	catch(int errid){
		cout << "��0����..."  << endl;
	}
}

//�쳣�������׳�
double Division(int a, int b) {
	// ��b == 0ʱ�׳��쳣
	if (b == 0){
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func(){
	// ���������0�����׳��쳣�������arrayû�еõ��ͷţ�������ڴ�й©
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ�����������׳�ȥ
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	cout << "delete []" << array << endl;
	delete[] array;
}
void test_3(){
	try{
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
}