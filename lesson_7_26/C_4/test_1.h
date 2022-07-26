#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//结构体的自引用
struct Node{
	int data;
	struct Node* next;
};

typedef struct Node1{
	int data;
	struct Node1* next;
}Node1;

void test1_1(){
	printf("%d ", sizeof(Node));
	printf("%d ", sizeof(Node1));
}

//结构体内存肚对齐
struct S1{
	char c1;
	int i;
	char c2;
};

struct S2{
	char c1;
	char c2;
	int i;
};

struct S3{
	double d;
	char c;
	int i;
};

struct S4{
	char c1;
	struct S3 s3;
	double d;
};
void test1_2(){
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	printf("%d\n", sizeof(struct S3));
	printf("%d\n", sizeof(struct S4));

	//offsetof函数：计算结构体成员相对于起始位置的偏移量
	printf("%u\n", offsetof(S1, c1));
	printf("%u\n", offsetof(S1, i));
	printf("%u\n", offsetof(S1, c2));
}

//位段
struct A{
	int _a : 2;  //2表示_a占了几个位数
	int _b : 5;
	int _c : 10;
	int _d : 30;
};
void test1_3(){
	printf("%d\n", sizeof(struct A));
}

//联合体:成员共用一块内存空间
union Un{
	//char c;
	int i;
	char c;
};

union Un1{
	char c[5];
	int i;
};

union Un2{
	short c[7];
	int i;
};


void test1_4(){
	union Un un;
	//printf("%d\n", sizeof(un));
	//printf("%d\n",&(un.c));
	//printf("%d\n", &(un.i));

	//un.i = 0x11223344;
	//un.c = 0x55;
	//printf("%x\n", un.i);

	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
}