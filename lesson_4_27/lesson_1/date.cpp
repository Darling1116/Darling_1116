#include "date.h"


//���캯��
Date::Date(int year, int month, int day){
	if (year >= 0 && month >= 1 && month <= 12 
		&& day >= 1 && day <= getMonthDay(year, month)){  //������ݵĺϷ���
		_year = year;
		_month = month;
		_day = day;
	}
	else{
		cout << "���ݲ��Ϸ�" << endl;
	}
}


//��ǰ���ڸı�
Date& Date::operator+=(int day){  //����thisָ�룬ָ��ǰ����
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

//��ǰ���ڲ��ı�
Date Date::operator+(int day){
	Date ret(*this);  //�õ�ǰ������һ���µĶ���
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
	//�������֮��_dayΪ������ֱ�ӷ��ص�ǰDate����
	//����Ҫ��ǰ��λ
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



int Date::getMonthDay(int year, int month){
	//�洢ÿ���µ������������±���Ƕ�Ӧ���·�
	static int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  
	int day = array[month];
	//�ж��Ƿ�������
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (month == 2)){
		day = 29;
	}
	return day;
}



void Date::Print(){
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}


//��������
Date::~Date(){

}