#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Date
{
public:
	Date(int year = 2020, int month = 1, int day = 1);  //����ʱ��ȱʡֵ

	void Print();

	int getMonthDay(int year, int month);

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	//����++/--:Ϊ������ǰ�õģ���������б����һ������
	Date operator++(int);
	Date operator--(int);

	//ǰ��++/--
	Date& operator++();
	Date& operator--();

	bool operator>(const Date& d);
	bool operator==(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator!=(const Date& d);


	//�����������
	int operator-(const Date& d);


	//��������
	Date(const Date& d);


	//��ֵ���������
	Date& operator=(const Date& d);

	~Date();  //��������

private:
	int _year;
	int _month;
	int _day;
};



