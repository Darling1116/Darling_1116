#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void GetMemory(char *p) {  
//	p = (char *)malloc(100);  //�ڴ�й©��û��free
//}

//void test2_1(){
//	char* str = NULL;
//	GetMemory(str);  //p��str��һ����ʱ����
//	strcpy(str, "hello world...");  //�Կ�ָ����н����ã��������
//	printf(str);
//}

//�����������ָ��ĵ�ַ
void GetMemory2(char **p, int num) {
	*p = (char*)malloc(num);
}
void test2_2() {
	char* str = NULL;
	GetMemory2(&str, 100);
	strcpy(str, "hello");
	printf(str);
	free(str);
	str = NULL;
}



//����ջ�ռ��ַ������
//char* GetMemory() {
//	char p[] = "hello world";  //���������򣬺������٣�ջ֡�ͷ�
//	return p;
//}

//���������ʹ�þ�̬����
char* GetMemory(){
	static char p[] = "hello world";
	//char p = "hello world";
	return p;
}
void test2_3(void) {
	char *str = NULL;  
	str = GetMemory();  
	printf(str);
}



void test2_4(){
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	printf(str);
	free(str);
	str = NULL;
	if (str != NULL){  
		strcpy(str, "world");
		printf(str);
	}
	
}