#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��������1: �����ڴ��ͷ�
typedef struct st_type{
	int i;
	int a[0]; //���������Ա
}type_a1;

void test3_1(){
	int i = 0;
	//���������鿪��Ԥ���Ŀռ�
	type_a1 *p = (type_a1*)malloc(sizeof(type_a1)+100 * sizeof(int));

	p->i = 100;
	for (i = 0; i < 100; i++){
		p->a[i] = i;
		printf("%d ", p->a[i]);
	}
	free(p);
}


//��������2: �����ڷ����ٶ�
typedef struct st{
	int i;
	int *array; //���������Ա
}type_a2;

void test3_2(){
	type_a2* p = (type_a2*)malloc(sizeof(type_a2));
	p->i = 100;

	//�ȸ��ṹ���ռ䣬�ٶ�̬������������Ŀռ�
	p->array = (int*)malloc(sizeof(int)*p->i);
	for (int i = 0; i < p->i; i++){
		p->array[i] = i;
		printf("%d ", p->array[i]);
	}
	//���ͷ���������Ŀռ䣬���ͷŽṹ��Ŀռ�
	free(p->array);
	p->array = NULL;
	free(p);
	p = NULL;
}