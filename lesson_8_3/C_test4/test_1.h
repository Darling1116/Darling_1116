#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.字符串左旋，ABCD左旋一个字符编程BCDA
//方法1：每次左旋一个字符
void test1_1(){
	char arr[] = "ABCDEF";
	int len = strlen(arr);
	int k = 2;
	while (k>0){
		int tmp = arr[0];
		for (int i = 1; i < len; i++){
			arr[i - 1] = arr[i];
		}
		arr[len - 1] = tmp;
		k--;
	}

	for (int i = 0; i < len; i++){
		printf("%c ", arr[i]);
	}
}

//方法2：利用字符串逆序，先左边逆序，再右边逆序，最后整体逆序

void reverse(char* left, char* right){
	while (left < right){
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void test1_2(){
	char arr[] = "ABCDEF";
	int len = strlen(arr);
	int k = 2;
	reverse(arr, arr + k - 1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);
	for (int i = 0; i < len; i++){
		printf("%c ", arr[i]);
	}
}

//2.杨氏矩阵:
//每一行都按照从左到右递增的顺序排序
//每一列都按照从上到下递增的顺序排序
void test1_3(){
	int arr[3][3] = { 1, 3, 4, 2, 4, 5, 4, 5, 6 };
	int i = 0;
	int j = 2;
	int x = 5;
	while (i <= 2 && j >= 0){
		if (x > arr[i][j]){
			//往下一行寻找
			i++;
		}
		else if (x < arr[i][j]){
			//往上一列寻找
			j--;
		}
		else{
			printf("找到了...\n");
			break;
		}
	}
}


//3.字符串旋转结果：判断一个字符串是否是另一个字符串旋转的结果
//方法1：每次左旋一个字符，然后进行比较
void test1_4(){
	char arr1[] = "ABCEDF";
	char arr2[] = "EDFABC";
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		printf("不匹配...\n");

	int k = len1;
	while (k){
		int tmp = arr1[0];
		for (int i = 1; i < len1; i++){
			arr1[i - 1] = arr1[i];
		}
		if (strcmp(arr1, arr2) == 1){
			printf("找到了...\n");
			break;
		}
		else{
			k--;
		}
	}
	if (k==0)
		printf("不匹配...\n");

}


//方法2：在要左旋的字符串后面追加该字符串，然后在该字符串中查找子串
int is_left_move(char* arr1, char* arr2){
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2){
		printf("不匹配...\n");
		return 0;
	}

	//strncat：字符串拼接
	strncat(arr1, arr1, sizeof(arr1));

	//查找子串
	char* ret = strstr(arr1, arr2);
	if (ret != NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void test1_5(){
	char arr1[20] = "ABCEDF";
	char arr2[20] = "EDFABC";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1){
		printf("找到了...\n");
	}
	else{
		printf("不匹配...\n");
	}
}