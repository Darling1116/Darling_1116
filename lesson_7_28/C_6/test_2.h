#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

//判断文本文件的读取是否结束
void test2_1(){
	char c;
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL){
		perror("File opening failed...");
		return;
	}

	while ((c = fgetc(pf)) != EOF){
		putchar(c);
	}
	if (ferror(pf))
		puts("I/O error when reading...");
	else if (feof(pf))
		puts("End of file reached successful...");
	fclose(pf);
}

//判断二进制文件的读取是否结束
void test2_2(){
	double a[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b[SIZE] = { 0.0 };
	size_t ret_code = 0;

	FILE *fp = fopen("test.bin", "wb"); // 必须用二进制模式
	fwrite(a, sizeof(*a), SIZE, fp); // 写 double 的数组
	fclose(fp);

	fp = fopen("test.bin", "rb");
	ret_code = fread(b, sizeof(*b), SIZE, fp); // 读 double 的数组

	if (ret_code == SIZE) {
		puts("Array read successfully, contents: ");
		for (int n = 0; n < SIZE; ++n) 
			printf("%f ", b[n]);
		putchar('\n');
	}
	else { // error handling
		if (feof(fp))
			printf("Error reading test.bin: unexpected end of file\n");
		else if (ferror(fp)) {
			perror("Error reading test.bin");
		}
	}
	fclose(fp);
}