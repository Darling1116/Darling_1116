#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

//�ж��ı��ļ��Ķ�ȡ�Ƿ����
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

//�ж϶������ļ��Ķ�ȡ�Ƿ����
void test2_2(){
	double a[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b[SIZE] = { 0.0 };
	size_t ret_code = 0;

	FILE *fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
	fwrite(a, sizeof(*a), SIZE, fp); // д double ������
	fclose(fp);

	fp = fopen("test.bin", "rb");
	ret_code = fread(b, sizeof(*b), SIZE, fp); // �� double ������

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