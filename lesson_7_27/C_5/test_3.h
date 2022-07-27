#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//柔性数组1: 方便内存释放
typedef struct st_type{
	int i;
	int a[0]; //柔性数组成员
}type_a1;

void test3_1(){
	int i = 0;
	//给柔性数组开出预留的空间
	type_a1 *p = (type_a1*)malloc(sizeof(type_a1)+100 * sizeof(int));

	p->i = 100;
	for (i = 0; i < 100; i++){
		p->a[i] = i;
		printf("%d ", p->a[i]);
	}
	free(p);
}


//柔性数组2: 有利于访问速度
typedef struct st{
	int i;
	int *array; //柔性数组成员
}type_a2;

void test3_2(){
	type_a2* p = (type_a2*)malloc(sizeof(type_a2));
	p->i = 100;

	//先给结构开空间，再动态开辟柔性数组的空间
	p->array = (int*)malloc(sizeof(int)*p->i);
	for (int i = 0; i < p->i; i++){
		p->array[i] = i;
		printf("%d ", p->array[i]);
	}
	//先释放柔性数组的空间，再释放结构体的空间
	free(p->array);
	p->array = NULL;
	free(p);
	p = NULL;
}