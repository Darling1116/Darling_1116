#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void GetMemory(char *p) {  
//	p = (char *)malloc(100);  //内存泄漏，没有free
//}

//void test2_1(){
//	char* str = NULL;
//	GetMemory(str);  //p是str的一份临时拷贝
//	strcpy(str, "hello world...");  //对空指针进行解引用，程序崩溃
//	printf(str);
//}

//解决方法：传指针的地址
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



//返回栈空间地址的问题
//char* GetMemory() {
//	char p[] = "hello world";  //出了作用域，函数销毁，栈帧释放
//	return p;
//}

//解决方法：使用静态变量
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