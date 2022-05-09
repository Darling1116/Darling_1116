#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void test_1(){
	//vector<int> v = { 1, 2, 3, 4, 5 };
	//v.push_back(6);
	string s("hahaha");
	vector<char> v(s.begin(), s.end());

	for (size_t i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	//v.insert(pos, 10);  //在pos位置之前插入10
	//vector<int>::iterator it = v.begin();
	//while (it != v.end()){
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;
}


void test_2(){
	vector<int> v = { 1, 2, 3, 4, 5 };

	//vector<int> v(5, 3);
	//v.push_back(6);

	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		if (*it % 2 == 0){
			it = v.erase(it);
		}
		else{
			it++;
		}
	}
	for (auto e : v){
		cout << e << " ";
	}
	cout << endl;
}



int main(){
	//test_1();
	test_2();

	system("pause");
	return 0;
}