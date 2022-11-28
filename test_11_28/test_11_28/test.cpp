#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//求 1 + 2 + ... + n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字

//1：利用递归
int sumNums_1(int n){
	if (n == 0)
		return 0;
	return n + sumNums_1(n - 1);
}

//2.利用类的静态成员变量和构造函数
class Add{
public:
	Add(){
		ret += count;
		count++;
	}

	static int GetRet(){
		return ret;
	}

	static void Init(){
		count = 1;
		ret = 0;
	}

private:
	static int count;
	static int ret;
};


//静态成员变量在类内声明，类外定义
int Add::count = 1;
int Add::ret = 0;

int sumNums_2(int n){
	Add::Init();
	for (int i = 0; i < n; i++){
		Add arr;
	}
	return Add::GetRet();
}

int main(){
	cout << sumNums_1(10) << endl;
	cout << sumNums_2(10) << endl;

	system("pause");
	return 0;
}