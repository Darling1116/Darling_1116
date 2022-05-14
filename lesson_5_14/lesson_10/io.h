#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>


using namespace std;

void test_1(){
	string s;

	//cin：遇到空格或换行就结束
	//cin >> s;  //使用cin只能拿到空格以前的内容
	//cout << s << endl;

	getline(cin, s);
	cout << s << endl;

}

void test_2(){
	string str;

	//持续接受输入
	//C++中：以ctrl+c结束输入
	while (cin >> str){  //调用的是string的operator>>(cin，str)，返回的是cin对象
		cout << str << endl;
	}

	//C语言中：用EOF判断
	string s;
	while (scanf("%s", s) != EOF){
		printf("%s\n", s);
	}

}

