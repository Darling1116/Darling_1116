#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.�ַ���������ABCD����һ���ַ����BCDA
//����1��ÿ������һ���ַ�
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

//����2�������ַ�������������������ұ����������������

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

//2.���Ͼ���:
//ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳������
void test1_3(){
	int arr[3][3] = { 1, 3, 4, 2, 4, 5, 4, 5, 6 };
	int i = 0;
	int j = 2;
	int x = 5;
	while (i <= 2 && j >= 0){
		if (x > arr[i][j]){
			//����һ��Ѱ��
			i++;
		}
		else if (x < arr[i][j]){
			//����һ��Ѱ��
			j--;
		}
		else{
			printf("�ҵ���...\n");
			break;
		}
	}
}


//3.�ַ�����ת������ж�һ���ַ����Ƿ�����һ���ַ�����ת�Ľ��
//����1��ÿ������һ���ַ���Ȼ����бȽ�
void test1_4(){
	char arr1[] = "ABCEDF";
	char arr2[] = "EDFABC";
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		printf("��ƥ��...\n");

	int k = len1;
	while (k){
		int tmp = arr1[0];
		for (int i = 1; i < len1; i++){
			arr1[i - 1] = arr1[i];
		}
		if (strcmp(arr1, arr2) == 1){
			printf("�ҵ���...\n");
			break;
		}
		else{
			k--;
		}
	}
	if (k==0)
		printf("��ƥ��...\n");

}


//����2����Ҫ�������ַ�������׷�Ӹ��ַ�����Ȼ���ڸ��ַ����в����Ӵ�
int is_left_move(char* arr1, char* arr2){
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2){
		printf("��ƥ��...\n");
		return 0;
	}

	//strncat���ַ���ƴ��
	strncat(arr1, arr1, sizeof(arr1));

	//�����Ӵ�
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
		printf("�ҵ���...\n");
	}
	else{
		printf("��ƥ��...\n");
	}
}