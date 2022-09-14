#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


//��1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���
//����---����ʱ������
int countDigitOne(int n) {
	int high = n;  //��λ��
	int low = 0;  //��λ��
	int cur = 0;  //��ǰλ
	int num = 1;  //��ǰλ����
	int count = 0;  //1���ֵĴ���

	while (high > 0){
		cur = high % 10;
		high /= 10;

		if (cur == 0)
			count += high * num;
		else if (cur == 1)
			count += high * num + low + 1;
		else
			count += (high + 1) * num;

		low = cur * num + low;
		num *= 10;
	}

	return count;
}




void test1_1(){
	int ret1 = countDigitOne(12);
	cout << ret1 << endl;
	int ret2 = countDigitOne(13);
	cout << ret2 << endl;
}