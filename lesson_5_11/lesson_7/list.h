#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>

using namespace std;

void test_1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	list<int> l1(a, a+5); //这里使用的是迭代器的区间构造对象

	list<int>::iterator it = l1.begin();
	while (it != l1.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_2(){
	list<int> l2(3, 0);
	l2.push_back(6);
	l2.push_back(0);
	l2.push_back(0);
	l2.push_back(0);
	for (auto e : l2){
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator pos = find(l2.begin(), l2.end(), 6);
	cout << *pos << endl;
	l2.insert(pos, 100);
	for (auto e : l2){
		cout << e << " ";
	}
	cout << endl;
	cout << *pos << endl;

	l2.erase(pos);
	for (auto e : l2){
		cout << e << " ";
	}
}


void test_3(){
	int a[9] = { 1, 2, 3, 3, 3, 4, 5 ,2, 5};
	list<int> l3(a, a + 9);
	for (auto e : l3){
		cout << e << " ";
	}
	cout << endl;

	l3.remove(2);
	for (auto e : l3){
		cout << e << " ";
	}
	cout << endl;

	l3.unique();
	for (auto e : l3){
		cout << e << " ";
	}
	cout << endl;
}

