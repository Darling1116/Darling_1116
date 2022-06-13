#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <array>

using namespace std;


//初始化列表
void test_1(){
	class Point{
	public:
		Point(int x = 0, int y = 0)
			: _x(x)
			, _y(y)
		{}

	private:
		int _x;
		int _y;
	};

	//内置类型
	int a = { 10 };  
	//自定义类型:单对象
	int* arr = new int[5]{1, 2, 3, 4, 5};  
	Point p1 = { 1, 2 };
	Point p2{ 1, 2 };
	//自定义类型:多对象，底层有initializer_list进行支持
	vector<Point> v1 = { Point(1, 2), Point{ 2, 3 } };
	vector<Point> v2{ { 1, 2 }, { 2, 3 } };
	
}

//decltype类型推导
void test_2(){
	const int x = 1;
	double y = 1.2;

	decltype(x * y) ret;
	decltype(&x) p;
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
}

//array
void test_3(){
	array<int, 10> a1;
	array<double, 5> a2;

	//cout << a1[10] << endl;
	cout << a1.at(4) << endl;
}

//左值、右值
void test_4(){
	int a = 5;
	cout << &a << endl;


	10;
	//cout << &10 << endl;
	int&& a1 = 10;
	cout << a1 << endl;

	//const左值引用可以引用右值
	const int& a2 = 10;
	cout << a2 << endl;

	//右值引用可以引用move后的左值
	int&& a3 = move(a);
	cout << a3 << endl;
}

//lambda表达式
void test_5(){
	struct Goods{
		string _name;
		double _price;
	};
	struct Compare{
		bool operator()(const Goods& gl, const Goods& gr){
			return gl._price <= gr._price;
		}
	};
	//使用仿函数，重载operator( )实现比较规则
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());

	//使用lambda表达式
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		[](const Goods& gl, const Goods& gr)->bool{return gl._price <= gr._price;});
}