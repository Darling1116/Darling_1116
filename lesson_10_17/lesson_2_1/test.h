#pragma once
#include <iostream>

using namespace std;

//�жϴ�С��
void isXiaoDuan_1(){
	int i = 1;
	if (*((char*)&i) == 1){
		cout << "С��" << endl;
	}
	else
		cout << "���" << endl;
}


union Un{
	char a;
	int i;
};
void isXiaoDuan_2(){
	Un un;
	un.i = 1;
	if (un.a == 1){
		cout << "С��" << endl;
	}
	else
		cout << "���" << endl;
}

void test_1(){
	isXiaoDuan_1();
	isXiaoDuan_2();
}