#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>


using namespace std;

void nextval(string& sub, vector<int>& next){
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k = 0;  //��ʾǰһ���nextֵ
	while(i < sub.length()){
		if (k == -1 || sub[i - 1] == sub[k]){
			next[i] = k + 1;
			i++;
			k++;
		}
		else{
			k = next[k];  //�Ӵ�����
		}
	}
}


int kmp(string& str, string& sub, int pos){
	if (str.empty() || sub.empty())
		return -1;
	if (str.length() == 0 || sub.length() == 0)
		return -1;
	if (pos < 0 || pos >= str.length())
		return -1;

	int i = pos;  //��������
	int j = 0;  //�����Ӵ�

	vector<int> next(sub.length(), 0);
	nextval(sub, next);

	while (i < str.length() && j < sub.length()){
		if (j == -1 || str[i] == sub[j]){
			//j���˵������λ�õ�ǰһλ
			i++;
			j++;
		}
		else{
			//iָ�벻���ˣ�jָ����˵�һ�����ʵ�λ��
			j = next[j];
		}
	}
	if (j >= sub.length()){
		return i - j;
	}
	return -1;
}


void test(){
	string str = "ababbaaabcd";
	string sub = "abcd";
	cout << kmp(str, sub, 0) << endl;

}