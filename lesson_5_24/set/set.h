#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;



void test_1(){
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(12);
	s.insert(11);
	s.insert(3);

	set<int>::iterator pos = s.find(3);
	cout << *pos << endl;

	s.erase(pos);

	//set默认的作用：排序+去重
	set<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	s.erase(12);
	for (auto&e : s){
		cout << e << " ";
	}
	cout << endl;
}

void test_2(){
	multiset<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(12);
	s.insert(11);
	s.insert(3);

	multiset<int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

}