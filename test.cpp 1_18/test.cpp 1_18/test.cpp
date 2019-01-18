#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date()
//		:_a(0)
//	{
//		cout << "Date()" << this << endl;
//	}
//
//
//	~Date()
//	{
//		cout << "~Date()" << this << endl;
//	}
//
//
//private:
//	int _a;
//};
//
//int main()
//{
	//Date* d1 = (Date*)malloc(sizeof(Date));
	//printf("%d ", d1);


	//free(d1);
	//Date* d2 = (Date*)malloc(sizeof(Date));
	//printf("%d ", d2);
	//free(d2);
//
//	Date* d1 = new Date;
//	Date* d2 = new Date;
//
//	cout << d1 << endl;
//	cout << d2 << endl;
//
//	delete d1;
//	delete d2;
//
//	system("pause");
//	return 0;
//}


//int main()
//{
//	void* p = new char[0xfffffffful];
//	cout << "new:" << p << endl;
//	system("pause");
//	return 0;
//}class Date{	friend ostream& operator<<(ostream& out, Date& d);	friend istream& operator>>(istream& in, const Date& d);public:	Date(int year, int month, int day)		:_year(year)		, _month(month)		, _day(day)	{	}private:	int _year;	int _month;	int _day;};ostream& operator<<(ostream& out,  Date& d){	out << d._year << "-" << d._month << "-" << d._day << endl;	return out;}istream& operator>>(istream& in, const Date& d){	in >> d._year;	in >> d._month;	in >> d._day;	return in;	}int main( ){	Date d2();	Date d1(2019,1,2);	cout << d1;	system("pause");	return 0;}