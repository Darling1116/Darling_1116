#include "unordermap.h"
#include "unorderset.h"

using namespace GXR;

//拷贝构造、赋值重载
void test(){
	unorder_set<int, int> set;
	set.Insert(1);
	set.Insert(2);
	set.Insert(5); 
	set.Insert(12);
	set.Insert(15);
	set.Insert(20);
	unorder_set<int, int>::iterator sit = set.begin();
	while (sit != set.end()){
		cout << *sit << " ";
		++sit;
	}
	cout << endl;


	unorder_map<int, int> map;
	int arr[] = { 12, 32, 5, 10, 6, 18 };
	for (auto&e : arr){
		map.Insert(make_pair(e, e));
	}

	//unorder_set<int, int> s(set);
	unorder_set<int, int> s;
	s = set;
	unorder_set<int, int>::iterator it = s.begin();
	while (it != s.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}



int main(){
	test();
	//unorderset_test();
	//unordermap_test();

	system("pause");
	return 0;
}