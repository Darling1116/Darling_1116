#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Date
{
public:
	bool IsLeapYear(int year)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetMonthDay(int year, int month)
	{
		int montharray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month ==2 && IsLeapYear(year))
		{
			return 29;
		}
		else
		{
			return montharray[month];
		}
	}

	//构造函数
	Date(int year = 2019, int month = 1, int day = 16)
	{
		if (year > 0 && month > 0 && month<13 && day>0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期输入有误" << endl;
		}
	}
	
	//拷贝复制函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//复制（赋值）
	//d1 = d
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//==    ！=
	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(operator==(d));
	}

	// >   <   >=   <=
	bool operator>(const Date& d)const
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Date& d)const
	{
		return !(operator==(d) || operator>(d));
	}

	bool operator>=(const Date& d)const
	{
		return !(operator<(d));
	}
	
	bool operator<=(const Date& d)const
	{
		return !(operator>(d));
	}

//+=   -=  this本身改变，要用引用，有返回值
	Date& operator+=(int days)
	{
		if (days<0)
		{
			return (*this) -= (-days);
		}
		_day += days;
		while (_day > GetMonthDay(_year,_month))
		{
			if (_month == 12)
			{
				_day -= GetMonthDay(_year, _month);
				_month = 1;
				++_year;
			}
			else 
			{
				_day -= GetMonthDay(_year, _month);
				++_month;
			}
		}
		return *this;
	}

	Date& operator-=(int days)
	{
		_day -= days;
		while (_day <= 0)
		{
			if (_month == 1)
			{
				_month = 12;
				--_year;
				_day += GetMonthDay(_year, _month);
			}
			else
			{
				--_month;
				_day += GetMonthDay(_year, _month);
			}
		}
		return *this;
	}


	Date operator-(int days)
	{
		//Date ret(*this);
		Date ret = *this;
		ret -= days;
		return ret;
	}
	Date operator+(int days)
	{
		Date ret(*this);
		ret += days;
		return ret;
	}

	//++d
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	//--d
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//d++
	Date operator++(int)
	{
		Date ret = (*this);
		(*this) += 1;
		return ret;
	}
	
	//d--
	Date operator--(int)
	{
		Date ret = (*this);
		(*this) -= 1;
		return ret;
	}


	//两个日期相减：d1 - d2
	 int operator-(const Date& d)const
	{
		int flag = 1;
		int day = 0;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (min != max)
		{
			min++;
			day++;
		}
		return day*flag;
	}


	void Print()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
		
private:
	int _year;
	int _month;
	int _day;
};


void Test1()
{
	Date d1(2019, 12, 29);
	d1.Print();
	Date d2(2019, 1, 13);
	d2.Print();
	//Date d3(d1);
	//d3.Print();
	//d1 = d2;
	//d1.Print();
}

void Test2()
{
	Date d1(2019, 2, 22);
	Date d2(2019, 2, 13);
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
}
void Test3()
{
	Date d1(2019, 1, 1);
//	d1 += -650;
//	d1 -= 2;
	d1.Print();
	printf("%d-%d-%d\n", d1 - 35);
	//printf("%d-%d-%d\n", d1 + 65);
	//++d1;
	//d1.Print();
	//--d1;
	//d1.Print();
	//printf("%d-%d_%d\n", d1++);
	//d1.Print();
	//printf("%d-%d-%d\n", d1--);
	//d1.Print();
}

void Test4()
{
	Date d1(2016, 1, 23);
	Date d2(2018, 4, 20);
	cout << (d1 - d2) << endl;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	system("pause");
	return 0;
}