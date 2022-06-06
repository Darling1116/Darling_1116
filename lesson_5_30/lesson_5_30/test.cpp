#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//�ײ��ǹ�ϣ�ṹ���������򣬻���������map��set����
void test_unordered_set(){
	unordered_set<int> set;
	set.insert(2);
	set.insert(1);
	set.insert(5);
	set.insert(3);
	set.insert(6);
	set.insert(2);
	set.insert(2);

	unordered_set<int>::iterator it = set.begin();
	while (it != set.end()){
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto &e : set){
		cout << e << " ";
	}
	cout << endl;
}

void test_unordered_map(){
	unordered_map<int, string> m;
	m.insert(make_pair(1, "����"));
	m.insert(make_pair(3, "���"));
	m.insert(make_pair(5, "����"));
	m.insert(make_pair(2, "��ͣ"));
	unordered_map<int, string>::iterator it = m.begin();
	while (it != m.end()){
		cout << (*it).first << ": " << (*it).second << " ";
		it++;
	}
	cout << endl;

	m[2] = "�޸�";
	m[10] = "����";

	for (auto&e : m){
		cout << e.first << ": " << e.second << " ";
	}
	cout << endl;
}

void test(){
	unordered_set<int> set;
	cout << "�����������Ϊ�� " << set.max_load_factor() << " ";
}


int main(){
	/*test_unordered_set();
	test_unordered_map();*/
	test();

	system("pause");
	return 0;
}