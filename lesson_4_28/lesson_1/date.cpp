#include "date.h"


//构造函数
Date::Date(int year, int month, int day){
	if (year >= 0 && month >= 1 && month <= 12 
		&& day >= 1 && day <= getMonthDay(year, month)){  //检查数据的合法性
		_year = year;
		_month = month;
		_day = day;
	}
	else{
		cout << "数据不合法" << endl;
	}
}


//当前日期改变
Date& Date::operator+=(int day){  //隐含this指针，指向当前对象
	_day += day;
	while (_day > getMonthDay(_year, _month)){
		_day -= getMonthDay(_year, _month);
		_month++;
		if (_month > 12){
			_year++;
			_month = 1;
		}
	}
	return *this;
}

//当前日期不改变
Date Date::operator+(int day){
	Date ret(*this);  //用当前对象构造一个新的对象
	ret._day += day;
	while (ret._day > getMonthDay(ret._year, ret._month)){
		ret._day -= getMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month > 12){
			ret._year++;
			ret._month = 1;
		}
	}
	return ret;
}


Date& Date::operator-=(int day){
	_day -= day;
	//如果减完之后_day为正数，直接返回当前Date对象
	//否则要往前退位
	while (_day <= 0){
		_month--;
		if (_month == 0){
			_year--;
			_month = 12;
		}
		_day += getMonthDay(_year, _month);
		
	}
	return *this;

}


Date Date::operator-(int day){
	Date ret(*this);
	ret._day -= day;
	while (ret._day <= 0){
		ret._month--;
		if (ret._month == 0){
			ret._year--;
			ret._month = 12;
		}
		ret._day += getMonthDay(ret._year, ret._month);
	}
	return ret;
}


Date Date::operator++(int){
	Date d1(*this);  //拷贝构造
	/*this->_day++;
	if (this->_day > getMonthDay(this->_year, this->_month)){
		this->_day -= getMonthDay(this->_year, this->_month);
		this->_month++;
		if (this->_month > 12){
			this->_year++;
			this->_month = 1;
		}
	}*/
	*this += 1;
	return d1;
}

Date Date::operator--(int){
	Date d1(*this);
	/*this->_day--;
	if (this->_day == 0){
		this->_month--;
		if (this->_month == 0){
			this->_year--;
			this->_month = 12;
		}
		this->_day = getMonthDay(this->_year, this->_month);
	}*/
	*this -= 1;
	return d1;
}

Date& Date::operator++(){
	*this += 1;
	return *this;
}


Date& Date::operator--(){
	*this -= 1;
	return *this;
}

bool Date::operator>(const Date& d){
	if (this->_year > d._year){
		return true;
	}
	else{
		if (this->_month > d._month){
			return true;
		}
		else{
			if (this->_day > d._day){
				return true;
			}
			else{
				return false;
			}
		}
	}
}

bool Date::operator==(const Date& d){
	if (this->_year == d._year && this->_month == d._month && this->_day == d._day){
		return true;
	}
	return false;
}

bool Date::operator>=(const Date& d){
	if (*this < d){
		return false;
	}
	return true;
}

bool Date::operator<(const Date& d){
	if (*this>d || *this == d){
		return false;
	}
	return true;
}


bool Date::operator<=(const Date& d){
	if (*this > d){
		return false;
	}
	return true;
}


bool Date::operator!=(const Date& d){
	if (*this == d){
		return false;
	}
	return true;
}


int Date::operator-(const Date& d){
	//首先确定日期大的为减数
	Date max = *this;
	Date min = d;
	int flag = 1;  //初始让*this为大的日期

	if (max < min){
		max = d;
		min = *this;
		flag = -1;
	}

	int count = 0;
	while (max != min){
		count++;
		++min;
	}
	return count*flag;
}


int Date::getMonthDay(int year, int month){
	//存储每个月的天数：数组下标就是对应的月份
	static int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  
	int day = array[month];
	//判断是否是闰年
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (month == 2)){
		day = 29;
	}
	return day;
}


void Date::Print(){
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}


//析构函数
Date::~Date(){

}