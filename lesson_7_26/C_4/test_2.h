#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//判断大小端
//常规方法：
void test2_1(){
	int i = 1;
	if (*(char*)&i == 1){
		printf("小端...");
	}
	else{
		printf("大端...");
	}
}

//利用联合体
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
		printf("小端...");
	}
	else{  //返回0
		printf("大端...");
	}
}