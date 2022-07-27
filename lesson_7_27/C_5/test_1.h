#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//malloc
void test1_1(){
	int num = 0;
	scanf("%d", &num);
	//int array[num] = { 0 };  
	//这种情况下num必须为常量

	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (ptr != NULL){ //动态开辟空间成功
		for (int i = 0; i < num; i++){
			*(ptr + i) = 2;
		}
	}
	for (int i = 0; i < num; i++){
		printf("%d ", *(ptr + i));
	}
	free(ptr);
	ptr = NULL;
}

//calloc
void test1_2(){
	int num = 10;
	int* ptr = (int*)calloc(num, sizeof(int));
	if (ptr != NULL){
		for (int i = 0; i < num; i++){
			*(ptr + i) = 2;
		}
		for (int i = 0; i < num; i++){
			printf("%d ", *(ptr + i));
		}
	}
	free(ptr);
	ptr = NULL;
}

//realloc
void test1_3(){
	int* ptr = (int*)malloc(100);
	printf("%p\n", ptr);

	//realloc开空间会存在原空间不足的情况
	int* p = NULL;
	p = (int*)realloc(ptr, 1000);
	if (p != NULL){
		ptr = p;
	}
	printf("%p\n", ptr);
	free(ptr);
	ptr = NULL;
}