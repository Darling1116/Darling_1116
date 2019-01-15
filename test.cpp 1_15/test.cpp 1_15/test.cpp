#include "test.h"
class Data
{
public:
	int IsLeapYear(int year)
	{
		if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year))
		{
			return 29;
		}
		else
		{
			return monthArray[month];
		}
	}

	Data(int year = 2019, int month = 1, int day = 15)
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

	Data(const Data& data1)
	{
		_year = data1._year;
		_month = data1._month;
		_day = data1._day;
	}

	bool operator==(const Data& data2)
	{
		return  _year == data2._year&&
			   _month == data2._month&&
			   _day == data2._day;
	}

	bool operator!=(const Data& data2)
	{
		return _year != data2._year ||
			_month != data2._month ||
			_day != data2._day;
	}

	bool operator>(const Data& data2)
	{
		if (_year > data2._year)
		{
			return true;
		}
		else if (_year == data2._year)
		{
			if (_month > data2._month)
			{
				return true;
			}
			else if (_month == data2._month)
			{
				if (_day > data2._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool operator>=(const Data& data2)
	{
		if (_year > data2._year)
			return true;
		else if (_year == data2._year)
		{
			if (_month > data2._month)
				return true;
			else if (_month == data2._month)
			{
				if (_day >= data2._day)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
  

	Data& operator=(const Data& data2)
	{
		if (this != &data2)//取地址
		{
			_year = data2._year;
			_month = data2._month;
			_day = data2._day;
			
		}
		return *this;
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

//
//bool operator==(const Data& data1, const Data& data2)
//{
//	return data1._year == data2._year &&
//		data1._month == data2._month &&
//		data1._day == data2._day;
//
//}
int main()
{/*
	Data data1;
	Data data2;*/

	Data data1 (2017, 1, 18);

	data1.Print();
	Data data2 (2019, 2, 18);
	
	data2.Print();

	//Data copy(data1);
	//copy.Print();

	//cout << (data1 == data2) << endl;
	/*cout << (data1 != data2) << endl;*/
	//cout << (data1 > data2) << endl;
	//cout << (data1 >= data2) << endl;
	//data1 = data2;
	
	//data1.Print();
	//data2.Print();

	
	system("pause");
	return 0;

}

//typedef int SEDataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_array = (SEDataType*)malloc(sizeof(int)*capacity);
//		assert (_array);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~SeqList()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//
//private:
//	int* _array;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	//SeqList sq;
//	SeqList sq( );
//	system("pause");
//	return 0;
//
//}
//class Data
//{
//public:
	//void Init(int year, int month, int data)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	//Data(int year = 2019, int month = 1, int day = 15)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	/*Data()
	{
		_year = 2019;
		_month = 1;
		_day = 16;
	}*/
//	void Print()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Data d1;
//	//d1.Init(2019, 1, 12);
//	//Data d1 (2019,1,12);
//	d1.Print();
//	Data d2;
//	//d2.Init(2019, 1, 13);
//	//Data d2(2019, 1, 13);
//	d2.Print();
//
//
//	system("pause");
//	return 0;
//
//}