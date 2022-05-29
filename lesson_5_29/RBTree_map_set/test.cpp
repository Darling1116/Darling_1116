#include "map.h"
#include "set.h"

//BRTree实现map和set
void test_1(){
	GXR::map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(3, 3));
	m.Insert(make_pair(0, 0));
	m.Insert(make_pair(5, 5));
	m.Insert(make_pair(6, 6));
	GXR::map<int, int>::iterator mit = m.begin();
	while (mit != m.end()){
		cout << (*mit).first << ": " << (*mit).second << " ";
		//cout << it->first << ": " << it->second << " ";
		++mit;
	}
	cout << endl;


	GXR::set<int, int> s;
	s.Insert(1);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	s.Insert(4);
	s.Insert(5);
	GXR::set<int, int>::iterator sit = s.begin();
	while (sit != s.end()){
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

//实现map和set中的正反向迭代器
void test_2(){

	GXR::set<int, int> s;
	s.Insert(1);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	s.Insert(6);
	s.Insert(8);
	GXR::set<int, int>::iterator sit = s.begin();
	while (sit != s.end()){
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	GXR::set<int, int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend()){
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;

	GXR::map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(3, 3));
	m.Insert(make_pair(0, 0));
	m.Insert(make_pair(5, 5));
	m.Insert(make_pair(6, 6));
	GXR::map<int, int>::iterator mit = m.begin();
	while (mit != m.end()){
		cout << (*mit).first << ": " << (*mit).second << " ";
		//cout << it->first << ": " << it->second << " ";
		++mit;
	}
	cout << endl;

	GXR::map<int, int>::reverse_iterator rmit = m.rbegin();
	while (rmit != m.rend()){
		cout << (*rmit).first << ": " << (*rmit).second << " ";
		//cout << it->first << ": " << it->second << " ";
		++rmit;
	}
	cout << endl;

}

//实现map中的operator[ ] 
void test_3(){
	GXR::map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(3, 3));
	m.Insert(make_pair(0, 0));
	m.Insert(make_pair(5, 5));

	m[1] = 10;
	m[5] = 100;
	m[100] = 1000;
	m.Insert(make_pair(6, 6));
	GXR::map<int, int>::iterator mit = m.begin();
	while (mit != m.end()){
		cout << (*mit).first << ": " << (*mit).second << " ";
		//cout << it->first << ": " << it->second << " ";
		++mit;
	}
	cout << endl;
}

int main(){
	
	//test_1();
	//test_2();
	test_3();
	system("pause");
	return 0;
}