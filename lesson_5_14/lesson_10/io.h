#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

void test_1(){
	string s;

	//cin�������ո���оͽ���
	//cin >> s;  //ʹ��cinֻ���õ��ո���ǰ������
	//cout << s << endl;

	getline(cin, s);
	cout << s << endl;

}

void test_2(){
	string str;

	//������������
	//C++�У���ctrl+c��������
	while (cin >> str){  //���õ���string��operator>>(cin��str)�����ص���cin����
		cout << str << endl;
	}

	//C�����У���EOF�ж�
	string s;
	while (scanf("%s", s) != EOF){
		printf("%s\n", s);
	}

}

