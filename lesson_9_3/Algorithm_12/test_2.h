#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

//�ַ���ѹ���㷨
//���룺xxxxyyyyyyzbbb    �����3x5yz2b

void test2_1(){
	string str;
	getline(cin, str, '\n');  //��\n��������

	int i = 0;
	while (i < str.length()){
		if (i + 1 < str.length() && str[i] == str[i + 1]){
			int count = 0;
			while (i + 1 < str.length() && str[i] == str[i + 1]){
				count++;
				i++;
			}
			cout << count << str[i];
			i++;
		}
		else{
			cout << str[i];
			i++;
		}
	}
}