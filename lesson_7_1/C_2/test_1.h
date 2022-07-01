#pragma once
#include "common.h"

//判断大小端
int check_sys(){
	int i = 1;
	return (*(char *)&i);
}

int check_sys2(){
	union{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}

void test_1(){
	int ret = check_sys2();
	if (ret == 1){
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}
}

void test_2(){
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);

	char a1 = -128;
	printf("%u\n", a1);

	char a2 = 128;
	printf("%u\n", a2);
}