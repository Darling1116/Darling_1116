#include "smart_ptr.h"

using namespace GXR;

int Division(){
	int i, j;
	cin >> i >> j;
	if (j == 0){
		throw invalid_argument("除0错误");
	}
	return i / j;
}

void fun_1(){
	int *p = new int;
	//把指针p交给sp这个对象去处理
	smart_ptr<int> sp(p);
	cout << Division() << endl;
	/*try{
		cout << Division() << endl;
	}
	catch (...){
		cout << "delete p" << endl;
		delete p;
		throw;
	}*/
}

void test_1(){
	try{
		fun_1();
	}
	catch (exception& e){
		cout << e.what() << endl;
	}
}

int main(){
	test_1();
	system("pause");
	return 0;
}