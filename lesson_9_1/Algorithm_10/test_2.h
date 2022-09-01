#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int strToInt(string& str){
	int num = 0;
	for (int i = 0; i < str.length(); i++){
		num = num * 10 + str[i] - '0';
	}
	return num;
}

//一年中的第几天
//输入：2019 - 01 - 09   输出：9
void test2_1(){
	string str;
	cin >> str;

	string v[3] = { "" };
	string sstr = "";
	int index = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == '-'){
			v[index++] = sstr;
			sstr = "";
		}
		else{
			sstr += str[i];
		}
	}
	v[2] = sstr;

	int year = strToInt(v[0]);
	int month = strToInt(v[1]);
	int day = strToInt(v[2]);

	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int total_day = 0;
	for (int i = 1; i < month; i++){
		total_day += days[i];
	}

	if (month > 2){
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
			total_day++;
		}
	}

	total_day += day;

	cout << total_day << endl;


}