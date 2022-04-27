#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

int main(){
	Date d1;
	d1.Print();

	Date d2(2020, 4, 20);
	d2.Print();

	//d2 += 12;
	//d2.Print();

	//(d2 + 12).Print();
	//d2.Print();

	//d2 -= 22;
	//d2.Print();

	(d2 - 12).Print();
	d2.Print();

	//cout << d2.getMonthDay(2020, 2) << endl;
	system("pause");
	return 0;

}

