#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1_1(){
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);  //写入数据的大小单位为字节数
	fclose(pf);
	pf = NULL;
}

void test1_2(){
	FILE* pf = fopen("test.txt", "w");
	if (pf != NULL){  //文件打开失败返回空指针
		fputs("fopen example", pf);
		fclose(pf);
		pf = NULL;
	}

}