#pragma once
#include <iostream>

using namespace std;

//判断大小端
void isXiaoDuan_1(){
	int i = 1;
	if (*((char*)&i) == 1){
		cout << "小端" << endl;
	}
	else
		cout << "大端" << endl;
}


union Un{
	char a;
	int i;
};
void isXiaoDuan_2(){
	Un un;
	un.i = 1;
	if (un.a == 1){
		cout << "小端" << endl;
	}
	else
		cout << "大端" << endl;
}

void test_1(){
	isXiaoDuan_1();
	isXiaoDuan_2();
}