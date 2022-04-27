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

	~Date();

private:
	int _year;
	int _month;
	int _day;
};



