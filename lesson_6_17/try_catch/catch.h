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
		cout << "除0错误..."  << endl;
	}
}

//异常的重新抛出
double Division(int a, int b) {
	// 当b == 0时抛出异常
	if (b == 0){
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func(){
	// 如果发生除0错误抛出异常，下面的array没有得到释放，会造成内存泄漏
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再重新抛出去
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