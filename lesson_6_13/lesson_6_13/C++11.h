#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <array>

using namespace std;


//��ʼ���б�
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

	//��������
	int a = { 10 };  
	//�Զ�������:������
	int* arr = new int[5]{1, 2, 3, 4, 5};  
	Point p1 = { 1, 2 };
	Point p2{ 1, 2 };
	//�Զ�������:����󣬵ײ���initializer_list����֧��
	vector<Point> v1 = { Point(1, 2), Point{ 2, 3 } };
	vector<Point> v2{ { 1, 2 }, { 2, 3 } };
	
}

//decltype�����Ƶ�
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

//��ֵ����ֵ
void test_4(){
	int a = 5;
	cout << &a << endl;


	10;
	//cout << &10 << endl;
	int&& a1 = 10;
	cout << a1 << endl;

	//const��ֵ���ÿ���������ֵ
	const int& a2 = 10;
	cout << a2 << endl;

	//��ֵ���ÿ�������move�����ֵ
	int&& a3 = move(a);
	cout << a3 << endl;
}

//lambda���ʽ
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
	//ʹ�÷º���������operator( )ʵ�ֱȽϹ���
	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());

	//ʹ��lambda���ʽ
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		[](const Goods& gl, const Goods& gr)->bool{return gl._price <= gr._price;});
}