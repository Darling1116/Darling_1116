#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//������������С������
//����1���ô����ÿ������1��ֱ��������ͬʱ��������������
void test3_1(){
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int max = a > b ? a : b;
	while (1){
		if (max%a == 0 && max%b == 0){
			printf("%d\n", max);
			break;
		}
		max++;
	}
}

//����1��ȱ�㣺�����������ܴ�ʱ��ѭ�������϶�
//����2�� ����a*n%b==0���ж�
void test3_2(){
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int n = 1;
	while (n){
		if (a*n%b == 0){
			printf("%d\n", a*n);
			break;
		}
		n++;
	}
}