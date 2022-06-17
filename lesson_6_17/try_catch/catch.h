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
		cout << "³ý0´íÎó..."  << endl;
	}
}