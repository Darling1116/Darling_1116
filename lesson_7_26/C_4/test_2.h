#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�жϴ�С��
//���淽����
void test2_1(){
	int i = 1;
	if (*(char*)&i == 1){
		printf("С��...");
	}
	else{
		printf("���...");
	}
}

//����������
int check_sys(){
	union Un{
		char c;
		int i;
	}un;
	un.i = 1;
	return un.c;
}

void test2_2(){
	int ret = check_sys();
	if (ret == 1){
		printf("С��...");
	}
	else{  //����0
		printf("���...");
	}
}