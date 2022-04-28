#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Date
{
public:
	Date(int year = 2020, int month = 1, int day = 1);  //声明时给缺省值

	void Print();

	int getMonthDay(int year, int month);

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	//后置++/--:为了区分前置的，给其参数列表加了一个参数
	Date operator++(int);
	Date operator--(int);

	//前置++/--
	Date& operator++();
	Date& operator--();

	bool operator>(const Date& d);
	bool operator==(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator!=(const Date& d);


	//两个日期相减
	int operator-(const Date& d);


	//拷贝构造
	Date(const Date& d);


	//赋值运算符重载
	Date& operator=(const Date& d);

	~Date();  //析构函数

private:
	int _year;
	int _month;
	int _day;
};



