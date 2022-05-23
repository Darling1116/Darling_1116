#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void test_1(){
	map<int, string> m1;
	m1.insert(pair<int, string>(1, "orange"));
	m1.insert(make_pair(2, "apple"));


	map<int, string>::iterator it = m1.begin();
	while (it != m1.end()){
		cout << (*it).first << ": " << (*it).second << endl;
		it++;
	}

	auto ret = m1.find(2);
	string& str = ret->second;
	str.insert(str.size(), "--�ó�");

	for (auto e : m1){
		cout << e.first << ": " << e.second << endl;
	}
	
}

//ʵ�ּ������ܵ�3�ַ���
void test_2(){
	string str[] = { "haha", "xixi", "yaya", "xixi", "xixi", "yaya", "xixi", "haha", "haha" };
	map<string, int> m1;
	typedef map<string, int>::iterator Ite;

	//1.ʹ��find��insert����
	//for (const auto&e : str){
	//	Ite it = m1.find(e);
	//	if (it != m1.end())
	//		it->second++;
	//	else
	//		m1.insert(make_pair(e, 1));
	//}

	//2. ����insert�����ķ���ֵ
	//map<int, string> new_map;
	//for (const auto&e : str){
	//	auto ret = m1.insert(make_pair(e, 1));
	//	if (ret.second == false)
	//		ret.first->second++;
	//}


	//3. ����operator[ ]
	for (const auto&e : str){
		m1[e]++;
	}

	for (auto const&e : m1){
		cout << e.first << ": " << e.second << endl;
	}


}

//����һ���º������涨vector�е�Ԫ�رȽϹ���
struct IteCompare{
	bool operator()(map<string, int>::iterator& it1, map<string, int>::iterator& it2){
		return it1->second > it2->second;
	}
};

//ȡ���ִ�������ǰk�����ݵ�2�ַ���
void test_3(){
	string str[] = { "haha", "xixi", "yaya", "xixi", "xixi", "yaya", "xixi", "haha", "haha", "lala", "mimi"};
	map<string, int> m1;
	for (const auto&e : str){
		m1[e]++;
	}
	//for (const auto& e : m1){
	//	cout << e.first << ": " << e.second << endl;
	//}

	//1.����vector���洢map�ĵ�������ͨ��������������pair
	//Ȼ�������Զ���ķº�������vector�е����ݽ�������
	/*vector<map<string, int>::iterator> v;
	map<string, int>::iterator it = m1.begin();
	while (it != m1.end()){
		v.push_back(it);
		it++;
	}
	sort(v.begin(), v.end(), IteCompare());
	int k = 3;
	for (int i = 0; i < k; i++){
		cout << v[i]->first << ": " << v[i]->second << endl;
	}*/

	//2.����һ���µ�new_map
	map<int, string, greater<int>> new_map;
	for (const auto& e : m1){
		new_map.insert(make_pair(e.second, e.first));
	}
	map<int, string>::iterator it = new_map.begin();
	//map<int, string>::reverse_iterator it = new_map.rbegin();
	int k = 3;
	while (k > 0){
		cout << it->first << ": " << it->second << endl;
		it++;
		k--;
	}

}

