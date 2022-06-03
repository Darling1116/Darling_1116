#include "unordermap.h"
#include "unorderset.h"

using namespace GXR;

void test(){
	unorder_set<int, int> set;
	set.Insert(1);
	set.Insert(2);
	set.Insert(5); 
	set.Insert(12);
	set.Insert(15);
	set.Insert(20);

	unorder_map<int, int> map;
	int arr[] = { 12, 32, 5, 10, 6, 18 };
	for (auto&e : arr){
		map.Insert(make_pair(e, e));
	}
}



int main(){
	//test();
	unorderset_test();
	unordermap_test();
	system("pause");
	return 0;
}