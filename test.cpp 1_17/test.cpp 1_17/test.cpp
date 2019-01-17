#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

//class A
//{
//public:
//
//	A(int a)
//		:_a(a)
//	{
//
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public :
//	Date(int year=2910, int month=9, int day=8)
	/*	Date(int n=12 ,int b=9)*/
		/*:_year(year)
		,_month ( month)
		,_day (10)*/
	/*	: _N(68)
		, _ref(ref)
		, B(b)*/
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
//	//void Print()
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;
//	//}
//
//private:
//	/*int _year;
//	int _month;
//	int _day;*/
//	const int _N;
//	//int& _ref;
//	 A B;
//
//};


//class Date
//{
//public:
//	/*Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)*/
//	Date(int year)
//		:_year(year)
//	    {
//	
//		}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{ 
//	Date d1(2018);
//	Date d2 = d1;
//	Date d3 = 2019;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	Date d1(2018);
//	Date d2 = 2013;
//	Date d3 = d2;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	Date(2018).Print();
//	system("pause");
//	return 0;
//}
//
//class A
//{
//public:
//	A( )
//	{
//		count++;
//	}
//	A(const A& a)
//	{
//		count++;
//	}
//
//	static int Getcount()
//	{
//		return count;
//	}
//
//private:
//	static int count;
//};
//
//int A::count = 0;
//int main()
//{
//	cout << A::Getcount() << endl;
//	A d1;
//	A d2 = d1;
//	A d3(d1);
//	cout << A::Getcount() << endl;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	cout << A::Getcount() << endl;
//	A d1;
////	A d3 = d1;
////	A d2(d1);
//	//d3 = d1;
//  cout << A::Getcount() << endl;
//	system("pause");
//	return 0;
//}


//class A
//{
//public:
//
//	void Print()
//	{
//		cout << a << endl;
//		cout << *p << endl;
//	}
//private:
//	int a = 9;
//	int* p = (int*)malloc(sizeof(int)* 4);
//};
//
//int main()
//{
//	A d1;
//	d1.Print();
//
//}


class Date
{
	friend ostream& operator>>(ostream& out, const Date& d);
	friend istream& operator >>(istream& in, Date& d);

public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		/*_year = year;
		_month = month;
		_day = day;*/
	}

	
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;

	}

	int _year;
	int _month;
	int _day;
};

ostream& operator <<(ostream& out, const Date &d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator >>(istream& in, Date &d)
{
	in >> d._year;
	in >> d._month;
	in >> d._day;
	return in;
}
int main()
{
	Date d1;
	//cout << d1;
	cin >> d1;
	cout << d1 << endl;


	system("pause");
	return 0;
}