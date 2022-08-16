#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//2.����������:���ҳ�һ��λ�ã�ɾ���Ǹ���ĸ֮���ַ�����ɻ���
//�ܻ���һ���Ϸ��Ľ⣬����������ַ����Ѿ���һ�����Ĵ�����ô���-1��

//���룺��һ�а���T���������ݵ�����;�������T�У�ÿ�а���һ���ַ�����
//������������ɾȥһ����ĸʹ����ɻ��Ĵ������������һ������������ɾȥ��ĸ��λ��

bool isHuiwen(string str, int* begin, int* end){
	int left = 0;
	int right = str.length() - 1;
	while (left < right){
		if (str[left] == str[right]){
			left++;
			right--;
		}
		else{
			if (begin != nullptr)
				*begin = left;
			if (end != nullptr)
				*end = right;
			return false;
		}
	}
	return true;
}


void test2_1(){
	int n = 0;
	cin >> n;

	while (n){
		string str;
		cin >> str;

		int begin = 0;
		int end = 0;

		if (isHuiwen(str, &begin, &end)){
			cout << -1 << endl;
		}
		else{
			str.erase(begin, 1);
			if (isHuiwen(str, nullptr, nullptr))
				cout << begin << endl;
			else
				cout << end << endl;
		}
		n--;
	}
}