#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


size_t strlen(const char* str){
	const char* p = str;
	size_t len = 0;
	while (*p != '\0'){
		len++;
		p++;
	}
	return len;
}

void test1_1(){
	char* str = "abhdjodo";
	printf("%d\n", strlen(str));

	const char* str1 = "abcdef";
	const char* str2 = "bbb";
	//printf("%d\n", strlen(str1));
	//printf("%d\n", strlen(str2));
	if (strlen(str1) - strlen(str2) > 0){
		printf("str1 > str2\n");
	}
	else{
		printf("srt1 < str2\n");
	}
}


//char* strcpy(char* dest, const char* source){
//	while (*source != '\0'){
//		*(dest++) = *(source++);
//	}
//	*dest = *source;  //把\0也包含copy过来
//	return dest;
//}

//优化
char* strcpy(char* dest, const char* source){
	assert(dest != source);
	while (*(dest++) = *(source++)){
	}
	return dest;
}

void test1_2(){
	const char* source = "abcdef";
	char dest[100] = { 0 };
	strcpy(dest, source);
	printf("%s\n", dest);
}


//字符串拼接
char* strcat(char* dest, const char* source){
	assert(dest != source);
	while (*dest != '\0'){
		++dest;
	}
	//先找到当前字符串的尾部
	while (*(dest++) = *(source++)){
	}
	return dest;
}

void test1_3(){
	const char* s1 = "my";
	const char* s2 = "favorite";
	const char* s3 = "fruit";
	char dest[100] = { 0 };
	strcat(dest, s1);
	strcat(dest, s2);
	strcat(dest, s3);
	printf("%s\n", dest);
}


int strcmp(const char* str1, const char* str2){
	while ((*str1 == *str2) && *str1 != '\0'){
		str1++;
		str2++;
	}

	if (*str1 > *str2){
		return 1;
	}
	else if (*str1 < *str2){
		return -1;
	}
	else
		return 0;
}

void test1_4(){
	const char* str1 = "abd";
	const char* str2 = "abc";
	int ret = strcmp(str1, str2);
	printf("%d\n", ret);
	//printf("%d\n", sizeof(str1));
}


char* strncpy(char* dest, const char* source, size_t num){
	assert(dest);
	assert(source);
	while (num){
		*(dest++) = *(source++);
		num--;
	}
	return dest;
}

void test1_5(){
	char str[] = "to be number one";
	char dest1[20] = { 0 };
	char dest2[20] = { 0 };
	strncpy(dest1, str, 5);
	strncpy(dest2, str, sizeof(str));
	printf("%s\n", dest1);
	printf("%s\n", dest2);
	//printf("%d\n", sizeof(str));
}


int strncmp(const char* str1, const char* str2, size_t num){
	assert(str1 && str2);
	//这里使用前置--
	while ((*(str1) == *(str2)) && (*str1 != '\0') && --num){
		str1++;
		str2++;
	}
	if (*str1 > *str2){
		return 1;
	}
	else if (*str1 < *str2){
		return -1;
	}
	else
		return 0;
}

void test1_6(){
	const char* str1 = "abcde";
	const char* str2 = "abcdf";
	int ret1 = strncmp(str1, str2, 4);
	int ret2 = strncmp(str1, str2, 5);
	printf("ret1: %d, ret2: %d\n", ret1, ret2);
}