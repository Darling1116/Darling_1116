#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int array[6] = { 2, 3, 5, 6, 7, 8 };
	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	//{
	//	cout << array[i] << endl;

	//}
	/*for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		cout << 2 * array[i] << endl;
	}*/
	/*for (auto e : array)
	{
		cout << e << endl;
	}*/
	for (auto& e : array)
	{
		cout << e * 2 << endl;
	}
	system("pause");
	return 0;

}

//运行时获知变量类型名称，可以使用 typeid(变量).name()
//int main()
//{
//	int a = 10;
//	auto b = &a;
//	auto* c = &a;
//	auto& d = a;
//
//	cout << typeid (b).name() << endl;
//	cout << typeid (c).name() << endl;
//	cout << typeid (d).name() << endl;
//
//	system("pause");
//	return 0;
//
//}

//inline void func(int i);
//void func(int i)
//{
//	cout << i << endl;
//}
//int main()
//{
//	func(2);
//	system("pause");
//	return 0;
//}
//struct B
//{
//	int a[100000];
//};
//B a;
//B& Test1( )
//{
//	return a;
//}
//B Test2( )
//{
//	return a;
//}
//
//void Testtime()
//{
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; i++)
//	{
//		Test1( );
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; i++)
//	{
//		Test2();
//	}
//	size_t end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//
//}
//int main()
//{
//	Testtime();
//	system("pause");
//	return 0;
//}
//struct A
//{
//	int a[10000];
//};
//void TestFunc1(A a)
//{
//}
//void TestFunc2(A& a)
//{
//}
//void TestRefAndValue()
////int main( )
//{
//	A a;
//	// 以指针作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; i++)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//	//system("pause");
//	//return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		TestRefAndValue();
//	}
//	system("pause");
//	return 0;
//}

//int& Add(int& a)
//{
//	a = a + 10;
//	return a;
//}
//int main()
//{
//	int a = 20;
//	cout << Add(a) << endl;
//	system("pause");
//	return 0;
//}
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int x = 12;
//	int y = 13;
//	Swap(x, y);
//	cout << x << endl;
//	cout << y << endl;
//	system("pause");
//	return 0;
//
//}
//int main()
//{
//	const int a = 10;
//	const int& b = a;
//}
//int main()
//{
//	int a = 10;
//	int m = 12;
//	int& b = a;
//	int& c = b;
//	int& b = m;
//	cout << b << endl;
//	cout << c << endl;
//	system("pause");
//	return 0;
//}
//extern "C"  int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	Add(1, 3);
//	//printf("%d ", Add(1, 3));
//	system("pause");
//	return 0;
//}
//void func(int a , int b = 3,int c = 6)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//
//int main()
//{
//	
//	func(1);
//	func(1, 1);
//	func(1, 1, 1);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int N1 = 20;
//
//	cout << GXR::N << endl;
//	printf("%d ", GXR::N);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a;
//	cin >> a;
//	cout << "hello" << endl;
//	system("pause");
//	return 0;
//}

//int main ()
//{
//	cout << "hello" << endl;
//	int a = 0;
//	cin >> a;
//	system("pause");
//	return 0;
//}
