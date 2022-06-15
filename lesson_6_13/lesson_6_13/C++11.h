#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <array>
#include <functional>

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


void Fun(int &x){ cout << "lvalue ref" << endl; }
void Fun(int &&x){ cout << "rvalue ref" << endl; }
void Fun(const int &x){ cout << "const lvalue ref" << endl; }
void Fun(const int &&x){ cout << "const rvalue ref" << endl; }

template<typename T>
void PerfectForward(T &&t){ 
	Fun(std::forward<T>(t)); 
}

//左值、右值、完美转发
void test_4(){
	int a = 12;
	PerfectForward(a);
	PerfectForward(1);
	const int b = 22;
	PerfectForward(b);
	PerfectForward(std::move(b));

	//int a = 5;
	//cout << &a << endl;

	//10;
	////cout << &10 << endl;
	//int&& a1 = 10;
	//cout << a1 << endl;

	////const左值引用可以引用右值
	//const int& a2 = 10;
	//cout << a2 << endl;

	////右值引用可以引用move后的左值
	//int&& a3 = move(a);
	//cout << a3 << endl;

}

//递归获取可变参数模板中的各个参数
template <class T, class... Args>
//void showlist(T value, Args... args){
//	cout << value << " ";
//	showlist(args...);
//}
void showlist(T value, Args&&... args){  //增加万能引用
	cout << value << " ";
	showlist(args...);
}

//终止条件
template <class T>
void showlist(T& value){
	cout << value << endl;
}
//可变参数
void test_5(){
	int i = 100;
	showlist(1, 2, 3, i);
	showlist("haha", 1.2);
}

//lambda表达式
void test_6(){
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

	int a = 10; 
	int b = 20;
	auto swap1 = [](int& a, int& b){int tmp = a; a = b; b = tmp; };
	swap1(a, b);
	cout << a << " " <<  b << endl;
}


//包装器
template <class F, class T>
T useF(F f, T x){
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}

double func(double i){
	return i / 2;
}

struct Functor{
	double operator()(double d){
		return d / 3;
	}
};

class Plus{
public:
	double plus(double x, double y){
		return x + y;
	}
};

void test_7(){
	/*cout << useF(func, 11.11) << endl;
	cout << useF(Functor(), 11.11) << endl;
	cout << useF([](double d)->double{return d / 4; }, 11.11) << endl;*/

	//包装函数指针
	std::function<double(double)> f1 = func;
	cout << f1(3) << endl;
	//包装仿函数
	std::function<double(double)> f2 = Functor();
	cout << f2(5) << endl;
	//包装成员函数
	std::function<double(Plus, double, double)> f3 = &Plus::plus;
	cout << f3(Plus(), 1.0, 12.0) << endl;
	//包装lambda表达式
	auto f4 = [](double x, double y){return x*y; };
	std::function<double(double, double)> f5 = f4;
	cout << f5(12.0, 2.0) << endl;
}