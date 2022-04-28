#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

int main(){
	Date d1;
	d1.Print();

	Date d2(2020, 12, 3);
	d2.Print();

	Date d3(d2);
	d3.Print();

	d1 = d3;
	d1.Print();

	//d2 += 12;
	//d2.Print();

	//(d2 + 12).Print();
	//d2.Print();

	//d2 -= 22;
	//d2.Print();

	//(d2 - 12).Print();
	//d2.Print();

	//d2++.Print();
	//d2.Print();

	//++d1;
	//d1.Print();


	//int count1 = d1 - d2;
	//cout << count1 << endl;

	//int count2 = d2 - d1;
	//cout << count2 << endl;

	//d2--.Print();
	//d2.Print();

	//bool ret1 = d2 > d1;
	//cout << ret1 << endl;

	//bool ret2 = d2 == d1;
	//cout << ret2 << endl;

	//bool ret3 = d2 <= d1;
	//cout << ret3 << endl;

	//cout << d2.getMonthDay(2020, 2) << endl;
	system("pause");
	return 0;

}

